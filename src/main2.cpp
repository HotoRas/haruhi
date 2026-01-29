#include <iostream>
#include "bigint.h"

#define Bigint bigint

#include <unordered_map>
std::unordered_map<bigint, bigint> *facto_db;
std::unordered_map<bigint, bigint> *fibo_db;
bigint *facto_db_top;
bigint *fibo_db_top;

Bigint factorial(bigint n)
{
	if (n < bigint(2))
		return 1;
	Bigint &result = Bigint(n);
	while (1)
	{
		n -= 1;
		if (n < bigint(1))
			break;
		if (facto_db->find(n) != facto_db->end())
		{
			result *= facto_db->at(n);
			break;
		}
		result *= n;
	}
	facto_db->emplace(n, result);
	facto_db_top = &n;

	return result;
}

bigint factorial(int n) { return factorial(bigint(n)); }

Bigint fibonacci(bigint n)
{
	Bigint result = 0, tmp1 = 0, tmp2 = 0;
	if (fibo_db->find(n) != fibo_db->end())
		return fibo_db->at(n);
	if (n > bigint(1))
	{
		result = bigint(1);
		for (bigint i = bigint(1); i <= n; i++)
		{
			tmp1 = result;
			result = tmp1 + tmp2;
			tmp2 = tmp1;
			if (i + bigint(3) < n && fibo_db->find(i + bigint(3)) != fibo_db->end())
			{
				fibo_db->emplace(n, fibo_db->at(i + bigint(3)));
			}
		}
		fibo_db->emplace(n, result);
		fibo_db_top = &n;
		return result;
	}
	else if (n == bigint(1))
		result = bigint(1);
	return result;
}

bigint fibonacci(int n) { return fibonacci(bigint(n)); }

#define _fac(n) factorial(n)
#define _fibo(n) fibonacci(n)

bigint haruhi_min(int x)
{
	bigint t = _fac(x - 2);
	return operator+(operator*(t, ((x + 1) * (x - 1) + 1)), x - 3);
}

bigint haruhi_max(int x)
{
	bigint t = _fac(x - 3);
	return operator+(operator*(t, (((x + 1) * (x - 1) + 1) * (x - 2) + 1)), x - 3);
}

bigint new_approach(int x)
{
	return operator*(_fac(x - 2), (x * x)) + _fibo(2 * (x - 3));
}

int disp_help()
{
	std::cerr << "haruhi [--help | -?]\nharuhi size"
			  << "example:\n"
			  << "\tharuhi 14\n";
	return 1;
}

int main(int argc, char **argv)
{
	if (argc < 2 || argv[1] == "--help" || argv[1] == "-?")
		return disp_help();

	facto_db = new std::unordered_map<bigint, bigint>();
	fibo_db = new std::unordered_map<bigint, bigint>();
	facto_db_top = new bigint(0);
	fibo_db_top = new bigint(0);

	int value = atoi(argv[1]);

	if (value == 1)
	{
		std::cout << 1 << std::endl;
		return 0;
	}
	if (value == 2)
	{
		std::cout << 3 << std::endl;
		return 0;
	}
	if (value == 3)
	{
		std::cout << 9 << std::endl;
		return 0;
	}

	// facto_db = new std::vector<_bigint>(1);
	bigint min, max, newa;
	min = haruhi_min(value);
	max = haruhi_max(value);
	newa = new_approach(value);
	// printf("The minimum is: %llu\n", min);
	// printf("The maximum is: %llu\n", max);
	// printf("An modified high schooler's answer is:\n\t%llu\n", new);
	// printf("Meanwhile, the dumbest result is\n\t%llu\n", dumb);
	// printf("\nfunction source: https://youtu.be/lcRHHIjAdMI\nedited by: Hoto Ras (hotoras03@gmail.com)");

	std::cout << "The minimum is: " << min << std::endl
			  << "The maximum is: " << max << std::endl
			  << "An modified high schooler's anser is:\n\t" << newa << std::endl
			  << "\nfunction source: https://youtu.be/lcRHHIjAdMI\nedited by: Hoto Ras (hotoras03@gmail.com)\n";
	return 0;
}
