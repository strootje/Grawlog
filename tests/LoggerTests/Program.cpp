#include "./Logger.hpp"
#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

TEST(LoggerTests, DoesOneEqOne)
{
	ASSERT_EQ(1, 1);
}
