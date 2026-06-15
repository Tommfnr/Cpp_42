#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "--- test du sujet (MutantStack) ---\n";
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top:  " << mstack.top()  << " (expected: 17)\n";
        mstack.pop();
        std::cout << "size: " << mstack.size() << " (expected: 1)\n";
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "iteration: ";
        MutantStack<int>::iterator it  = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << '\n';

        std::stack<int> s(mstack);
        std::cout << "copy to std::stack size: " << s.size() << '\n';
    }

    std::cout << "\n--- meme test avec std::list (doit donner le meme output) ---\n";
    {
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << "top:  " << mlist.back()  << " (expected: 17)\n";
        mlist.pop_back();
        std::cout << "size: " << mlist.size() << " (expected: 1)\n";
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);

        std::cout << "iteration: ";
        std::list<int>::iterator it  = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << '\n';
    }

    std::cout << "\n--- const_iterator ---\n";
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        const MutantStack<int> cmstack(mstack);
        MutantStack<int>::const_iterator it  = cmstack.begin();
        MutantStack<int>::const_iterator ite = cmstack.end();
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << '\n';
    }

    return 0;
}
