/*
** EPITECH PROJECT, 2018
** 204ducks Math Project
** File description:
** Makefile of 204duck
*/

#include <iostream>
#include <vector>
#include "DemoVrbles.hpp"
#include "Demo.hpp"
#include "Country.hpp"

Country::Country(std::string country, std::string code, std::vector<double> population)
: _country(country), _code(code), _population(population), _pop_mean(sum(population) / population.size())
{

}

Country::~Country()
{

}