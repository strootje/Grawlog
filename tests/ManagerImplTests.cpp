#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ctime>
#include <string>
#include "./../include/Entry.hpp"
#include "./../include/ManagerImpl.hpp"
#include "./../include/Writer.hpp"

class MockWriter : public Grawlog::Writer
{
public:
	MOCK_CONST_METHOD2(Write, void(const Grawlog::Entry&,const std::string&));
};

TEST(ManagerImplTests, SANITY_CHECK)
{
	// Arrange
	auto writer = new MockWriter();
	auto manager = Grawlog::ManagerImpl::Instance();
	manager->Register("test", [=]() { return writer; });

	// Act
	manager->Log(Grawlog::Entry{ std::time(nullptr), Grawlog::Severity::Information, __FILE__, __FUNCTION__, __LINE__ }, "test_message");

	// Assert
	ASSERT_EQ(1, 2);
	delete writer;
	delete manager;
}
