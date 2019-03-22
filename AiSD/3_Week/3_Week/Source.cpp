#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void main(void) {
	int n1, n2;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n1;
	read >> n2;
	//array create
	int *a1 = new int[n1];
	int *a2 = new int[n1];
	int all = n1 * n2;
	int *unit = new int[all];
	int *answer = new int[all];


	//read
	int max1 = -41000, max2 = -41000;

	for (int i = 0; i < n1; i++)
	{
		read >> a1[i];
		if (a1[i] > max1)
			max1 = a1[i];
	}
	for (int i = 0; i < n2; i++)
	{
		read >> a2[i];
		if (a2[i] > max1)
			max2 = a2[i];
	}

	read.close();


	//array of all elements
	int k = 0;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
		{
			unit[k] = a1[i] * a2[j];
			k++;
		}

	int numb_i = max1 * max2;
	int *numb = new int[numb_i];
	for (int i = 0; i < numb_i; numb_i++)
		numb[i] = -1;

	for (int i = 0; i < all; i++)
		numb[(unit[i])--]++;

	//array - dict
	//int **dict = new int*[2];
	//for (int i = 0; i < 2; i++)
	//	dict[i] = new int[all];

	ofstream file;
	file.open("output.txt");


	//write 2 file

	file << "No more swaps needed.\n";
	for (int i = 0; i < all; i++)
	{
		file << int(unit[i]);
		file << ' ';
	}
	file << '\n';
	for (int i = 0; i < numb_i; i++)
	{
		file << int(numb[i]);
		file << ' ';
	}
	file << 'sss';
	file.close();


}