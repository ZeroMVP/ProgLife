#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int ARR_LEN;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;

}

int split(int *a, int left, int right, int x) {
	int j = left;
	for(int i = left; i < right; i++)
	{
		if (a[i] < x)
		{
			swap(&a[i], &a[j]);
			j++;
		}
	}
	return j + 1;
}

void quicksort(int *a, int left, int right)
{
	for (int i = left; i < right; i++) {
		cout << a[i];
	}
	cout << '\n';
	if (left == right)
		return;
	int x = rand() % (right - left + 1);
	int border = split(a, left, right, a[x]);
	quicksort(a, left, border - 1);
	quicksort(a, border, right);
}

int main(void) {
	int n;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n;
	ARR_LEN = n;
	int *ar = new int[n];
	for (int i = 0; i < n; i++)
	{
		read >> ar[i];
	}
	read.close();

	//insertion sort
	quicksort(ar, 0, n);
	ofstream file;
	file.open("output.txt");

	
	//write 2 file

	file << "No more swaps needed.\n";
	for (int i = 0; i < n; i++)
	{
	file << int(ar[i]);
	file << ' ';
	}
	file.close();
	return 1;
}