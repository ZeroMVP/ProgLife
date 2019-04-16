#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  

using namespace std;
int inv = 0;

void merge(vector<int>& arra, int left, int mid, int right, vector<int>& invn)
{
	int iter1 = 0;
	int iter2 = 0;
	vector<int> result(right - left);
	vector<int> resinv(right - left);

	while (left + iter1 < mid && mid + iter2 < right)
	{
		if (arra[left + iter1] < arra[mid + iter2])
		{
			result[iter1 + iter2] = arra[left + iter1];
			resinv[iter1 + iter2] = invn[left + iter1];
			iter1++;
		}
		else
		{
			result[iter1 + iter2] = arra[mid + iter2];
			//if (arra[left + iter1] == arra[mid + iter2])
			//	resinv[iter1 + iter2] = invn[mid + iter2] + mid - left - iter1 - 1;
			//else
			resinv[iter1 + iter2] = invn[mid + iter2] + mid - left - iter1;
			iter2++;
		}
	}

	while (left + iter1 < mid)
	{
		result[iter1 + iter2] = arra[left + iter1];
		resinv[iter1 + iter2] = invn[left + iter1];
		iter1++;
	}

	while (mid + iter2 < right)
	{
		result[iter1 + iter2] = arra[mid + iter2];
		resinv[iter1 + iter2] = invn[mid + iter2];
		iter2++;
	}

	for (int i = 0; i < iter1 + iter2; i++)
	{
		arra[left + i] = result[i];
		invn[left + i] = resinv[i];
	}


}

string mergeSort(vector<int>& arra, string data, vector<int>& invn)
{
	int n = size(arra);
	for (int i = 1; i < n; i *= 2)
		for (int j = 0; j < n - i; j += 2 * i)
		{
			int k = min(j + 2 * i, n);
			merge(arra, j, j + i, min(j + 2 * i, n), invn);
			//data += to_string(j + 1) + " " + to_string(k) + " " + to_string(arra[j]) + " " + to_string(arra[k - 1]) + "\n";
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
	vector<int> invnum(n);
	for (int i = 0; i < n; i++)
	{
		read >> arra[i];
		invnum[i] = 0;
	}
	read.close();

	//insertion sort
	ofstream file;
	//write 2 file
	file.open("output.txt");
	string data = "";
	data = mergeSort(arra, data, invnum);
	for (int i = 0; i < n; i++)
	{
		file << invnum[i] << " ";
	}
	file << "\n";
	for (int i = 0; i < n; i++)
	{
		file << arra[i] << " ";
	}
	file << "\n";
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		 a = a + invnum[i];
	}
	file << a;
	file.close();


}
