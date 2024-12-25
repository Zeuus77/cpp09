#include"RPN.hpp"


int main(int ac , char **av)
{
   RPN a;
    if (ac > 1) 
    {
        a.calcu_RPN(av[1]);
    } 
    else 
    {
        std::cerr << "Error: No expression provided!" << std::endl;
    }
}   