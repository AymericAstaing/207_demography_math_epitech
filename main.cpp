/*
** EPITECH PROJECT, 2018
** 204ducks Math Project
** File description:
** Makefile of 204duck
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include "DemoVrbles.hpp"
#include "Demo.hpp"

void print_help()
{
    std::ifstream f(HELP_FILE);
    if (f.is_open())
        std::cout << f.rdbuf() << std::endl;
}

int is_help_requiered(char *arg) {
    if (strcmp(HELP_FLAG, arg) != 0)
        return (0);
    print_help();
    return (1);
}

std::vector<std::string> get_code_array(char **argv)
{
    std::vector<std::string> array;

    for (int i = 1; argv[i] != NULL; i++)
        array.push_back(argv[i]);
    return (array);
}

int main(int argc, char **argv)
{
    Demo d = Demo();
    if (argc < 2) {
        print_help();
        return (EXIT_FAIL);
    }
    if (argc == 2 && is_help_requiered(argv[1]))
        return (EXIT_SUCC);
    if (d.parse_file() == FAIL)
        return (FAIL);
    std::vector<std::string> country_code = get_code_array(argv);
    d.compute(country_code);
    return (EXIT_SUCC);
}