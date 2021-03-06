#include <string>
#include <sys/time.h>
#include <fstream>

#include "tests.hpp"

#ifdef USE_STD
	namespace ft = std;
	#include <vector>
	#define FILENAME "output_vector_std.txt"
#else
	#include "../containers/vector.hpp"
	#define FILENAME "output_vector_ft.txt"
#endif

void testVector(const int seed)
{
	srand(seed);

	std::string filename(FILENAME);
	std::ofstream output;
	output.open("outputs/" + filename, std::ofstream::trunc);
	output << std::boolalpha;
	struct timeval time_start;
	struct timeval time_end;
	gettimeofday(&time_start, NULL);

/**************************************************************************************************
 * start tests
**************************************************************************************************/

	ft::vector<int> vec_int;
	ft::vector<std::string> vec_str(COUNT, "ciao");
	ft::vector<std::string> vec_str_range(vec_str.begin(), vec_str.end());
	ft::vector<std::string> vec_str_copy(vec_str);

	for (int i = 0; i < COUNT; ++i)
	{
		vec_int.push_back(rand());
		output << vec_int[i] << std::endl;
		output << vec_str[i] << std::endl;
		output << vec_str_range[i] << std::endl;
		output << vec_str_copy[i] << std::endl;
	}

	vec_str.push_back(" a tutti");
	output << (vec_str == vec_str_copy) << std::endl;			// false
	output << (vec_str_range == vec_str_copy) << std::endl;		// true
	output << (vec_str_range < vec_str_copy) << std::endl;		// false
	vec_str_range.insert(vec_str_range.begin() + (rand() % (vec_str_range.size() / 2)), "cIao");
	output << (vec_str_range < vec_str_copy) << std::endl;		// true

	vec_int[rand() % (vec_int.size() - 1)] = rand();

// print vec_int //
	for (ft::vector<int>::reverse_iterator r_it = vec_int.rbegin(); r_it != vec_int.rend(); ++r_it)
		output << *r_it << std::endl;
///////////////////

	ft::vector<int>().swap(vec_int);

// print vec_int //
	for (ft::vector<int>::iterator it = vec_int.begin(); it != vec_int.end(); ++it)
		output << *it << std::endl;
///////////////////

	vec_int.assign(COUNT / 2, rand());
	vec_int.pop_back();
	vec_int.insert(vec_int.begin() + ft::vector<int>::difference_type(&vec_int[rand() % (vec_int.size() - 1)] - &vec_int[0]), COUNT / 2, rand());
	vec_int.erase(vec_int.begin(), vec_int.begin() + (rand() % (vec_int.size() / 2)));

// print vec_int //
	for (long unsigned int i = 0; i < vec_int.size(); ++i)
		output << vec_int.at(i) << std::endl;
///////////////////

/**************************************************************************************************
 * end tests
**************************************************************************************************/

	gettimeofday(&time_end, NULL);
	output.close();
	output.open("performances/" + filename);
	output << time_end.tv_sec - time_start.tv_sec + 1e-6 * (time_end.tv_usec - time_start.tv_usec);
}
