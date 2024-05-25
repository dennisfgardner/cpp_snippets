#include <string>
#include <set>
#include <utility>

#include <catch2/catch.hpp>

#include "utilities.hpp"


TEST_CASE("argument count checker", "[utilities]" )
{
    const std::string usage{"test test test"};
    REQUIRE(argc_checker(1, usage, 0) == true);
    REQUIRE(argc_checker(2, usage, 1) == true);
    REQUIRE(argc_checker(10, usage, 9) == true);
    REQUIRE(argc_checker(10, usage, 0) == false);
    REQUIRE(argc_checker(10, usage, 8) == false);
    REQUIRE(argc_checker(2, usage, 0) == false);
}

TEST_CASE("directory checker", "[utilities]" )
{
    REQUIRE(dir_checker("../test/") == true);
    const std::string src{"../src/"};
    REQUIRE(dir_checker(src) == true);
    const std::string hdr{"../include"};
    REQUIRE(dir_checker(hdr) == true);
    REQUIRE(dir_checker("/foobar_98930") == false);
    const std::string foo{"./ijdhdofi/"};
    REQUIRE(dir_checker(foo) == false);
    const std::string bar{"jkjdf/dfj/dor"};
    REQUIRE(dir_checker(bar) == false);
}

TEST_CASE("get directory filenames", "[utilities]" )
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

TEST_CASE("get csv rows and cols", "[utilities]" )
{
    const std::string no_file{"./test/data/no_file_here_dljksfkh.csv"};
    REQUIRE(get_csv_rows_and_cols(no_file) == std::pair<int, int>(0, 0));
    const int rows = 1280;
    const int cols = 1024;
    const std::pair<int, int> rows_cols{rows, cols};
    const std::string csv_file{"../test/data/bkg000_x_017800_y_014600_ExpTime_us_000100_FrameNum_0000.csv"};
    REQUIRE(get_csv_rows_and_cols(csv_file) == rows_cols) ;
    REQUIRE(get_csv_rows_and_cols("../test/data/bkg000_x_017800_y_014600_ExpTime_us_000100_FrameNum_0001.csv") == rows_cols) ;

}
