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

    // check number of arguments
    const std::string usage{"main <path_to_data_dir>"};
    const int required_num_args = 1;
    const bool in_arg_check = argc_checker(argc, usage, required_num_args);
    if (!in_arg_check){
        return EXIT_FAILURE;
    }

    // check input directory exists
    const std::string input_data_dir{argv[1]};
    const bool dir_exists = dir_checker(input_data_dir);
    if (!dir_exists){
        return EXIT_FAILURE;
    }

    // get all filenames
    std::set<std::string> filenames = get_dir_filenames(input_data_dir, ".csv");
    std::cout << "filenames:\n";
    for (const auto& filename : filenames)
    {
        std::cout << "\t" << filename << "\n";
    }

    // parse the filenames
    for (const auto& filename : filenames)
    {
        filenameInfo filename_info = parse_filename(filename);
        std::cout << filename << "\n";
        std::cout << "\tprefix: " << filename_info.prefix << "\n";
        std::cout << "\tscan number: " << filename_info.scan_num << "\n";
        std::cout << "\tx position: " << filename_info.x_pos << "\n";
        std::cout << "\ty position: " << filename_info.y_pos << "\n";
        std::cout << "\texposure time: " << filename_info.exposure << "\n";
        std::cout << "\tframe number: " << filename_info.frame_num << "\n";
    }


    // get number or rows and cols
    const std::string single_file = *filenames.begin();
    std::pair<int, int> rows_cols = get_csv_rows_and_cols(input_data_dir + single_file);
    std::cout << "the data files have:\n"; 
    std::cout << "\t" << rows_cols.first << " rows and\n";
    std::cout << "\t" << rows_cols.second << " cols.\n";

    InputDataHandler input_data_handler(input_data_dir);
    cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
    std::cout << "the matrix has a size (width x height) of:\n"; 
    std::cout << "\t" << diffraction_pattern.size() << "\n";
    
    std::cout << "Program Finished.\n";
    return 0;
}
