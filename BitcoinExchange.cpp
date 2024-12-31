#include"BitcoinExchange.hpp"


btc::btc()
{

}
btc::~btc()
{

}
void btc::read_file()
{
    std::ifstream file1 , file2;
    file1.open("input.txt");
    file2.open("data.csv");
    if (!file1.is_open() || !file2.is_open()) 
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string d_line;
    std::getline(file2,d_line);
    while(std::getline(file2,d_line))
    {
        size_t j = d_line.find(",");
        std::string d_key = d_line.substr(0,j);
        std::string d_value = d_line.substr(j + 1);
        double valuee = std::stod(d_value);

        _btc[d_key] = valuee;
    }
    std::string f_line;
    std::getline(file1, f_line);
    while(std::getline(file1, f_line))
    {
        size_t i = f_line.find("|");
        std::string key = f_line.substr(0, i);
        std::istringstream istr(key);
        std::string s_key;

        istr >> s_key;
        if (!check_date(s_key))
        {
            std::cerr << "Erreur f date " << key << std::endl;
            continue;
        }
        std::string value_str = f_line.substr(i + 1);
        std::istringstream istrv(value_str);
        std::string value_istr;
        istrv >> value_istr;
        double value = std::stod(value_istr);
        if(!check_value(value))
        {
            std::cerr << "erreur : ya ima srare man 0 ya kbar man 1000 -> " << value_istr << std::endl;
        }
        std::map<std::string , double>::iterator it =  _btc.upper_bound(s_key);

        std::cout << s_key << "->" << it->second * value << std::endl;
    }
    file1.close();
    file2.close();
    //std::map<std::string, double>::iterator it = _btc.begin();
    // for (; it != _btc.end(); ++it) 
    // {
    //     std::cout << it->first << " -> " << it->second << std::endl;
    // }
}
bool btc::check_value(double value)
{
    if(value <  0 || value > 1000)
        return false;
    return true;
}
bool btc::check_date(std::string date)
{
    for(int i = 0; i < date.size() ;i++)
    {
        if(i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return false;
    }
    if(date.size() != 10)
    {
        return false;
    }
    if(date[4] != '-' || date[7] != '-')
    {
        return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12) 
    {
        return false;
    }
    int days_in_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && year % 4!= 0 && day == 29) 
    {
        std::cout << "bad date" << std::endl;
    }
    if (day < 1 || day > days_in_month[month - 1]) 
    {
        return false;
    }
    return true;
}
