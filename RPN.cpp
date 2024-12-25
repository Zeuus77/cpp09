#include"RPN.hpp"


RPN::RPN()
{

}
RPN::~RPN()
{

}
int RPN::check_op(std::string ope)
{
    if(ope == "+"  || ope == "-" || ope == " *" || ope == "/")
    {
        if(cal.size() < 2)
        {
            std::cerr << "Error operator machi f blasto" << std::endl;
            return(0);
        }

    }
    return 1;
}
void RPN::calcu_RPN(std::string num)
{
    std::istringstream istr(num);
    std::string res;
  
    while(istr >> res)
    {
        
      if (std::isdigit(res[0]) || (res[0] == '-' && res.length() > 1 && std::isdigit(res[1]))) 
        {
            cal.push(std::atoi(res.c_str()));
        }
        else if(check_op(res))
        { 
            if (cal.size() < 2) 
            {
                std::cerr << "Error: Not enough operands for operator \"" << res << "\"" << std::endl;
                return; 
            }
                int num2 = cal.top(); 
                cal.pop();
                int num1 = cal.top(); 
                cal.pop();
                int result;

            if(res == "+")
            {
                result = num1 + num2;
            }
            else if(res == "-")
            {
               result =  num1 - num2;
            }
            else if( res == "*")
            {
               result = num1 * num2;
            }
            else if(res == "/")
            {
                if(num2 == 0)
                {
                    std::cerr << "maymkanche t9same 3la 0" << std::endl;
                    return;
                }
                result = num1 / num2;
            }
            cal.push(result);
        }
        else
        {
            std::cerr << "inpute machi howa " << res << std::endl;
            return;
        }
    }
    if(cal.size() != 1)
    {
        std::cerr << "prblem fl 7sab" << std::endl;
    }
    else
    {
        std::cout << cal.top() << std::endl;
    }
}