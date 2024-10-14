/* blabla */

#include "err_hdl.h"
#include <iostream>

int no_of_errors;

double error(const char* stirng)
{
    std::cerr << "error: " << stirng << std::endl;
    no_of_errors++;
    return 1;
}