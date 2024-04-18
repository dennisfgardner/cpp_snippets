#include <iostream>
#include <string>

#include "utilities.hpp"


auto arg_count_checker(const int argc, const int req_num_args) -> bool
{
    // the program name is added to the argument count
    const int extra_name_arg = 1;

    bool retval{false};
    if (argc != (req_num_args + extra_name_arg))
    {
        const std::string plural = (req_num_args > 1 ? "s" : "");
        std::cerr << "ERROR: " << req_num_args << " input argument" << plural
            << " required" << std::endl;
    } else
    {
        retval = true;
    }
    return retval;
}