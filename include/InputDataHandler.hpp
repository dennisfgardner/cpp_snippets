#ifndef INPUT_DATA_HANDLER_CPP_SNIPPETS_HEADER
#define INPUT_DATA_HANDLER_CPP_SNIPPETS_HEADER

#include <string>
#include <vector>
#include <set>

#include <opencv2/opencv.hpp>


#include "utilities.hpp"


/** \class InputDataHandler
 * \brief Input Data Handler
 *
 * This class parses the data file. The data filenames contain information
 * about the data collect. To extract the information, the file name needs to
 * be parsed.
 */
class InputDataHandler
{

public:
    /**
     * \brief InputDataHandler Constructor.
     *
     * Calling the constructor will iterate through all the filenames in the
     * directory and parse the filenames to extract the data collection
     * information and process the diffraction pattern. 
     *
     * \param data_directory path to directory containing data files must end with "/"
     */
    explicit InputDataHandler(const std::string &data_directory);


    /**
     * \brief Get Diffraction Pattern
     *
     * Return the background subtracted, high-dynamic range, diffraction pattern. 
     *
     * \return diffraction pattern
     */
    [[nodiscard]] auto get_diffraction_pattern() -> cv::Mat;


    /**
     * \brief get data filenames
     * \return data filenames
     */
    [[nodiscard]] auto get_filenames() const -> std::set<std::string> {return filenames;};


    /**
     * \brief get number of rows
     * \return number of rows
     */
    [[nodiscard]] auto get_num_rows() const -> int{return rows_cols.first;};


    /**
     * \brief get number of columns
     * \return number of columns
     */
    [[nodiscard]] auto get_num_cols() const -> int {return rows_cols.second;};


private:
    const std::string data_dir{};
    const std::string data_file_extension{};
    std::set<std::string> filenames{};
    std::pair<int, int> rows_cols{0, 0};
    const int opencv_datatype{};
    struct filename_info
    {
        std::string prefix{};
        unsigned int scan_num{};
        double x_pos{};
        double y_pos{};
        double exposure{};
        unsigned int frame_num{};

    };
    std::vector<filename_info> scan_info{};
};

#endif // INPUT_DATA_HANDLER_CPP_SNIPPETS_HEADER