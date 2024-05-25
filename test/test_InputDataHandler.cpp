#include <catch2/catch.hpp>
#include <opencv2/opencv.hpp>

#include "InputDataHandler.hpp"


TEST_CASE( "input data handler", "[InputDataHandler]" ) {

    SECTION( "zero size with no file directory path" )
    {
        InputDataHandler input_data_handler("");
        const cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
        const int rows{0};
        const int cols{0};
        const cv::Size empty_mat(rows, cols);
        REQUIRE(diffraction_pattern.size() == empty_mat);
    }

    SECTION( "zero size with non existing directory path" )
    {
        InputDataHandler input_data_handler("./foo/bar/dkljf/oijeo");
        const cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
        const int rows{0};
        const int cols{0};
        const cv::Size empty_mat(rows, cols);
        REQUIRE(diffraction_pattern.size() == empty_mat);
    }

    SECTION( "1280 x 1024 size with test/data directory path" )
    {
        InputDataHandler input_data_handler("../test/data/");
        const cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
        const int rows{1280};
        const int cols{1024};
        // I think of matrices as rows x cols
        // but opencv size is cols (width) x rows (height)
        const cv::Size test_data_mat(cols, rows);
        REQUIRE(diffraction_pattern.size() == test_data_mat);
        REQUIRE(diffraction_pattern.rows == rows);
        REQUIRE(diffraction_pattern.cols == cols);
    }


}