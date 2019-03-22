#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int *kucha;

int norm(int index, int size) {
	if (index >= size)
		return 1;
	if ((index * 2 + 1) <= size) {
		if ((kucha[index] <= kucha[2 * index]) && (kucha[index] <= kucha[2 * index + 1]))
			return 1;
		else
			return 0;
	}
	else if ((index * 2) <= size)
	{
		if (kucha[index] <= kucha[2 * index])
			return 1;
		else
			return 0;
	}
	return 1;
}


void main(void) {
	int n;
	printf("well");

	//get data
	ifstream read("input.txt");
	read >> n;
    kucha = new int[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		read >> kucha[i];
	}
	read.close();

	ofstream file;
	file.open("output.txt");
	int flag = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (norm(i, n) == 0)
		{
			file << "NO";
			flag = 1;
			break;
		}
		
	}
	if (flag == 0)
	{
		file << "YES";
	}
	file.close();

}
