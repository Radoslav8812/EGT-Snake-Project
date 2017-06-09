#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int _lis(int arr[], int n, int *max_lis_length)
{
	/// Base case
	if (n == 1)
		return 1;

	int current_lis_length = 1;
	for (int i = 0; i < n - 1; i++)
	{


		int subproblem_lis_length = _lis(arr, i, max_lis_length);

		if (arr[i] < arr[n-1] && current_lis_length < (1+subproblem_lis_length))

			current_lis_length = 1+subproblem_lis_length;
	}

	if (*max_lis_length < current_lis_length)
		*max_lis_length = current_lis_length;

	return current_lis_length;
}


int lis(int arr[], int n)
{
	int max_lis_length = 1;

	_lis( arr, n, &max_lis_length );

	return max_lis_length;
}

int main()
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of Lis is %s", lis( arr, n ));
	return 0;
}
