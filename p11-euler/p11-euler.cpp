#include <iostream>


#include "the_number.h"
#include "NumberArrayCalculator.h"



int main(int argc, char **argv)
{
	unsigned long long p11_answ = 0;


	std::cout << the_number << "\n";


	NumberArrayCalculator num_arr;

	num_arr.set_matrix(the_number);


	p11_answ = num_arr.highest_product(4);


	std::cout << "The answer to the 11th problem of ProjectEuler.Net is " << p11_answ << ".\n";


	return 0;
}