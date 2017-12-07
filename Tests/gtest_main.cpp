//
// Created by shay on 11/23/17.
//

#include <gtest/gtest-typed-test.h>
#include <gtest/gtest.h>


GTEST_API_ int gtest_main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}