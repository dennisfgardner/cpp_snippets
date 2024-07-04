#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <regex>

#include <opencv2/opencv.hpp>

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

auto parse_filename(const std::string &filename) -> filenameInfo
{
    // parts of the filename
    const std::string any_letters = "([^\\d+]+)";
    const std::string any_nums = "([\\d+]+)";
    const std::string reg_exp = 
        any_letters // prefix text
        + any_nums // scan number
        + "(_x_)" + any_nums // x stage position
        + "(_y_)" + any_nums // y stage postion
        + "(_ExpTime_us_)" + any_nums // camera exposure time
        + "(_FrameNum_)" + any_nums // frame number
        + "(.*)";  // anything else
    // match parts of the filename using regular expression
    std::regex rgx(reg_exp);
    std::smatch match;
    std::regex_match(filename, match, rgx);
    // put info into struc
    filenameInfo filename_info;
    filename_info.prefix = match[1];
    filename_info.scan_num = std::stoi(match[2]);
    filename_info.x_pos = std::stod(match[4]);
    filename_info.y_pos = std::stod(match[6]);
    filename_info.exposure = std::stod(match[8]);
    filename_info.frame_num = std::stoi(match[10]);
    return filename_info;
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


auto read_csv_img_data(const std::string &csv_file, int rows, int cols) -> cv::Mat
{
    cv::Mat img(rows, cols, CV_64FC1);

    std::ifstream input(csv_file, std::ifstream::in);
    if (!input)
    {
        std::cerr << "ERROR: Cannot read csv file to get image data " << csv_file << "\n";
    } else {
        int row_cnt{0};
        std::string line_content{};
        while (input >> line_content)
        {
            int col_cnt{0};
            std::stringstream line(line_content);
            std::string col_content{};
            while (std::getline(line, col_content, ','))
            {
                img.at<double>(row_cnt, col_cnt) = std::stod(col_content);
                ++col_cnt;
            }
            ++row_cnt;
        }

    }
    return img;

}