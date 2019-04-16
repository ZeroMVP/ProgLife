#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;



void main(void) {
	int n;
	int p;
	printf("well");

	//get data
	ifstream read("input.txt");
	read >> n;
	int value = 0;
	int new_value = 0;
	int uniq = 0;
	int *left = new int[n];
	int *right = new int[n];
	int last = 0;
	left[0] = 0;
	map <int, int> maMap;
	read >> value;
	maMap.insert(pair<int, int>(value, 0));
	int i;
	for (i = 1; i < n; i++)
	{
		read >> new_value;
		if (new_value != value)
		{
			right[uniq] = i - 1;
			uniq++;
			left[uniq] = i;
			maMap.insert(pair<int, int>(new_value, uniq));
		}
		value = new_value;
	}
	right[uniq] = i - 1;
	read >> p;

	ofstream file;
	file.open("output.txt");
	for (int i = 0; i < p; i++)
	{
		read >> value;
		auto findu = maMap.find(value);
		if (findu == maMap.end())
		{
			file << -1 << " " << -1 << "\n";
		}
		else
		{
			int fi = findu->second;
			file << (left[fi] + 1) << " " << (right[fi] + 1) << "\n";
		}
	}
	read.close();



	file.close();

}
