/*
* C program to compute the average and the median of the 100000 element array. 
* Program uses 2 functions and outputs the result to the user.
* to compile this file: gcc cprogram.C -o cprogram
* to run this file:  ./cprogram
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declare one of our own functions so the compiler will understand the references below
void countnum(int[], int, int);

//declare an constant integer called arraysz of size 1000
const int arraysz = 100000;

using namespace std;

int main(int argc, char** argv) 
{

	int n1;
	int n2; 
	cout << "Enter two ints: ";
	cin >> n1 >> n2;

	//this is an integer array of size arraysz
	int intarray[arraysz];
	int num;
	srand(time(NULL));
	
	//fill the array with random numbers
	for (int t = 0; t < arraysz; t++) {
		intarray[t] = rand() % 100;
	}

	countnum(intarray[], n1, n2);
	
	return 1;

}
// this is the implementation of the function declared above
// function caluculates the number of times a number (numberentered) appears in the array
void countnum(int intarray[], int number1, int number2) {

	//assign a counter
	int numcount = 0;

	//perform linear search
	for (int t = 0; t < arraysz; t++) {
		if (intarray[t] < number1 && intarray[t] > number1) {
			numcount += 1;
		}
	}
	printf("The number %d appears in the array %d", number1, numcount);
}
