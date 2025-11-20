#include <gtest/gtest.h>
#include "instructions.h"

TEST(MathUtils, Execute) 
{
    EXPECT_EQ(execute(0), false);
}