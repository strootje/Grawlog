#include "./Writers/Stream.hpp"
#include <gtest/gtest.h>

#include <sstream>
#include <ctime>

TEST(StreamWriterTests, WriteWithInfo_OutputsMessageToStream)
{
	// Arrange
	std::stringstream output;
	auto time = std::time(nullptr);
	Grawlog::Entry entry { time, Grawlog::Severity::Information, "test.cpp", "TEST", 2 };
	auto message = "hello, test";
	auto writer = new Grawlog::Writers::Stream(&output);

	// Act
	writer->Write(entry, message);

	// Assert
	std::stringstream check;
	check << "[" << time << "]" << "[1] hello, test" << std::endl;;
	ASSERT_EQ(check.str(), output.str());
}

TEST(StreamWriterTests, WriteWithDiag_OutputsMethodToStream)
{
	// Arrange
	std::stringstream output;
	auto time = std::time(nullptr);
	Grawlog::Entry entry { time, Grawlog::Severity::Diagnostic, "test.cpp", "TEST", 2 };
	auto message = "hello, test";
	auto writer = new Grawlog::Writers::Stream(&output);

	// Act
	writer->Write(entry, message);

	// Assert
	std::stringstream check;
	check << "[" << time << "]" << "[0] TEST" << std::endl;;
	ASSERT_EQ(check.str(), output.str());
}
