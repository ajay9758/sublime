// A Dynamic Programming based C++ program to find the
// number of times the second string occurs in the first
// string, whether continuous or discontinuous
#include <iostream>
using namespace std;

int count(string a, string b)
{
	int m = a.length();
	int n = b.length();

	int lookup[m + 1][n + 1] = { { 0 } };

	// If first string is empty
	for (int i = 0; i <= n; ++i)
		lookup[0][i] = 0;

	// If second string is empty
	for (int i = 0; i <= m; ++i)
		lookup[i][0] = 1;


	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{

			if (a[i - 1] == b[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + lookup[i - 1][j];
				
			else
				lookup[i][j] = lookup[i - 1][j];
		}
	}
	return lookup[m][n];
}


int main()
{
	string a = "QAQAQYSYIOIWIN";
	string b = "QAQ";

	cout << count(a, b);

	return 0;
}
