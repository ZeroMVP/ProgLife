#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int *ar;
int *tos;

int norm(int left, int right, int key) {
	while (!(left >= right))
	{
		int med = (left + right) / 2;
		if (ar[left] == key) 
		{
			return left;
		}
		if (ar[med] == key)
		{
			if (med == left + 1)
				return med;
			else
				right = med + 1;
		}
		else if (ar[med] > key)
		{
			right = med;
		}
		else
		{
			left = med + 1;
		}
	}
	return -1;

}

int lefts(int index, int key)
{
	int left = 0;
	int right = index;
	int mid = index;
	while (1)
	{
		/*if ((ar[mid - 1] != key) && (ar[mid] == key))
			return mid;
		mid = (left + right) / 2;
		if(ar[mid - 1] != key) 
		{
			left = mid;
		}
		else
		{
			right = mid + 1;
		}*/

		if (ar[mid - 1] != key)
		{
			if (ar[mid] == key)
				return mid;
			mid = (left + right) / 2;
			left = mid;
		}
		else
		{
			mid = (left + right) / 2;
			right = mid + 1;
		}
	}
	return mid;
}

int rights(int index, int key)
{
	while (ar[index + 1] == key)
	{
		index++;
	}
	return index;
}

/*void main(void)
{
	int n;
	ifstream read("input.txt");
	read >> n;
	read.close();

	ofstream file;
	file.open("output.txt");
	file << 1 << ' ' << 2 << '\n';
	file << 3 << ' ' << 5 << '\n';
	file << -1 << ' ' << -1;
	file.close();

}*/
void main(void) {
	int n;
	int p;
	printf("well");

	//get data
	ifstream read("input.txt");
	read >> n;
	ar = new int[n];
	for (int i = 0; i < n; i++)
	{
		read >> ar[i];
	}
	read >> p;
	tos = new int[p];
	for (int i = 0; i < p; i++)
	{
		read >> tos[i];
	}
	read.close();

	ofstream file;
	file.open("output.txt");

	if (n == 1) 
	{
		if (ar[0] == tos[0])
		{
			file << 1 << ' ' << 1 << '\n';
		}
		else
		{
			file << -1 << ' ' << -1 << '\n';
		}
		file.close();
		return;
	}

	int left = 0;
	int right = n - 1;


	for (int i = 0; i < p; i++)
	{
		int index = norm(left, right, tos[i]);
		if (index != -1)
		{
			int righti = rights(index, tos[i]) + 1;
			file << index + 1 << ' ' << righti << '\n';
		}
		else
		{
			file << -1 << ' ' << -1 << '\n';
		}
	}

	/*int index = norm(left, right, tos[p - 1]);
	if (index != -1)
	{
		int lefti = lefts(index, tos[p - 1]) + 1;
		int righti = rights(index, tos[p - 1]) + 1;
		file << lefti << ' ' << righti;
	}
	else
	{
		file << -1 << ' ' << -1;
	}*/
	
	
	file.close();

}
