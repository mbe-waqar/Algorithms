#include<iostream>
using namespace std;

void printArray(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}


void insertionSort(int A[], int n)
{
	int key = 0, j = 0;
	for (int i = 1; i <= n - 1; i++)//Loop for passes
	{
		key = A[i];
		j = i - 1;
		//Loop for comparisons
		while (j >= 0 && A[j] > key)  //This is for ascending order, for desending A[j] < key
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;

	}
}

int main()
{
	// -1  0    1   2   3   4   5 -->indexes
	//     12,| 54, 65, 7, 23,  9 --> i=1, key =54, j=0
	//     12,| 54, 65, 7, 23,  9 --> 1st pass done (i=1)

	//     12, 54,| 65, 7, 23,  9 --> i=2, key =65, j=1
	//     12, 54,| 65, 7, 23,  9 --> 2nd pass Done (i=2)

	//     12, 54, 65,| 7, 23,  9 --> i=3, key =7, j=2
	//     12, 54, 65,| 7, 23,  9 --> i=3, key =7, j=1
	//     12, 54, 54,| 65, 23, 9 --> i=3, key =7, j=0
	//     12, 12, 54,| 65, 23, 9 --> i=3, key =7, j=-1 
	//      7, 12, 54,| 65, 23, 9 --> i=3, key =7, j=-1  3rd pass Done (i=3)


	//Fast forwarding and 4th and 5th pass will give:
	//      7, 12, 23, 54,| 65, 9 --> i=4, key =23, j=3 
	//      7, 12, 23, 54,| 65, 9 --> After the 4th pass

	//      7, 12, 23, 54, 65,| 9 --> i=5, key=9, j=4
	//      9,  7, 12, 23, 54, 65 --> After the 5th pass



	int A[] = { 12, 54, 65, 7, 23, 9 };
	int n = 6;
	cout << "Array before Sorting" << endl;
	printArray(A, n);
	insertionSort(A, n);
	cout << "Array after Sorting" << endl;
	printArray(A, n);
	return 0;
}