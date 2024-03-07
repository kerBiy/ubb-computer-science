#include <iostream>
#include "../tests/TestExtins.h"
#include "../tests/TestScurt.h"

int main(int argc, char **argv)
{
	testAll();
	testAllExtins();

	std::cout << "All tests ran successfully.\n";
	return 0;
}
