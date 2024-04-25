#include <iostream>
#include <filesystem>
#include <string_view>

#include "utilities.hpp"

auto argc_checker(
    const int argc,
    const std::string_view usage,
    const int req_num_args
) -> bool
{
    // the program name is added to the argument count
    const int extra_name_arg = 1;
    const int total_arg_count = req_num_args + extra_name_arg;

    bool retval{true};
    if (argc != total_arg_count)
    {
        retval = false;
        const std::string_view plural{req_num_args > 1 ? "s" : ""};
        std::cerr << "ERROR: " << req_num_args << " input argument" << plural
            << " required\n"
            << "USAGE: " << usage << "\n";
    }
    return retval;
}

auto dir_checker(const std::string_view dir_path) -> bool
{
    const bool retval{std::filesystem::is_directory(dir_path)};
    if (!retval)
    {
        std::cerr << "ERROR: " << dir_path << " is not a directory." << "\n";
    }
    return retval;

}