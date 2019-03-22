#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int * MergeSort(int * ar, int left, int right) {
	int n = right - left + 1;
	if (n == 1) {
		return ar;
	}
	int * a = MergeSort(ar, left, left + int(n / 2));
	int * b = MergeSort(ar + int(n / 2) + 1, left + int(n / 2) + 1, right);
	return merge(a, b,)
}

int * merge(int *a, int *b, int len1, int len2) {
	int i = 0;
	int j = 0;
	int *c = new int[len1 + len2];
	while (i < len1 || j < len2) 
	{
		if (j == len2 || (i < len1 and (a[i] < b[j])))
		{
			c[i + j] = a[i];
			i++;
		}
		else
		{
			c[i + j] = b[j];
			j++;
		}
	}
	return c
}

 int main(void) {
	int n;
	printf("well");
	//read data
	cin >> n;
	int *q = new int[n];
	cout << (sizeof(q) / sizeof(*q));
	cin >> n;
	/*ifstream read("input.txt");
	read >> n;
	float *slojno = new float[n];
	int *slojno_index = new int[n];
	for (int i = 0; i < n; i++)
	{
		read >> slojno[i];
		slojno_index[i] = i + 1;
	}
	read.close();

	//insertion sort
	ofstream file;
	file.open("output.txt");

	for (int j = 1; j < n; j++)
	{
		int i = j;
		int start = i;
		while ((i > 0) && (slojno[i - 1] > slojno[i]))
		{
			int temp = slojno[i - 1];
			slojno[i - 1] = slojno[i];
			slojno[i] = temp;
			i--;


		}
		if (i != start)
			file << "Swap elements at indices " << i + 1 << " and " << start + 1 << ".\n";
	}

	//write 2 file

	file << "No more swaps needed.\n";
	for (int i = 0; i < n; i++)
	{
		file << int(slojno[i]);
		file << ' ';
	}
	file.close();
	*/

}