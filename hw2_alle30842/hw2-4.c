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
	int mflopsAdd = (int) numRuns/(double)pow(run_time_add, 6.0);


	// devision operations
	begin = clock();

	for(int i = 0; i < numRuns; i++){
		result = a * b;
	}

	end = clock();
	double run_time_mult = (double)(end - begin) / CLOCKS_PER_SEC;
	int mflopsMult = (int)numRuns/(double)pow(run_time_mult, 6.0);

	printf("Add MFLOPS: %d\n", mflopsAdd);
	printf("Divide time: %d\n", mflopsMult);
}