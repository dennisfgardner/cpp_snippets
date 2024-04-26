#define CATCH_CONFIG_MAIN

#include <string_view>
#include <string>
#include <set>

#include <filesystem>

#include <catch2/catch.hpp>
#include <opencv2/core.hpp>

#include "utilities.hpp"
#include "InputDataHandler.hpp"

TEST_CASE( "argument count checker", "[utilities]" )
{
    const std::string usage{"test test test"};
    REQUIRE(argc_checker(1, usage, 0) == true);
    REQUIRE(argc_checker(2, usage, 1) == true);
    REQUIRE(argc_checker(10, usage, 9) == true);
    REQUIRE(argc_checker(10, usage, 0) == false);
    REQUIRE(argc_checker(10, usage, 8) == false);
    REQUIRE(argc_checker(2, usage, 0) == false);
}

TEST_CASE( "directory checker", "[utilities]" )
{
    REQUIRE(dir_checker("../test/") == true);
    const std::string_view src{"../src/"};
    REQUIRE(dir_checker(src) == true);
    const std::string hdr{"../include"};
    REQUIRE(dir_checker(hdr) == true);
    REQUIRE(dir_checker("/foobar_98930") == false);
    const std::string_view foo{"./ijdhdofi/"};
    REQUIRE(dir_checker(foo) == false);
    const std::string bar{"jkjdf/dfj/dor"};
    REQUIRE(dir_checker(bar) == false);
}

TEST_CASE( "get directory filenames", "[utilities]" )
{

    const std::set<std::string> filelist{
        "bkg000_x_017800_y_014600_ExpTime_us_000100_FrameNum_0000.csv",
        "bkg000_x_017800_y_014600_ExpTime_us_000100_FrameNum_0001.csv"
    };
    REQUIRE(get_dir_filenames("../test/data", ".csv") == filelist);
    const std::set<std::string> no_files{};
    REQUIRE(get_dir_filenames("../test/data", ".foo") == no_files);
    REQUIRE(get_dir_filenames("../koije/jcid", ".bar") == no_files);

}

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
        InputDataHandler input_data_handler("../test/data");
        const cv::Mat diffraction_pattern = input_data_handler.get_diffraction_pattern();
        const int rows{1280};
        const int cols{1024};
        const cv::Size test_data_mat(rows, cols);
        REQUIRE(diffraction_pattern.size() == test_data_mat);
    }


}