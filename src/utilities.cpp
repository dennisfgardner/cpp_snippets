#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "utilities.hpp"

auto argc_checker(
    const int argc,
    const std::string &usage,
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
        const std::string plural{req_num_args > 1 ? "s" : ""};
        std::cerr << "ERROR: " << req_num_args << " input argument" << plural
            << " required\n"
            << "USAGE: " << usage << "\n";
    }
    return retval;
}

auto dir_checker(const std::string &dir_path) -> bool
{
    const bool retval{std::filesystem::is_directory(dir_path)};
    if (!retval)
    {
        std::cerr << "ERROR: " << dir_path << " is not a directory." << "\n";
    }
    return retval;

}

auto get_dir_filenames(
    const std::string &dir_path,
    const std::string &ext
) -> std::set<std::string>
{
    std::set<std::string> filenames;
    if (std::filesystem::is_directory(dir_path))
    {
        for (const auto &element : std::filesystem::directory_iterator(dir_path))
        {
            if (element.is_regular_file())
            {
                if (element.path().extension() == ext)
                {
                    filenames.insert(element.path().filename().string());
                }
            }
        }
    }
    return filenames;
}


auto get_csv_rows_and_cols(const std::string &csv_file) -> std::pair<int, int>
{
    std::pair<int, int> retval{0, 0};
    
    std::ifstream input(csv_file, std::ifstream::in);
    if (!input)
    {
        std::cerr << "ERROR: Cannot read csv file " << csv_file << "\n";
    } else {
        std::string line_content{};
        int rows{0};
        while (input >> line_content)
        {
            ++rows;
        }
        std::stringstream line(line_content);
        std::string col_content{};
        int cols{0};
        while (std::getline(line, col_content, ','))
        {
            ++cols;
        }
        retval.first = rows;
        retval.second = cols;
    }
    return retval;
}
