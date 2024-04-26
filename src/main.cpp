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

    std::set<std::string> filenames = get_dir_filenames(input_data_dir, ".csv");
    std::cout << "filenames:\n";
    for (const auto& filename : filenames)
    {
        std::cout << filename << "\n";
    }

    std::string single_file = *filenames.begin();
    std::pair<size_t, size_t> rows_cols = get_csv_rows_and_cols(input_data_dir + single_file);

    std::cout << "there are " << rows_cols.first << " rows in this file\n";
    std::cout << "there are " << rows_cols.second << " cols in this file\n";

    std::cout << "Program Finished.\n";
    return 0;
}

#endif //UNIT_TESTING