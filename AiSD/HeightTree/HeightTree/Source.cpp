#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int *kucha;
int maxi;

int gouto(int indexx, int height)
{
	if ((kucha[indexx + 1] == 0) && (kucha[indexx + 2] == 0))
		return height;
	else if ((kucha[indexx + 1] == 0))
		return gouto((3*kucha[indexx + 2] - 2), height + 1);
	else if ((kucha[indexx + 2] == 0))
		return gouto((3*kucha[indexx + 1] - 2), height + 1);
	else
		return max(gouto((3*kucha[indexx + 2] - 2), height + 1), gouto((3* kucha[indexx + 1] - 2), height + 1));

}


void main(void) {
	int n;
	printf("well");

	//get data
	ifstream read("input.txt");
	read >> n;
	if (n == 0)
	{
		read.close();
		ofstream file;
		file.open("output.txt");
		file << 0;
		file.close();
		return;
	}

	maxi = n;
	kucha = new int[3 * n + 1];
	for (int i = 1; i < (3 * n + 1); i++)
	{
		read >> kucha[i];
	}
	read.close();
	int a = gouto(1, 1);
	ofstream file;
	file.open("output.txt");
	file << a;
	/*for (int i = 1; i < (3 * n + 1); i++)
	{
		file << kucha[i];
	}*/
	
	file.close();

}