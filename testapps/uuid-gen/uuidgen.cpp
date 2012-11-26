#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
int main(int argc, char* argv[])
{
	boost::uuids::basic_random_generator<boost::mt19937> gen;
	boost::uuids::uuid u = gen();
	std::cout << u << std::endl;
	return 0;
}
