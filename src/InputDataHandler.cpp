#include <set>
#include <string>

#include <opencv2/core.hpp>

#include "InputDataHandler.hpp"
#include "utilities.hpp"

auto InputDataHandler::get_diffraction_pattern() -> cv::Mat
{

    std::set<std::string> data_filenames = get_dir_filenames(data_dir, data_file_extension);

    // TODO get the number of rows and cols

    cv::Mat diffraction_pattern;
    return diffraction_pattern;
}
