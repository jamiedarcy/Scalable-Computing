#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv)
{
	#pragma omp parallel
	{
		//expect 4 threads to run 
		printf("Tid is %d\n", omp_get_thread_num());
	}
	
	//parallel region ends here
	
	//barrier

	int n = 8;
	#pragma omp parallel for
	for (int i = 0; i<n; ++i)
	{	
		printf("FOR Tid is %d\n", omp_get_thread_num());
	}
	return 0;
}
