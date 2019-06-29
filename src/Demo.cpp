/*
** EPITECH PROJECT, 2018
** 204ducks Math Project
** File description:
** Makefile of 204duck
*/

#include <vector>
#include <iostream>
#include <math.h>
#include "DemoVrbles.hpp"
#include "Demo.hpp"
#include "Country.hpp"

Demo::Demo()
{

}

Demo::~Demo()
{
    
}


void Demo::compute(std::vector<std::string> code)
{
    unsigned int i = 0;
    std::vector<double> full_population = get_full_population(country_list, code);
    std::cout << "Country: ";
    for (; i < code.size() - 1; i++)
        std::cout << get_country_by_code(country_list, code.at(i)).get_country() << ", ";
    std::cout << get_country_by_code(country_list, code.at(i)).get_country() << "\n";
    std::cout << "Fit1\n";
    double X_MEAN = custom_mean(1960, 1960 + full_population.size());
    double Y_MEAN = mean(full_population);
    std::vector<double> square_xlessx_;
    std::vector<double> square_ylessy_;
    std::vector<double> xandy;

    double x_x = 0;
    double y_y = 0;
    double X_b0 = 0;
    double X_b1 = 0;
    double Y_b0 = 0;
    double Y_b1 = 0;
    double rmsd = 0;
    double rmsd2 = 0;

    for (unsigned int i = 0; i < full_population.size(); i++) {
        x_x = (1960 + i) - X_MEAN;
        y_y = full_population.at(i) - Y_MEAN;
        square_xlessx_.push_back(x_x * x_x);
        square_ylessy_.push_back(y_y * y_y);
        xandy.push_back(x_x * y_y);
    }
    Y_b0 = (sum(xandy) / sum(square_xlessx_));
    Y_b1 = (Y_MEAN - (Y_b0 * X_MEAN));
    if (Y_b1 < 0)
        Y_b1 *= -1;
    X_b0 = sum(xandy) / sum(square_ylessy_);
    X_b1 = (X_MEAN - (X_b0 * Y_MEAN));
    printf("    Y = %.2f X - %.2f\n", Y_b0 , Y_b1);
    rmsd = get_rmsd(full_population, Y_b0, Y_b1);
    printf("    Root-mean-square deviation: %.2f\n", rmsd);
    printf("    Population in 2050: %.2f\nFit2\n", Y_b0 * 2050 - Y_b1);
    printf("    X = %.2f Y + %.2f\n", X_b0, X_b1);
    rmsd2 = get_rmsd2(full_population, X_b0, X_b1);
    printf("    Root-mean-square deviation: %.2f\n", rmsd2);
    printf("    Population in 2050: %.2f\n", ((-(X_b1) + 2050) / X_b0));
    printf("Correlation: %.4f\n", get_correlation(full_population, Y_b0, Y_b1, X_b0, X_b1, rmsd, rmsd2));
}

int Demo::parse_file()
{
    std::string file = get_file();
    if (file.empty())
        return (FAIL);
    std::vector<std::string> file_splited = split_string(file, "\n");
    std::vector<std::string> country_line;
    std::vector<double> population_list;
    file_splited.erase(file_splited.begin());

    for (unsigned int i = 0; i < file_splited.size(); i++) {
        if (file_splited.at(i).empty())
            continue;
        country_line = split_string(file_splited.at(i), ";");
        if (country_line.at(0) == "Not classified") // attention
            continue;
        population_list = parse_population(country_line);
        Country c = Country(country_line.at(0), country_line.at(1), population_list);
        country_list.push_back(c);
    }
    return (SUCC);
}