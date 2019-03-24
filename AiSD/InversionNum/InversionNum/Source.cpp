#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  

using namespace std;

void merge(vector<int>& arra, int left, int mid, int right)
{
	int iter1 = 0;
	int iter2 = 0;
	vector<int> result(right - left);


	while (left + iter1 < mid && mid + iter2 < right)
	{
		if (arra[left + iter1] < arra[mid + iter2])
		{
			result[iter1 + iter2] = arra[left + iter1];
			iter1++;
		}
		else
		{
			result[iter1 + iter2] = arra[mid + iter2];
			iter2++;
		}
	}

	while (left + iter1 < mid)
	{
		result[iter1 + iter2] = arra[left + iter1];
		iter1++;
	}

	while (mid + iter2 < right)
	{
		result[iter1 + iter2] = arra[mid + iter2];
		iter2++;
	}

	for (int i = 0; i < iter1 + iter2; i++)
		arra[left + i] = result[i];


}

string mergeSort(vector<int>& arra, string data)
{
	int n = size(arra);
	for (int i = 1; i < n; i *= 2)
		for (int j = 0; j < n - i; j += 2 * i)
		{
			int k = min(j + 2 * i, n);
			merge(arra, j, j + i, min(j + 2 * i, n));
			data += to_string(j + 1) + " " + to_string(k) + " " + to_string(arra[j]) + " " + to_string(arra[k - 1]) + "\n";
		}
	return data;
}


void main(void) {
	int n;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n;
	vector<int> arra(n);
	for (int i = 0; i < n; i++)
	{
		read >> arra[i];
	}
	read.close();

	//insertion sort
	ofstream file;
	//write 2 file
	file.open("output.txt");
	string data = "";
	data = mergeSort(arra, data);
	file << data;
	for (int i = 0; i < n; i++)
	{
		file << arra[i] << " ";
	}
	file.close();


}
