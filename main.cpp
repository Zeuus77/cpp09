#include"BitcoinExchange.hpp"


// void btc::read_file()
// {
//     std::ifstream file;
//     file.open("data.csv");
//     if (!file.is_open()) 
//     {
//         std::cerr << "Error opening file!" << std::endl;
//         return;
//     }
//     std::string f_line;
//     std::getline(file, f_line);
//     while(std::getline(file, f_line))
//     {
//         int i = f_line.find(",");
//         std::string key = f_line.substr(0, i);
//         std::string value = f_line.substr(i + 1);
//         std::cout << key << "--" << value << std::endl;
//     }
// }
int main(int ac , char ** av)
{
    btc a;
    if(ac > 1)
    {
        a.read_file();
    }
    else
    {
        std::cout << "Erreur" << std::endl;
    }
}