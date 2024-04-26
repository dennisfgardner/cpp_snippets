#ifndef INPUT_DATA_HANDLER_CPP_SNIPPETS_HEADER
#define INPUT_DATA_HANDLER_CPP_SNIPPETS_HEADER

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>


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
     * information. 
     *
     * \param data_directory path to directory containing data files
     */
    explicit InputDataHandler(const std::string &data_directory) : dir{data_directory} {};


    /**
     * \brief Get Diffraction Pattern
     *
     * Return the background subtracted, high-dynamic range, diffraction pattern. 
     *
     * \return diffraction pattern
     */
    [[nodiscard]] auto get_diffraction_pattern() -> cv::Mat;

private:
    std::string dir{};
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