#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <stdexcept>

class PmergeMe
{
    private:
        std::vector<int> _input;
        std::vector<int> _vec;
        std::deque<int>  _deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parse(int ac, char **av);
        void sort();
};

#endif
