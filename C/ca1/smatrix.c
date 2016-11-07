/*
* Scalable Computing -CA1
* Jamie Darcy (X00130016) - 01/11/2016
* to compile this file: g++ -fopenmp smatrix.c -o smatrix
* to run this file:  ./smatrix
*/
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int main()
{
	/* DECLARING VARIABLES */
	double wtime; // Execution time measure
	int a[255][255], b[255][255], mult[255][255]; // declaring matrices of NxN size
	int aRows, aColumns, bRows, bColumns, i, j, k;

	srand(time(NULL)); //seeds the random number generator used by the function rand
	
	cout << "\n";
	cout << "The number of processors available = " << omp_get_num_procs() << "\n";

	cout << "Enter the number of rows and columns for first matrix: ";
	cin >> aRows >> aColumns;
	cout << "Enter rows and columns for second matrix: ";
	cin >> bRows >> bColumns;

	/*
	* If colum of first matrix in not equal to row of second matrix,
	* ask the user to enter the size of matrix again.
	*/
	while (aColumns != bRows)
	{
		cout << "Error! Multiplication is not possible of the two matrices. Try again \n.";
		cout << "Enter rows and columns for first matrix: ";
		cin >> aRows >> aColumns;
		cout << "Enter rows and columns for second matrix: ";
		cin >> bRows >> bColumns;
	}

	/* Record start time*/
	wtime = omp_get_wtime();
	
	/* Genarate matirix A with random number and print*/
	cout << endl << "Matrix A:" << endl;
	for (i = 0; i<aRows; ++i)
	{
		for (j = 0; j<aColumns; ++j)
		{
			a[i][j] = rand() % 100;
			cout << " " << a[i][j];
		}
		cout << "\n";
	}

	/* Genarate matirix B with random number and print */
	cout << endl << "Matrix B:" << endl;
	for (i = 0; i<bRows; ++i)
	{
		for (j = 0; j<bColumns; ++j)
		{
			b[i][j] = rand() % 100;
			cout << " " << b[i][j];
		}
		cout << "\n";
	}

	/* Multiplication Logic
	*  Multiplying matrix a and b and storing in array mult. */
	for (i = 0; i<aRows; ++i)
		
		for (j = 0; j < bColumns; ++j)
		{
			mult[i][j] = 0;   // set initial value of resulting matrix = 0 
			
			for (k = 0; k<aColumns; ++k)
			{
				mult[i][j] += a[i][k] * b[k][j];
			}
		}

	/* Displaying the multiplication of two matrix. */
	cout << endl << "Output Matrix: " << endl;
	for (i = 0; i<aRows; ++i)
		for (j = 0; j<bColumns; ++j)
		{
			cout << " " << mult[i][j];
			if (j == bColumns - 1)
				cout << endl;
		}

	/* Record End time*/
	wtime = omp_get_wtime() - wtime;
	cout << "  Elapsed seconds = " << wtime << "\n";
	cout << "\n";

	/* TERMINATE PROGRAM */
	return 0;
}


