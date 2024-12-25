#pragma once


#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include <cctype>
class RPN
{
    private:

    public:
    RPN();
    ~RPN();
    RPN(RPN const & copy );
    RPN operator=(RPN const & copy);

    std::stack<int> cal;
    int check_op(std::string ope);

    void calcu_RPN(std::string num);
    

};