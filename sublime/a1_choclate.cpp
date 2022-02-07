#include <bits/stdc++.h>
using namespace std;
// arr[0..n-1] represents sizes of packets m is number of students.
// Returns minimum difference between maximum and minimum values of distribution.


int findMinDiff(int arr[], int n, int m)
{
	if (m == 0 || n == 0)
		return 0;

	sort(arr, arr + n );

	if (n < m)
		return -1;

	int diff = INT_MAX;

	for (int i = 0; i < n-m+1; i++) {

		diff = min(diff,arr[i + m - 1] - arr[i]);
		
	}
	return diff;
}

int main()
{
	int arr[] = { 12, 4, 7, 9, 2, 23, 25, 41, 30,40, 28, 42, 30, 44, 48, 43, 50 };
	int m = 7; // Number of students
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Minimum difference is "
		<< findMinDiff(arr, n, m);
	return 0;
}
