#include <iostream>
#include "/home/alex/proga/ea-course/longnum/longnum.h"

#include "Testlib.h"

bool Geo::Testlib::__assert_print_to_stderr = true;
bool Geo::Testlib::__assert_print_if_ok     = false;
bool Geo::Testlib::__assert_throw_exception = true;
bool Geo::Testlib::__test_print_to_stderr   = true;
bool Geo::Testlib::__test_throw_exception   = false;




using namespace std;

void Test1() {
	{
	   ASSERT_MSG(LongNum((int)1) == LongNum((unsigned long long)1), "1 is equal to 1");
	   ASSERT_EQUAL_MSG(1, 1, "1 is still equal to 1");
	}
	{
	   ASSERT_MSG(1 != 1, "1 is not equal to 1");
	}
	{
	   ASSERT_MSG(1 == 2, "1 is equal to 2"); // This test will not be executed, only one fail per testFunction
	}
}

void Test2() {
	{
	   ASSERT_MSG(1 > 0, "1 is greater than 0");
	   ASSERT_MSG(1 < 2, "1 is smaller than 2");
	}
}

void TestAll() {
	Geo::Testlib::Test test;
	RUN_TEST_MSG(test, Test1, "Equality check");
	RUN_TEST_MSG(test, Test2, "Comparison check");
}

int main() {
	TestAll();

	return 0;
}
