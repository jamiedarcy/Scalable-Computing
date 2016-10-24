/*
* to compile this file: gcc countNumber.C -o cprogram
* to run this file:  ./countnumber
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//declare one of our own functions so the compiler will understand the references below
void countnum(int[], int);

//declare an constant integer called arraysz of size 1000
const int arraysz = 100000;

int main(int argc, char** argv) {

	//this is an integer array of size arraysz
	int intarray[arraysz];
	int num;
	srand(time(NULL));

	if (argc != 2) /* argc should be 2 for correct execution */
	{
		/* We print argv[0] assuming it is the program name */
		printf("usage: %s filename", argv[0]);
	}
	else
	{
		num = atoi(argv[1]);
		printf(argv[1]);
	}

	//fill the array with random numbers
	for (int t = 0; t < arraysz; t++) {
		intarray[t] = rand() % 100;
	}

	// Call function countnum
	countnum(intarray, num);
	return 1;

}
// this is the implementation of the function declared above
// function caluculates the number of times a number (numberentered) appears in the array
void countnum(int intarray[], int numberentered) {

	//assign a counter
	int numcount = 0;

	//perform linear search
	for (int t = 0; t < arraysz; t++) {
		if (intarray[t] == numberentered) {
			numcount += 1;
		}
	}
	printf("The number %d appears in the array %d", numberentered, numcount);
}