#ifndef UNIT_TESTING
// this main function interferes with the catch2 main

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <span>
#include <cstdlib>

#include "utilities.hpp"

auto main(int argc, char** argv) -> int
{
    std::cout << "Main Program Started\n";

    const std::string_view usage{"main <path_to_data_dir>"};
    const int required_num_args = 1;
    const bool in_arg_check = argc_checker(argc, usage, required_num_args);
    if (!in_arg_check){
        return EXIT_FAILURE;
    }

    auto args = std::span(argv, argc);
    const std::string input_data_dir{args[1]};
    const bool dir_exists = dir_checker(input_data_dir);
    if (!dir_exists){
        return EXIT_FAILURE;
    }



    
    if (!std::filesystem::exists(input_data_dir))
    {
        std::cerr << "ERROR: input data dir " << input_data_dir 
            << " does not exist\n";
        return EXIT_FAILURE;
    }

    auto dir_iter = std::filesystem::directory_iterator(input_data_dir);
    std::cout << "directory contents:\n";
    for (const auto& dir_item : dir_iter)
    {
        std::cout << "\t" << dir_item << "\n";
    }

    const std::string filename = 
        "./test/data/bkg000_x_017800_y_014600_ExpTime_us_000100_FrameNum_0000.csv";
    std::ifstream input(filename, std::ifstream::in);
    if (!input)
    {
        std::cerr << "ERROR: Cannot read file " << filename << "\n";
    }
    std::string line_content{};
    std::size_t rows{0};
    while (input >> line_content)
    {
        ++rows;
    }
    std::cout << "there are " << rows << " rows in this file\n";
    
    std::stringstream line(line_content);
    std::string col_content{};
    std::size_t cols{0};
    while (std::getline(line, col_content, ','))
    {
        ++cols;
    }
    std::cout << "there are " << cols << " cols in this file\n";


    std::cout << "Program Finished.\n";
    return 0;
}

#endif //UNIT_TESTING