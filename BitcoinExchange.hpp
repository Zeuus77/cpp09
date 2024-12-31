#pragma once



#include<iostream>
#include<map>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
class btc
{
    private:

    public:
    btc();
    ~btc();

    std::map<std::string , double> _btc;
    void read_file();
    bool check_date(std::string date);
    bool check_value(double value);
};