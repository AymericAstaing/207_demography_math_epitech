/*
** EPITECH PROJECT, 2018
** 204ducks Math Project
** File description:
** Makefile of 204duck
*/

#ifndef DEMO_H_
#define DEMO_H_

#include "Country.hpp"      

class Demo {
    public:
                            Demo();
                            ~Demo();
        int                 parse_file();
        void                compute(std::vector<std::string> code);
        std::vector<Country> get_countries() { return (this->country_list); }
    private:
        std::vector<Country> country_list;

};

/********** header zone utils **********/
std::string                 get_file();
double                      mean(std::vector<double> array);
double                      get_correlation(std::vector<double> population,
                            double y0, double y1, double x0, double x1, double rmsd1, double rmsd2);
double                      get_rmsd(std::vector<double> population, double a, double b);
double                      get_rmsd2(std::vector<double> population, double x0, double x1);
double                      sum(std::vector<double> tab);
double                      custom_mean(double min, double max);
int                         fully_numeric(std::string str);
std::vector<double>         get_full_population(std::vector<Country> country_list, std::vector<std::string> code);
Country                     get_country_by_code(std::vector<Country> c_list, std::string code);
std::vector<double>         parse_population(std::vector<std::string> pop);
std::vector<std::string>    split_string(std::string str, std::string delmtr);

#endif
