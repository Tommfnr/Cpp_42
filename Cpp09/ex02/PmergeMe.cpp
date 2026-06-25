#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _input(other._input), _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _input = other._input;
        _vec   = other._vec;
        _deq   = other._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string token(av[i]);

        if (token.empty())
            throw std::runtime_error("Error: invalid input");

        for (size_t j = 0; j < token.size(); j++)
        {
            if (!isdigit(token[j]))
                throw std::runtime_error("Error: invalid input");
        }

        std::istringstream iss(token);
        long n = 0;
        iss >> n;

        if (iss.fail() || n > INT_MAX)        // débordement int
            throw std::runtime_error("Error: invalid input");
        if (n <= 0)
            throw std::runtime_error("Error: only positive integers allowed");

        _input.push_back(static_cast<int>(n));
    }
}


// ─── Jacobsthal ───────────────────────────────────────────────────────────────

// Génère l'ordre d'insertion : [1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, ...]
static std::vector<size_t> jacobsthalOrder(size_t n)
{
    // Construire la suite jusqu'à dépasser n
    std::vector<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n)
        jac.push_back(jac[jac.size()-1] + 2 * jac[jac.size()-2]);

    // Générer l'ordre d'insertion
    std::vector<size_t> order;
    size_t prev = 0;
    for (size_t k = 1; k < jac.size(); k++)
    {
        size_t from = std::min(jac[k], n); // on ne dépasse pas n
        size_t to   = prev + 1;
        for (size_t i = from; i >= to; i--)  // on descend dans chaque groupe
            order.push_back(i);
        prev = jac[k];
        if (prev >= n) break;
    }
    return order;
}

// Comparateur sur le .first d'une paire (pour lower_bound : paire/paire et paire/int)
struct ByFirst
{
    bool operator()(const std::pair<int,int>& a, const std::pair<int,int>& b) const
    { return a.first < b.first; }
    bool operator()(const std::pair<int,int>& a, int b) const
    { return a.first < b; }
};

// ─── Ford-Johnson vector ──────────────────────────────────────────────────────

// Trie un vecteur de paires par .first (le .second voyage avec, sans jamais être
// comparé). Remplace l'ancienne récursion sur les "grands" + réordonnance O(n²).
static void fjPairsVec(std::vector<std::pair<int,int> >& p)
{
    size_t n = p.size();
    if (n <= 1) return;
    if (n == 2)
    {
        if (p[0].first > p[1].first) std::swap(p[0], p[1]);
        return;
    }

    bool hasStraggler = (n % 2 != 0);
    std::pair<int,int> straggler = hasStraggler ? p[n-1] : std::make_pair(0, 0);

    // Apparier les paires entre elles en comparant leur .first → gagnant/perdant.
    // winnerKey[k] = .first du gagnant : une valeur, donc elle survit au tri récursif.
    std::vector<std::pair<int,int> > winners;
    std::vector<std::pair<int,int> > losers;
    std::vector<int> winnerKey;
    size_t cnt = hasStraggler ? n - 1 : n;
    for (size_t i = 0; i < cnt; i += 2)
    {
        if (p[i].first >= p[i+1].first) { winners.push_back(p[i]);   losers.push_back(p[i+1]); }
        else                            { winners.push_back(p[i+1]); losers.push_back(p[i]);   }
        winnerKey.push_back(winners.back().first);
    }

    fjPairsVec(winners); // trie les gagnants par .first

    std::vector<std::pair<int,int> > chain(winners);

    // perdants (+ straggler) insérés par recherche binaire, ordre de Jacobsthal
    std::vector<std::pair<int,int> > pend(losers);
    std::vector<int> pendKey(winnerKey);
    if (hasStraggler) { pend.push_back(straggler); pendKey.push_back(0); }

    std::vector<size_t> order = jacobsthalOrder(pend.size());
    ByFirst cmp;
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k] - 1;
        std::pair<int,int> val = pend[idx];

        // borne = position du gagnant lié (retrouvé par sa valeur en O(log n))
        std::vector<std::pair<int,int> >::iterator boundIt;
        if (hasStraggler && idx == pend.size() - 1)
            boundIt = chain.end();
        else
            boundIt = std::lower_bound(chain.begin(), chain.end(), pendKey[idx], cmp);

        std::vector<std::pair<int,int> >::iterator pos =
            std::lower_bound(chain.begin(), boundIt, val, cmp);
        chain.insert(pos, val);
    }

    p = chain;
}

