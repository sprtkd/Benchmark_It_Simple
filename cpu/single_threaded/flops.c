//Built by Suprotik Dey, 2019

#include <stdio.h>
#include <time.h>
#include "logger.h"
#define ITERS 500000000

#define FLOAT_CONST_1 5468.56506
#define FLOAT_CONST_2 78942.78901
#define FLOAT_CONST_3 942.27014

int main()
{
	float f1, f2, f3, f4;
	long long int iter;
	clock_t t;
	double time_taken, time_taken_null, curr_flops;
	
	f1 = FLOAT_CONST_1;
	f2 = FLOAT_CONST_2;
	f3 = FLOAT_CONST_3;

	logger("--FLOPS Estimator (Single threaded)--\n\n");
	
	// printf("--FLOPS Estimator (Single threaded)--\n\n");
	
	while(1)
	{
		t = clock();
		for(iter=1; iter <= ITERS; iter++)
		{
			f4 = (f1*f2)/f3;
		}
		t = clock() - t;
		
		time_taken = ((double)t)/CLOCKS_PER_SEC;
		
		//estimating null loop time
		t = clock();
		for(iter=1; iter <= ITERS; iter++)
		{
		}
		t = clock() - t;
		time_taken_null = ((double)t)/CLOCKS_PER_SEC;
		time_taken = time_taken - time_taken_null;
		
		if(time_taken <= 0.0)
			continue;
			
		curr_flops = (2.0*(double)ITERS)/time_taken; //since two operations per cycle
		logger("%f secs\t%f flops\n", time_taken, curr_flops);
	}
	
	return 0;
	
}
