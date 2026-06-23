#pragma once

#include <stack>
#include <string>

enum Type
{
    Number,
    Operator,
    OtherElement
};

class RPN
{
    private:
        std::stack<int> _st;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int proceed(const std::string& expr);
        Type getType(const char c);

};
