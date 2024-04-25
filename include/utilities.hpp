#ifndef UTILITIES_CPP_SNIPPETS_HEADER
#define UTILITIES_CPP_SNIPPETS_HEADER

#include <string>
#include <vector>

/*! @fn argc_checker
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

/*! @fn dir_checker
 * @brief check if directory exists
 * 
 * @param dir_path directory path
 *
 * @return true if directory exists else false.
 */
auto dir_checker(
    std::string_view dir_path
) -> bool;

#endif