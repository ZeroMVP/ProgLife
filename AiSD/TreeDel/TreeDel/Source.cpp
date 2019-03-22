#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int *kucha;
int maxi;

int gouto(int indexx, int num_versh, int key)
{
	if (kucha[indexx] == 987654)
		return (num_versh - 1);
	else if (kucha[indexx] == key)
	{	
		kucha[indexx] = 987654;
		return (num_versh - 1);
	}
	else if ((kucha[indexx + 1] == 0) && (kucha[indexx + 2] == 0))
		return num_versh;
	else if ((kucha[indexx + 1] == 0))
		return gouto((3 * kucha[indexx + 2] - 2), num_versh + 1, key);
	else if ((kucha[indexx + 2] == 0))
		return gouto((3 * kucha[indexx + 1] - 2), num_versh + 1, key);
	else
		return (num_versh + gouto((3 * kucha[indexx + 2] - 2), 1, key) + gouto((3 * kucha[indexx + 1] - 2), 1, key));

}

void search(int indexx, int key)
{
	if(kucha[indexx] == key)
	{
		kucha[indexx + 1] == 0;
		kucha[indexx + 2] == 0;
		return;
	}
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
	//tree
	for (int i = 1; i < (3 * n + 1); i++)
	{
		read >> kucha[i];
	}
	//versh
	int versh;
	read >> versh;
	int *maversh = new int[versh];
	for (int i = 0; i < versh; i++)
	{
		read >> maversh[i];
	}
	read.close();
	ofstream file;
	file.open("output.txt");
	int b = gouto(1, 1, maversh[0]);
	for (int i = 0; i < versh; i++)
	{
		int j = 0;
		for (j = 1; j <= n; j++)
		{
			//file << maversh[i] << " " << kucha[3 * j - 2] << "\n";
			if (maversh[i] == kucha[3*j - 2])
			{
				b = gouto(1, 1, maversh[i]);
				file << b;
				file << "\n";
				break;
			}
		}
		if (j > n)
		{
			file << b;
			file << "\n";
		}

	}
	/*for (int i = 1; i < (3 * n + 1); i++)
	{
	file << kucha[i];
	}*/

	file.close();

}