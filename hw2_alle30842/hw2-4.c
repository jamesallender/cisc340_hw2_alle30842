#include <time.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){

	double a = 4745689733.6445467;
	double b = 8545679766.6646597;
	double result = 0;
	int numRuns = 1000000000;
	clock_t begin;
	clock_t end;

	// addition operations
	begin = clock();

	for(int i = 0; i < numRuns; i++){
		result = a + b;
	}
		
	end = clock();
	double run_time_add = (double)(end - begin) / CLOCKS_PER_SEC;

	// Pow workaround
	result = 1;
	for (int i = 0; i < 6; ++i)
	{
        result *= run_time_add;
	}
	int mflopsAdd = (int) (numRuns/result);


	// devision operations
	begin = clock();

	for(int i = 0; i < numRuns; i++){
		result = a * b;
	}

	end = clock();
	double run_time_mult = (double)(end - begin) / CLOCKS_PER_SEC;
	// Pow workaround
	result = 1;
	for (int i = 0; i < 6; ++i)
	{
        result *= run_time_mult;
	}
	int mflopsMult = (int)numRuns/result;

	printf("Add MFLOPS: %d\n", mflopsAdd);
	printf("Divide MFLOPS: %d\n", mflopsMult);

	return 1;
}