/*
* C program to compute the average and the median of the 100000 element array. 
* Program uses 2 functions and outputs the result to the user.
* to compile this file: gcc cprogram.C -o cprogram
* to run this file:  ./cprogram
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//declare one of our own functions so the compiler will understand the references below
int average(int[]);
int median(int[]);

//declare an constant integer called arraysz of size 1000
const int arraysz = 100000;

int main(int argc, char** argv) {

	//this is an integer array of size arraysz
	int intarray[arraysz];
	int num;
	srand(time(NULL));
	
	//fill the array with random numbers
	for (int t = 0; t < arraysz; t++) {
		intarray[t] = rand() % 100;
	}

	// Call function average and assign the returned value to answer
	int answer = average(intarray);

	// Call function median and assign the returned value to answer
	int mediananswer = median(intarray);

	printf("The average of the array is %d\n", answer);
	printf("The median of the array is %d\n", mediananswer);
	return 1;

}
// this is the implementation of the function declared above
// function caluculates the average of elements in the array
int average(int intarray[]) {
	
	int sum = 0;
	int average = 0;

	//perform linear search
	for (int t = 0; t < arraysz; t++) {
		sum += intarray[t];
	}

	return average = sum / arraysz;
}

// this is the implementation of the function declared above
// function caluculates the median of elements in the array
int median(int intarray[]) {

	int temp;
	int i, j;

	// the following two loops sort the array x in ascending order
	for (i = 0; i<arraysz - 1; i++) {
		for (j = i + 1; j<arraysz; j++) {
			if (intarray[j] < intarray[i]) {
				// swap elements
				temp = intarray[i];
				intarray[i] = intarray[j];
				intarray[j] = temp;
			}
		}
	}

	if (arraysz % 2 == 0) {
		// if there is an even number of elements, return mean of the two elements in the middle
		return((intarray[arraysz / 2] + intarray[arraysz / 2 - 1]) / 2.0);
	}
	else {
		// else return the element in the middle
		return intarray[arraysz / 2];
	}
}



