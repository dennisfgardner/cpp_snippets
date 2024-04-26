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

auto get_dir_filenames(
    const std::string_view dir_path,
    const std::string_view ext
) -> std::set<std::string>
{
    std::set<std::string> filenames;
    if (std::filesystem::is_directory(dir_path))
    {
        for (const auto &el : std::filesystem::directory_iterator(dir_path))
        {
            if (el.is_regular_file())
            {
                if (el.path().extension() == ext)
                {
                    filenames.insert(el.path().filename().string());
                }
            }
        }
    }
    return filenames;
}