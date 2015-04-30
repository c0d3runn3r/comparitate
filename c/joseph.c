// Goal: Create a file containing 10,000 random 4-letter strings, sorted alphabetically.
// 

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGTH 10000
#define STRING_LENGTH 4

// Handle GNU quirks
#ifndef __GNUC__
#define __compar_fn_t int(*)
#endif

// Comparison function
int cmpfunc (const void *a, const void *b);


int main () {

	// Benchmark #TODO may have a resolution of 10ms on some systems
	double start_time, end_time;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	start_time=tv.tv_sec+(tv.tv_usec/1000000.0);


	// Allocate space for our strings
	char* a=(void*)malloc(ARRAY_LENGTH * (STRING_LENGTH+1));		// Don't forget trailing NUL or LF
	if(a==NULL) {

		printf("Unable to allocate memory\n");
		exit(1);
	} 

	// Define an alphabet
	char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// Initialize our (weak) random generator #TODO and create many strings
	srand(time(NULL));

	char* line=a;	// Set to beginning of array
	int n=0;
	int y=0;
	while(n< ARRAY_LENGTH * (STRING_LENGTH+1)){
		for(y=0; y< 4; y++){

			a[n]=alphabet[(rand() % (sizeof(alphabet)-1))];
			n++;
		}

		// Add terminating LF (change this to 0x0 if you want to print...)
		a[n]=0x0a;
		n++;		
	}

	// Sort
	qsort(a, ARRAY_LENGTH, STRING_LENGTH+1, (__compar_fn_t)strcmp);

	// Print (change LF to NULL above first!)
	// n=0;
	// while(n<ARRAY_LENGTH * (STRING_LENGTH+1)){

	// 	printf("String: %s\n",&a[n]);
	// 	n+=(STRING_LENGTH+1);
	// }

	// Write to file
	FILE *f;
	f=fopen("strings.txt", "w");
	fwrite(a, 1, (ARRAY_LENGTH * (STRING_LENGTH+1)), f);
	fclose(f);


	// Clean up
	free(a);

	// Finish benchmark
	gettimeofday(&tv, NULL);
	end_time=tv.tv_sec+(tv.tv_usec/1000000.0);
	printf("Complete in %.1f ms\n", ((end_time - start_time) * 1000 )); 

	return 0;
}



int cmpfunc (const void *a, const void *b) {





}




















