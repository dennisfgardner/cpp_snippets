#include <filesystem>
#include <iostream>
#include <string>
#include <cstdlib>
#include <set>

#include <opencv2/opencv.hpp>


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

    // get number or rows and cols
    const std::string single_file = *filenames.begin();
    std::pair<int, int> rows_cols = get_csv_rows_and_cols(input_data_dir + single_file);
    std::cout << rows_cols.first << ", " << rows_cols.second << "\n";

    // parse all the filenames
    std::vector<filenameInfo> file_infos;
    file_infos.reserve(filenames.size());
    for (const auto& filename : filenames)
    {
        file_infos.push_back(parse_filename(filename));
    }

    //  read a image
    cv::Mat img = read_csv_img_data(input_data_dir + single_file, rows_cols.first, rows_cols.second);
    cv::imwrite("img.png", img);
    double minV{};
    double maxV{};
    cv::minMaxLoc(img, &minV, &maxV);
    std::cout << "min " << minV << "max " << maxV << std::endl;


    InputDataHandler input_data_handler(input_data_dir);
    cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
    std::cout << "the matrix has a size (width x height) of:\n"; 
    std::cout << "\t" << diffraction_pattern.size() << "\n";
    
    std::cout << "Program Finished.\n";
    return 0;
}
