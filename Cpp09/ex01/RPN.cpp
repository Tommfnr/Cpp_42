#include "RPN.hpp"
#include <iostream>
#include <climits>

static int checked(long long r) {
    if (r > INT_MAX || r < INT_MIN)
        throw std::runtime_error("Error: overflow");
    return static_cast<int>(r);
}

RPN::RPN() {};

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other){
        this->_st = other._st;
    }
    return (*this);
}

RPN::~RPN() {};

Type RPN::getType(const char c) {
    if (isdigit(c))
        return Number;
    else if (c == '+' || c == '-' || c == '/' || c == '*')
        return Operator;
    return OtherElement;
}


int RPN::proceed(const std::string& expr) {
    int res = 0;
    for (size_t i = 0; i < expr.size(); i++)
    {
        switch (getType(expr[i]))
        {
        case Number:
            _st.push(expr[i] - '0');
            break;

        case Operator: {
            if (_st.size() < 2)
                throw std::runtime_error("Error");
            int b = _st.top(); _st.pop();
            int a = _st.top(); _st.pop();
            if (expr[i] == '+') _st.push(checked((long long)a + b));
            else if (expr[i] == '-') _st.push(checked((long long)a - b));
            else if (expr[i] == '*') _st.push(checked((long long)a * b));
            else if (expr[i] == '/')
            {
                if (b == 0) throw std::runtime_error("Error: division by zero");
                _st.push(checked((long long)a / b));
            }
            break;
        }

        case OtherElement:
            if (expr[i] == ' ')
                break;
            throw std::runtime_error("Error: wrong element");
        }
    }
    if (_st.size() != 1)
        throw std::runtime_error("Error");
    res = _st.top();
    std::cout << res << std::endl;
    return res;
}
