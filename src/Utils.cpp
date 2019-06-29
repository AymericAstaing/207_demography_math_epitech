
#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <math.h>
#include <iomanip>
#include <sstream> 
#include <fstream>
#include "DemoVrbles.hpp"
#include "Country.hpp"

Country get_country_by_code(std::vector<Country> c_list, std::string code)
{
    for (unsigned int i = 0; i < c_list.size(); i++) {
        if (c_list.at(i).get_code() == code)
            return (c_list.at(i));
    }
    return (c_list.at(0));
}

std::string get_file()
{
    std::ifstream t("207demography_data.csv");
     if (!t.is_open())
        return ("");
    std::string str((std::istreambuf_iterator<char>(t)),
    std::istreambuf_iterator<char>());
    return (str);
}

std::vector<double> get_full_population(std::vector<Country> country_list, std::vector<std::string> code)
{
    Country tmp = get_country_by_code(country_list, code.at(0));
    std::vector<double>pop;
    double value = 0;

    unsigned int size = tmp.get_population().size();


    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < code.size(); j++)
            value += get_country_by_code(country_list, code.at(j)).get_population().at(i);
        pop.push_back(value);
        value = 0;
    }
    return (pop);
}

double get_rmsd(std::vector<double> population,
double a, double b)
{
    double Y_b = 0.0;
    double divider = population.size();
    double result = 0.0;
    double t = 0;
    double year = 1960.0;

    for (unsigned int i = 0; i < population.size(); i++, year++) {
        t  =  (a * year) - b;
        Y_b += pow((population.at(i) - t), 2);
    }
    result = sqrt(Y_b / divider);
    return (result);
}

double get_rmsd2(std::vector<double> population, double y1, double x1)
{
    double Y_b = 0.0;
    double divider = population.size();
    double result = 0.0;
    double t = 0;
    double year = 1960.0;

    for (unsigned int i = 0; i < population.size(); i++, year++) {
        t  =  ((-(x1) + year) / y1);
        Y_b += pow(population.at(i) - t, 2);
    }
    result = sqrt(Y_b / divider);
    return (result);
}

double get_correlation(std::vector<double> population,
double y0, double y1, double x0, double x1, double rmsd1, double rmsd2)
{
    double cor = 0;
    double year = 1960.0;
    double divider = population.size();

    for (unsigned int i = 0; i < divider; i++, year++)
        cor += (population.at(i) - (y0 * year + y1)) * (population.at(i) - ((-(x1) + year) / x0));
    cor /= divider;
    return (cor / (rmsd1 * rmsd2));
}

double mean(std::vector<double> array)
{
    double sum = 0;

    for (unsigned int i = 0; i < array.size(); i++)
        sum  += array.at(i);
    return (sum / array.size());
}

double custom_mean(double min, double max)
{
    double sum = 0;
    if (max <= min)
        return (-1);
    for (double i = min; i < max; i++)
        sum += i;
    return (sum / (max - min));
}

double sum(std::vector<double> tab)
{
    return (std::accumulate(tab.begin(), tab.end(), 0));
}

int fully_numeric(std::string str)
{
    for (unsigned int i = 0; i < str.size(); i++)
        if (str.at(i) < 48 || str.at(i) > 57)
            return (FAIL);
    return (SUCC);
}


std::vector<double> parse_population(std::vector<std::string> popu)
{
    std::vector<double>  pop_list;

    for (unsigned int i = 2; i < popu.size(); i++) {
        if (!popu.empty() && (fully_numeric(popu.at(i)) == SUCC))
            pop_list.push_back((double) std::stoul(popu.at(i)) / 1000000.0);
    }
    return (pop_list);
}

std::vector<std::string> split_string(std::string str, std::string delimiter)
{
    std::vector<std::string> spliter;
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        
        token = str.substr(0, pos);
        if (!token.empty())
            spliter.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    spliter.push_back(str);
    return (spliter);
    
}
