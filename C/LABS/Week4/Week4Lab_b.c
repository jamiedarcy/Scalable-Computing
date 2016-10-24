#include <iostream>
using namespace std;
int main()
{
	int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;
	cout << "Enter rows and columns for first matrix: ";
	cin >> r1 >> c1;
	cout << "Enter rows and columns for second matrix: ";
	cin >> r2 >> c2;

	/* If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again. */
	while (c1 != r2)
	{
		cout << "Error! column of first matrix not equal to row of second.";
		cout << "Enter rows and columns for first matrix: ";
		cin >> r1 >> c1;
		cout << "Enter rows and columns for second matrix: ";
		cin >> r2 >> c2;
	}

	/// <summary>
	//  Storing elements of first matrix
	/// </summary>
	/// <complexitymeasure>O(N2) - Quadratic Time</complexitymeasure>
	/// <complexitymeasureexplained>
		//The outer loop executes N times.Every time the outer loop executes, the inner loop executes N times.
		//As a result, the statements in the inner loop execute a total of N * N times.Thus, the complexity is O(N * M).
		// the total complexity for the two loops is O(N2).
	///</complexitymeasureexplained>
	///<parallelopportunity>NO - Because array is getting data from the user - Not read only</parallelopportunity>
	

	cout << endl << "Enter elements of matrix 1:" << endl;
	for (i = 0; i<r1; ++i)
		for (j = 0; j<c1; ++j)
		{
			cout << "Enter element a" << i + 1 << j + 1 << " : ";
			cin >> a[i][j];
		}

	/// <summary>
	//  Storing elements of second matrix.
	/// </summary>
	/// <complexitymeasure>O(N2) - Quadratic Time</complexitymeasure>
	/// <complexitymeasureexplained>
	//The outer loop executes N times.Every time the outer loop executes, the inner loop executes N times.
	//As a result, the statements in the inner loop execute a total of N * N times.Thus, the complexity is O(N * M).
	// the total complexity for the two loops is O(N2).
	///</complexitymeasureexplained>
	///<parallelopportunity>NO - Because array is getting data from the user - Not read only</parallelopportunity>

	cout << endl << "Enter elements of matrix 2:" << endl;
	for (i = 0; i<r2; ++i)
		for (j = 0; j<c2; ++j)
		{
			cout << "Enter element b" << i + 1 << j + 1 << " : ";
			cin >> b[i][j];
		}

	/// <summary>
	//  Initializing elements of matrix mult to 0.
	/// </summary>
	/// <complexitymeasure>O(N2) - Quadratic Time</complexitymeasure>
	/// <complexitymeasureexplained>
	//The outer loop executes N times.Every time the outer loop executes, the inner loop executes N times.
	//As a result, the statements in the inner loop execute a total of N * N times.Thus, the complexity is O(N * M).
	// the total complexity for the two loops is O(N2).
	///</complexitymeasureexplained>
	///<parallelopportunity>Yes</parallelopportunity>
	for (i = 0; i<r1; ++i)
		for (j = 0; j<c2; ++j)
		{
			mult[i][j] = 0;
		}

　
	/// <summary>
	//  Multiplying matrix a and b and storing in array mult
	/// </summary>
	/// <complexitymeasure>O(N2) - Quadratic Time</complexitymeasure>
	/// <complexitymeasureexplained>
	//The outer loop executes N times.Every time the outer loop executes, the inner loop executes N times.
	//As a result, the statements in the inner loop execute a total of N * N times.Thus, the complexity is O(N * M).
	// the total complexity for the two loops is O(N2).
	///</complexitymeasureexplained>
	///<parallelopportunity>No - Because there is an update of the array.</parallelopportunity>
	for (i = 0; i<r1; ++i)
		for (j = 0; j<c2; ++j)
			for (k = 0; k<c1; ++k)
			{
				mult[i][j] += a[i][k] * b[k][j];
			}
	/// <summary>
	//  Displaying the multiplication of two matrix.
	/// </summary>
	/// <complexitymeasure>O(N2) - Quadratic Time</complexitymeasure>
	/// <complexitymeasureexplained>
	//The outer loop executes N times.Every time the outer loop executes, the inner loop executes N times.
	//As a result, the statements in the inner loop execute a total of N * N times.Thus, the complexity is O(N * M).
	// the total complexity for the two loops is O(N2).
	///</complexitymeasureexplained>
	///<parallelopportunity>Yes</parallelopportunity>

	cout << endl << "Output Matrix: " << endl;
	for (i = 0; i<r1; ++i)
		for (j = 0; j<c2; ++j)
		{
			cout << " " << mult[i][j];
			if (j == c2 - 1)
				cout << endl;
		}
	return 0;
}
