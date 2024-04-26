#ifndef UTILITIES_CPP_SNIPPETS_HEADER
#define UTILITIES_CPP_SNIPPETS_HEADER

#include <string>
#include <vector>


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
    std::string_view usage,
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
    std::string_view dir_path
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
    std::string_view dir_path,
    std::string_view ext
) -> std::vector<std::string>;

#endif