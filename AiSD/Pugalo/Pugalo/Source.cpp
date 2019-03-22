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

void mergeSort(vector<int>& arra)
{
	int n = size(arra);
	for (int i = 1; i < n; i *= 2)
		for (int j = 0; j < n - i; j += 2 * i)
		{
			int k = min(j + 2 * i, n);
			merge(arra, j, j + i, min(j + 2 * i, n));
		}
}


void main(void) {
	int n;
	int step;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n;
	read >> step;
	vector<int> arra(n);
	for (int i = 0; i < n; i++)
	{
		read >> arra[i];
	}
	read.close();

	ofstream file;
	//write 2 file
	file.open("output.txt");
	for (int i = 0; i < step; i++)
	{
		int new_size = 0;
		for (int j = i; j < n; j = j + step)
		{
			new_size++;
		}

		vector<int> new_arra(new_size);
		int temp = 0;
		for (int j = i; j < n; j = j + step)
		{
			new_arra[temp] = arra[j];
			temp++;
		}
		
		mergeSort(new_arra);

		temp = 0;
		for (int j = i; j < n; j = j + step)
		{
			arra[j] = new_arra[temp];
			temp++;
		}
	}

	//insertion sort
	string data = "";
	//data = mergeSort(arra, data);
	//file << data;
	int flag = 0;
	for (int i = 1; i < n; i++)
	{
		if (arra[i - 1] > arra[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		file << "NO";
	else
		file << "YES";
	file.close();


}
