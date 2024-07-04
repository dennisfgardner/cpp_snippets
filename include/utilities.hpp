#ifndef UTILITIES_CPP_SNIPPETS_HEADER
#define UTILITIES_CPP_SNIPPETS_HEADER

#include <string>
#include <utility>
#include <set>

#include <opencv2/opencv.hpp>


/** @fn
 * @brief check number of input arguments
 *
 * Make sure the number of input args is correct. The required number of
 * input args does not include the main function's name. For example, if your
 * main function requires two arguments, then reg_num_args = 2.
 * 
 * @param argc argument count
 * @param usage how to call the function description
 * @param req_num_args required number of input arguments
 *
 * @return true if number of arg count matches required number else false .
 */
auto argc_checker(
    int argc,
    const std::string &usage,
    int req_num_args
) -> bool;


/** @fn
 * @brief check if directory exists
 * 
 * @param dir_path directory path
 *
 * @return true if directory exists else false.
 */
auto dir_checker(
    const std::string &dir_path
) -> bool;


/** @fn
 * @brief Get filenames with extension
 * 
 * Get all the filenames in the directory, excluding subdirectories,
 * with the given extension (include the period). For example, if looking for
 * comma separated values (csv) files, then ext=".csv".
 * 
 * @param dir_path directory path
 * @param ext file extension with the preceding period
 *
 * @return filenames in the directory with specified directory
 */
auto get_dir_filenames(
    const std::string &dir_path,
    const std::string &ext
) -> std::set<std::string>;


/** @struct filenameInfo
 *  @brief information about the scan obtained from filename
 *  @var filenameInfo::prefix
 *  Member 'prefix' contains a short description of the scan, e.g., data or bkg
 *  @var filenameInfo::scan_num
 *  Member 'scan_num' is the scan number, zero based index
 *  @var filenameInfo::x_pos
 *  Member 'x_pos' is the x-stage scan position
 *  @var filenameInfo::y_pos
 *  Member 'y_pos' is the y-stage scan position
 *  @var filenameInfo::exposure
 *  Member 'exposure' is the exposure time of the focal plane array
 *  @var filenameInfo::frame_num
 *  Member 'frame_num' is the frame number for a particular exposure, zero based indexing.
 */
struct filenameInfo
{
    std::string prefix{};
    int scan_num{};
    double x_pos{};
    double y_pos{};
    double exposure{};
    int frame_num{};

    bool operator==(const filenameInfo& rhs) const
    {
        return (frame_num == rhs.frame_num)
        && (exposure == rhs.exposure)
        && (x_pos == rhs.x_pos)
        && (y_pos == rhs.y_pos)
        && (scan_num == rhs.scan_num)
        && (prefix == rhs.prefix);
    }
    bool operator!=(const filenameInfo& rhs) const
    {
        return !operator==(rhs);
    }
};


/** @fn
 * @brief parse filename
 * 
 * Extract scan data information from the filename.
 * 
 * @param dir_path filename
 *
 * @return filename information
 */
auto parse_filename(const std::string &filename) -> filenameInfo;


/** @fn
 * @brief Get CSV number of rows and cols
 * 
 * Get comma separated values (csv) file's number of rows and columns.
 * 
 * @param csv_file csv filepath path
 * @param ext file extension with the preceding period
 *
 * @return filenames in the directory with specified directory
 */
auto get_csv_rows_and_cols(const std::string &csv_file) -> std::pair<int, int>;


/** @fn
 * @brief Read the csv image data
 * 
 * Read the image data from a csv file.
 * 
 * @param csv_file csv filepath path
 * @param rows number of rows of data
 * @param cols number of cols of data
 *
 * @return image data
 */
auto read_csv_img_data(const std::string &csv_file, int rows, int cols) -> cv::Mat;

#endif