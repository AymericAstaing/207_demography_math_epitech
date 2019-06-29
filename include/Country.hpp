/*
** EPITECH PROJECT, 2018
** 204ducks Math Project
** File description:
** Makefile of 204duck
*/

#include <iostream>
#include <vector>

#ifndef COUNTRY_H_
#define COUNTRY_H_

class Country {
    public:
                                    Country(std::string country, std::string code, std::vector<double> pop);
                                    ~Country();
        std::string                 get_country() { return (this->_country); }
        std::string                 get_code() { return (this->_code); }
        const std::vector<double>   get_population() { return (this->_population); }
        double                      get_pop_mean() { return (this->_pop_mean); }
    private:
        std::string             _country;
        std::string             _code;
        std::vector<double>     _population;
        double                  _pop_mean;
};

#endif
