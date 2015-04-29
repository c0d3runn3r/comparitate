// Goal: Create a file containing 10,000 random 4-letter strings, sorted alphabetically.
// 
// Don't make the most efficient program possible, just write something natural that 
// thinks about the generic case.  The following loop (for example) uses a strlen type
// check with every iteration.  But it's easy to read and easy to change.

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <sys/time.h>

using namespace std;

#define ARRAY_SIZE 10000


// Don't want this on the stack!
vector<string> a(ARRAY_SIZE);



int main () {

	// Benchmark #TODO may have a resolution of 10ms on some systems
	double start_time, end_time;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	start_time=tv.tv_sec+(tv.tv_usec/1000000.0);

	// Initialize our (weak) random generator #TODO
	srand(time(NULL));

	// Create array of random letters
	int n;
	string letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for( string &line : a) {
		
		while(line.length() < 4) {

			line+=letters[(int) (rand() % letters.length())];
		}
		
	}	

	// Sort them
	sort (a.begin(), a.end());

	// Save to file
	ofstream file;
	file.open("joseph_output.txt");
	for( const string &line : a) {

		file << line << endl;
	}
	
	file.close();

	// Finish benchmark
	gettimeofday(&tv, NULL);
	end_time=tv.tv_sec+(tv.tv_usec/1000000.0);
	cout << "Complete in " << ((end_time - start_time) * 1000 ) << " ms" << endl; 

	return 0;
}