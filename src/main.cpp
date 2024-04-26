#ifndef UNIT_TESTING
// this main function interferes with the catch2 main

#include <filesystem>
#include <iostream>
#include <string>
#include <cstdlib>
#include <set>

#include "utilities.hpp"
#include "InputDataHandler.hpp"

auto main(int argc, char** argv) -> int
{
    std::cout << "Main Program Started\n";

    const std::string usage{"main <path_to_data_dir>"};
    const int required_num_args = 1;
    const bool in_arg_check = argc_checker(argc, usage, required_num_args);
    if (!in_arg_check){
        return EXIT_FAILURE;
    }

    const std::string input_data_dir{argv[1]};
    const bool dir_exists = dir_checker(input_data_dir);
    if (!dir_exists){
        return EXIT_FAILURE;
    }

    
    InputDataHandler input_data_handler(input_data_dir);
    const auto filenames = input_data_handler.get_filenames();
    std::cout << "filenames:\n";
    for (const auto& filename : filenames)
    {
        std::cout << filename << "\n";
    }
    const int rows = input_data_handler.get_num_rows();
    const int cols = input_data_handler.get_num_cols();
    std::cout << "the data files have:\n"; 
    std::cout << "\t" << rows << " rows and\n";
    std::cout << "\t" << cols << " cols.\n";


    cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
    std::cout << "the matrix has a size (width x height) of:\n"; 
    std::cout << "\t" << diffraction_pattern.size() << "\n";
    
    std::cout << "Program Finished.\n";
    return 0;
}

#endif //UNIT_TESTING