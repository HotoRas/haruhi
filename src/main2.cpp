#include <iostream>
#include "bigint.h"

#define Bigint bigint

#include <vector>
//std::vector<Bigint> * facto_db;

Bigint factorial(int n) {
	if (n < 2) return 1;
	Bigint result = n;
	result *= factorial(n-1);
	//facto_db->emplace_back(result);
	return result;
}

Bigint fibonacci(int n) {
	Bigint result = 0;
	if (n > 1) result = fibonacci(n-1) + fibonacci(n-2);
	else if (n == 1) result = 1;
	return result;
}

#define _bigint Bigint
#define _fac(n) factorial(n)
#define _fibo(n) fibonacci(n)

_bigint haruhi_min(int x) {
	_bigint t = _fac(x-2);
	return t * ((x + 1) * (x - 1) + 1) + x - 3;
}

_bigint haruhi_max(int x) {
	_bigint t = _fac(x-3);
	return t * (((x + 1) * (x - 1) + 1) * (x - 2) + 1) + x - 3;
}

_bigint new_approach(int x) {
	return _fac(x-2) * x * x + _fibo(2 * (x-3));
}

int disp_help() {
	std::cerr << "haruhi [--help | -?]\nharuhi size"
		<< "example:\n"
		<< "\tharuhi 14\n";
	return 1;
}

int main(int argc, char** argv) {
	if (argc < 2 || argv[1] == "--help" || argv[1] == "-?") return disp_help();

	int value = atoi(argv[1]);
	
	if (value == 1) {
		std::cout << 1 << std::endl; return 0;
	}
	if (value == 2) {
		std::cout << 3 << std::endl; return 0;
	}
	if (value == 3) {
		std::cout << 9 << std::endl; return 0;
	}

	//facto_db = new std::vector<_bigint>(1);
	_bigint min, max, newa;
	min = haruhi_min(value); max = haruhi_max(value);
	newa = new_approach(value);
	//printf("The minimum is: %llu\n", min);
	//printf("The maximum is: %llu\n", max);
	//printf("An modified high schooler's answer is:\n\t%llu\n", new);
	//printf("Meanwhile, the dumbest result is\n\t%llu\n", dumb);
	//printf("\nfunction source: https://youtu.be/lcRHHIjAdMI\nedited by: Hoto Ras (hotoras03@gmail.com)");
	
	std::cout << "The minimum is: " << min << std::endl
		<< "The maximum is: " << max << std::endl
		<< "An modified high schooler's anser is:\n\t" << newa << std::endl
		<< "\nfunction source: https://youtu.be/lcRHHIjAdMI\nedited by: Hoto Ras (hotoras03@gmail.com)\n";
	return 0;
}
