/*
*Write a C program that searches through an array of data looking for the largest element 
*(implement linear search). Fill an array with 100000 random numbers using srand(time(NULL)); 
* and int r = rand() [15 min]
* to compile this file: gcc cprogram.C -o cprogram
* to run this file:  ./cprogram
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declare one of our own functions so the compiler will understand the references below
void printmaxnum(int[]);

//declare an constant integer called arraysz of size 1000
const int arraysz = 100000;

int main(int argc, char** argv) {

	//this is an integer array of size arraysz
	int intarray[arraysz];
	srand(time(NULL));


	char name[20];
	printf("Hello friend, What is your name?\n");
	scanf("%s", &name);
	printf("Hello %s Welcome to c programming", name);



	for (int t = 0; t < arraysz; t++) {
		intarray[t] = rand() % 100;
	}

	printmaxnum(intarray);
	getch();
	getch();
	return 1;

}
// this is the implementation of the function declared above
void printmaxnum(int intarray[]) {

	//perform linear search
	int maxnum = intarray[0];
	for (int t = 0; t < arraysz; t++) {
		if (intarray[t] > maxnum) {
			maxnum = intarray[t];
		}
	}
	printf("The max number in array is %d", maxnum);
}


