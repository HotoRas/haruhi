#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int x) {
	if (x<2) {
		return (unsigned long long)1;
	}
	//printf("%llu\n", x * factorial(x-1));
	return x * factorial(x-1);
}
#define fac(x) factorial(x)

unsigned long long haruhi_min(int x) {
	//unsigned long long ii = factorial(x);
	return fac(x) + fac(x-1) + fac(x-2) + x - 3;
}

unsigned long long haruhi_max(int x) {
	//unsigned long long ii = factorial(x);
	return fac(x) + fac(x-1) + fac(x-2) + fac(x-3) + x - 3;
}

unsigned long long fibo(int x) {
	if (x < 1) return 0;
	if (x == 1) return 1;
	return fibo(x-1) + fibo(x-2);
}

// //n!/(n-2)*n+fibo(2(n-3))
unsigned long long new_approach(int x) {
	printf("fibo(2(n-3)): %llu (n: %d)\n", fibo(2 * (x-3)), x);
	return fac(x) / (x-1) * x + fibo(2 * (x-3));
}

int disp_help() {
	fprintf(stderr,"haruhi [--help | -?]\nharuhi size");
	fprintf(stderr,"example:\n");
	fprintf(stderr,"\tharuhi 14\n");
	return 1;
}

int main(int argc, char** argv) {
	if (argc < 2 || argv[1] == "--help" || argv[1] == "-?") return disp_help();

	int value = atoi(argv[1]);
	
	if (value == 1) {
		printf("%d\n", 1); return 0;
	}
	if (value == 2) {
		printf("%d\n", 3); return 0;
	}
	if (value == 3) {
		printf("%d\n", 9); return 0;
	}
	unsigned long long min, max, new;
	min = haruhi_min(value); max = haruhi_max(value);
	new = new_approach(value);
	printf("The minimum is: %llu\n", min);
	printf("The maximum is: %llu\n", max);
	printf("An modified high schooler's answer is:\n\t%llu\n", new);
	//printf("Meanwhile, the dumbest result is\n\t%llu\n", dumb);
	printf("\nfunction source: https://youtu.be/lcRHHIjAdMI\nedited by: Hoto Ras (hotoras03@gmail.com)");
	return 0;
}