void fordJohnsonVec(std::vector<int>& vec)
{
    size_t size = vec.size();

    if (size <= 1) return;
    if (size == 2)
    {
        if (vec[0] > vec[1]) std::swap(vec[0], vec[1]);
        return;
    }

    bool hasStraggler = (size % 2 != 0);
    int  straggler    = hasStraggler ? vec.back() : -1;

    // former les paires (grand, petit)
    std::vector<std::pair<int,int> > pairs;
    size_t pairCount = hasStraggler ? size - 1 : size;
    for (size_t i = 0; i < pairCount; i += 2)
    {
        if (vec[i] >= vec[i+1]) pairs.push_back(std::make_pair(vec[i], vec[i+1]));
        else                    pairs.push_back(std::make_pair(vec[i+1], vec[i]));
    }

    // trier les paires par leur grand (le petit reste attaché → plus de réordonnance)
    fjPairsVec(pairs);

    // chaîne principale : petit du 1er (gratuit, c'est le plus petit) + grands triés
    std::vector<int> chain;
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        chain.push_back(pairs[i].first);

    std::vector<int> smalls;
    for (size_t i = 1; i < pairs.size(); i++)
        smalls.push_back(pairs[i].second);
    if (hasStraggler)
        smalls.push_back(straggler);

    std::vector<size_t> insertOrder = jacobsthalOrder(smalls.size());
    for (size_t k = 0; k < insertOrder.size(); k++)
    {
        size_t idx = insertOrder[k] - 1;
        int    val = smalls[idx];

        // borne droite : position du grand lié (en O(log n) car chain est triée)
        std::vector<int>::iterator boundIt = chain.end();
        if (!hasStraggler || idx < smalls.size() - 1)
        {
            int largeVal = pairs[idx + 1].first;
            boundIt = std::lower_bound(chain.begin(), chain.end(), largeVal);
        }

        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), boundIt, val);
        chain.insert(pos, val);
    }

    vec = chain;
}

// ─── Ford-Johnson deque ───────────────────────────────────────────────────────

static void fjPairsDeq(std::deque<std::pair<int,int> >& p)
{
    size_t n = p.size();
    if (n <= 1) return;
    if (n == 2)
    {
        if (p[0].first > p[1].first) std::swap(p[0], p[1]);
        return;
    }

    bool hasStraggler = (n % 2 != 0);
    std::pair<int,int> straggler = hasStraggler ? p[n-1] : std::make_pair(0, 0);

    std::deque<std::pair<int,int> > winners;
    std::deque<std::pair<int,int> > losers;
    std::deque<int> winnerKey;
    size_t cnt = hasStraggler ? n - 1 : n;
    for (size_t i = 0; i < cnt; i += 2)
    {
        if (p[i].first >= p[i+1].first) { winners.push_back(p[i]);   losers.push_back(p[i+1]); }
        else                            { winners.push_back(p[i+1]); losers.push_back(p[i]);   }
        winnerKey.push_back(winners.back().first);
    }

    fjPairsDeq(winners);

    std::deque<std::pair<int,int> > chain(winners);

    std::deque<std::pair<int,int> > pend(losers);
    std::deque<int> pendKey(winnerKey);
    if (hasStraggler) { pend.push_back(straggler); pendKey.push_back(0); }

    std::vector<size_t> order = jacobsthalOrder(pend.size());
    ByFirst cmp;
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k] - 1;
        std::pair<int,int> val = pend[idx];

        std::deque<std::pair<int,int> >::iterator boundIt;
        if (hasStraggler && idx == pend.size() - 1)
            boundIt = chain.end();
        else
            boundIt = std::lower_bound(chain.begin(), chain.end(), pendKey[idx], cmp);

        std::deque<std::pair<int,int> >::iterator pos =
            std::lower_bound(chain.begin(), boundIt, val, cmp);
        chain.insert(pos, val);
    }

    p = chain;
}

void fordJohnsonDeq(std::deque<int>& deq)
{
    size_t size = deq.size();

    if (size <= 1) return;
    if (size == 2)
    {
        if (deq[0] > deq[1]) std::swap(deq[0], deq[1]);
        return;
    }

    bool hasStraggler = (size % 2 != 0);
    int  straggler    = hasStraggler ? deq.back() : -1;

    std::deque<std::pair<int,int> > pairs;
    size_t pairCount = hasStraggler ? size - 1 : size;
    for (size_t i = 0; i < pairCount; i += 2)
    {
        if (deq[i] >= deq[i+1]) pairs.push_back(std::make_pair(deq[i], deq[i+1]));
        else                    pairs.push_back(std::make_pair(deq[i+1], deq[i]));
    }

    fjPairsDeq(pairs);

    std::deque<int> chain;
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        chain.push_back(pairs[i].first);

    std::deque<int> smalls;
    for (size_t i = 1; i < pairs.size(); i++)
        smalls.push_back(pairs[i].second);
    if (hasStraggler)
        smalls.push_back(straggler);

    std::vector<size_t> insertOrder = jacobsthalOrder(smalls.size());
    for (size_t k = 0; k < insertOrder.size(); k++)
    {
        size_t idx = insertOrder[k] - 1;
        int    val = smalls[idx];

        std::deque<int>::iterator boundIt = chain.end();
        if (!hasStraggler || idx < smalls.size() - 1)
        {
            int largeVal = pairs[idx + 1].first;
            boundIt = std::lower_bound(chain.begin(), chain.end(), largeVal);
        }

        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), boundIt, val);
        chain.insert(pos, val);
    }

    deq = chain;
}

// ─── Sort ─────────────────────────────────────────────────────────────────────

void PmergeMe::sort()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _input.size(); i++)
        std::cout << _input[i] << " ";
    std::cout << std::endl;

    // vector : remplissage (data management) + tri, chronométrés ensemble
    std::clock_t t1 = std::clock();
    _vec.assign(_input.begin(), _input.end());
    fordJohnsonVec(_vec);
    std::clock_t t2 = std::clock();

    // deque : remplissage (data management) + tri, chronométrés ensemble
    std::clock_t t3 = std::clock();
    _deq.assign(_input.begin(), _input.end());
    fordJohnsonDeq(_deq);
    std::clock_t t4 = std::clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double timeVec = (double)(t2 - t1) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = (double)(t4 - t3) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
