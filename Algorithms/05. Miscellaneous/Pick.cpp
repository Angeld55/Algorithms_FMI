// PICK finds the k-th smallest number in A[0...n-1].
// Worst-case time complexity: n.
// Worst-case memory complexity: log n.

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int ROWS = 21;  // ROWS must be an odd number greater than 5
const int MIDDLE = 11; // MIDDLE must be ROWS/2 (rounded upwards).
const int N0 = 200; // N0 must be greater than ROWS.


template <typename T>
void sort(T M[], int start, int final) 
{

	for (int i = start + 1, j; i < final; ++i, j = i) 
	{
		j = i;
		while ((j > start) && (M[j] < M[j - 1])) 
		{
			std::swap(M[j], M[j - 1]);
			--j;
		}
	}
}

template <typename T>
int partition(T arr[], int len, int splitter, bool smallerFirst) 
{
	// This algorithm is similar to Hoare's partition
	// but does not put the splitter between the two groups.
	int i = -1;
	int j = len;

	while (true)
	{

		do
		{
			++i;
		} while ((smallerFirst && arr[i] < splitter) || (!smallerFirst && arr[i] > splitter));
		do
		{
			--j;

			if (j <= i)
				return i;

		} while ((smallerFirst && arr[j] >= splitter) || (!smallerFirst && arr[j] <= splitter));

		std::swap(arr[i], arr[j]);
	}
}

template <typename T>
T PICK(T A[], int n, int k)
{
	int s, f, i, j, L1, L2;
	T M;

	while (true)
	{

		if (n < N0)
		{
			sort<T>(A, 0, n);
			return A[k - 1];
		}

		// Split the array into a table ROWS x (n / ROWS)
		// and find the median of each column:

		s = 0;
		f = ROWS;
		while (f <= n)
		{
			sort<T>(A, s, f);
			s = f;
			f += ROWS;
		}
		if (s < n)
			sort<T>(A, s, n);

		// Move the medians of the columns
		// to the beginning of the array:
		i = 0;
		j = MIDDLE;
		s = 0;
		f = ROWS;
		while (f <= n)
		{
			std::swap(A[i], A[j]);
			s = f;
			f += ROWS;
			j += ROWS;
			++i;
		}
		if (s < n)
		{
			j = (s + n - 1) >> 1;
			std::swap(A[i], A[j]);
		}

		// Find the median of the medians:
		M = PICK<T>(A, i, i >> 1);

		// Calculate the rank of M among the elements of A:
		L1 = 0;
		L2 = 0;

		for (i = 0; i < n; ++i)
		{
			if (A[i] < M)
				++L1;

			if (A[i] <= M)
				++L2;
		}

		// Check if M is the answer:
		if ((L1 < k) && (k <= L2))
			return M;

		// Erase 1/4 of the elements:
		if (k <= L1)
			n = partition(A, n, M, true); // Put the small numbers at the beginning:
		else
		{
			n = partition(A, n, M, false); // Put the big numbers at the beginning:
			k -= L2;
		}

	} // The tail recursion has been replaced with a loop.
}