/* Goal: Create a file containing 10,000 random 4-letter strings, sorted alphabetically. */ 

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGTH 10000
#define STRING_LENGTH 4

/* Handle GNU quirks */
#ifndef __GNUC__
#define __compar_fn_t int(*)
#endif

/* Time measurements */
double bench();


int main () {

	bench();

	/* Allocate space for our strings */
	char* a=(void*)malloc(ARRAY_LENGTH * (STRING_LENGTH+1));		/* Don't forget trailing NUL or LF */
	if(a==NULL) {

		printf("Unable to allocate memory\n");
		exit(1);
	} 

	/* Define an alphabet */
	char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	/* Initialize our (weak) random generator #TODO and create many strings */
	srand(time(NULL));

	char* line=a;	/* Set to beginning of array */
	int n=0;
	int y=0;
	while(n< ARRAY_LENGTH * (STRING_LENGTH+1)){
		for(y=0; y< 4; y++){

			a[n]=alphabet[(rand() % (sizeof(alphabet)-1))];
			n++;
		}

		/* Add terminating LF (change this to 0x0 if you want to print...) */
		a[n]=0x0a;
		n++;		
	}

	double gen=bench();

	/* Sort */
	qsort(a, ARRAY_LENGTH, STRING_LENGTH+1, (__compar_fn_t)strcmp);

	double sort=bench();

	/*
	Print (change LF to NULL above first!)
	n=0;
	while(n<ARRAY_LENGTH * (STRING_LENGTH+1)){

		printf("String: %s\n",&a[n]);
		n+=(STRING_LENGTH+1);
	}
	*/

	/* Write to file */
	FILE *f;
	f=fopen("strings.txt", "w");
	fwrite(a, 1, (ARRAY_LENGTH * (STRING_LENGTH+1)), f);
	fclose(f);

	double write=bench();


	/* Clean up */
	free(a);

	double complete=bench();


	/* Finish benchmark */
	printf("Generate: %.1f ms\n", gen); 
	printf("Sort: %.1f ms\n", sort); 
	printf("Write file: %.1f ms\n", write); 
	printf("Total: %.1f ms\n", gen+sort+write+complete); 

	return 0;
}


/** 
 * Benchmark
 *
 * Returns the number of milliseconds that have elapsed since the last call
 * #TODO may have a resolution of 10ms on some systems 
 */
double bench() {

	// Store the last bench time
	static double last_time;

	// Get time
	struct timeval tv;
	gettimeofday(&tv, NULL);

	// Get Start time, if first run
	if(last_time==0) {

		last_time=tv.tv_sec+(tv.tv_usec/1000000.0);
		return 0;
	}

	double this_time=tv.tv_sec+(tv.tv_usec/1000000.0);
	double elapsed_ms=(this_time-last_time)*1000;
	last_time=this_time;
	return elapsed_ms;
}




















