#include <gtest/gtest.h>
#include "instructions.h"

TEST(MathUtils, Multiply) 
{
    EXPECT_EQ(multiply(2, 3), 6);
}