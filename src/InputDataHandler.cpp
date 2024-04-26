#include <set>
#include <string>
#include <utility>

#include <opencv2/opencv.hpp>

#include "InputDataHandler.hpp"
#include "utilities.hpp"


InputDataHandler::InputDataHandler(const std::string &data_directory) :
    data_dir{data_directory},
    data_file_extension{".csv"},
    opencv_datatype{CV_64FC1}
{
    filenames = get_dir_filenames(data_dir, data_file_extension);

    const std::string single_file = *filenames.begin();
    rows_cols = get_csv_rows_and_cols(data_dir + single_file);
};


auto InputDataHandler::get_diffraction_pattern() -> cv::Mat
{

    cv::Mat diffraction_pattern(rows_cols.first, rows_cols.second, opencv_datatype);
    return diffraction_pattern;
}
