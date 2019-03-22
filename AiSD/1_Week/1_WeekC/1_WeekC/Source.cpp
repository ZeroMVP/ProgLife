#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//5 zadanie
/*void main(void) {
	int n;
//read data
	ifstream read("input.txt");
	read >> n;
	int *slojno = new int[n];
	int *slojno_index = new int[n];
	int *Truei = new int[n];
	for (int i = 0; i < n; i++)
	{
		read >> slojno[i];
		slojno_index[i] = i + 1;
		Truei[i] = i + 1;
	}
	read.close();
//insertion sort
	ofstream file;
	file.open("output.txt");
	string vivod = "";
	string vivod2 = "";
	for (int j = 1; j < n; j++)
	{
		int i = j;
	
		//vivod = "";
		while ((i > 0) && (slojno[i - 1] > slojno[i]))
		{
			int temp = *(slojno + i - 1);
			slojno[i - 1] = *(slojno + i);
			slojno[i] = temp;
			temp = slojno_index[i - 1];
			slojno_index[i - 1] = slojno_index[i];
			slojno_index[i] = temp;
			i--;
			
		}
		
	}
	//file << vivod;
//write 2 file
	int k;
	for (int i = 0; i < n; i++)
	{
		vivod2 += to_string(slojno[i]) + " ";
		if (Truei[i] != slojno_index[i])
		{
			for (k = i + 1; Truei[k] != slojno_index[i]; k++)
			{

			}
			file << "Swap elements at indices " << to_string(i + 1) << " and " << to_string(k + 1) << ".\n";
			//file << "Swap elements at indices " << to_string(Truei[i]) << " and " << to_string(slojno_index[i]) << ".\n";
			int temp = Truei[i];
			Truei[i] = slojno_index[i];
			Truei[k] = temp;
		}
	}
	file << "No more swaps needed.\n";
	file << vivod2;
	file.close();


}*/

//3 task

/*void main(void) {
	int n;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n;
	int *slojno = new int[n];
	int *slojno_index = new int[n];
	slojno_index[0] = 1;
	for (int i = 0; i < n; i++)
		read >> slojno[i];
	read.close();

	//insertion sort
	for (int j = 1; j < n; j++)
	{
		int i = j;
		while ((i > 0) && (slojno[i - 1] > slojno[i]))
		{
			int temp = slojno[i - 1];
			slojno[i - 1] = slojno[i];
			slojno[i] = temp;
			i--;
		}
		slojno_index[j] = i + 1;
	}

	//write 2 file
	ofstream file;
	file.open("output.txt");

	for (int i = 0; i < n; i++)
	{
		file << slojno_index[i];
		file << ' ';
	}

	file << '\n';

	for (int i = 0; i < n; i++)
	{
		file << slojno[i];
		file << ' ';
	}

	file.close();
	//	scanf_s("%i", &n);


}*/

void main(void) {
	int n;
	printf("well");
//read data
	ifstream read("input.txt");
	read >> n;
	float *slojno = new float[n];
	int *slojno_index = new int[n];
	for (int i = 0; i < n; i++)
	{
		read >> slojno[i];
		slojno_index[i] = i + 1;
	}
	read.close();

//insertion sort
	for (int j = 1; j < n; j++)
	{
		int i = j;
		while ((i > 0) && (slojno[i - 1] > slojno[i]))
		{
			float temp = slojno[i - 1];
			slojno[i - 1] = slojno[i];
			slojno[i] = temp;

			temp = slojno_index[i - 1];
			slojno_index[i - 1] = slojno_index[i];
			slojno_index[i] = temp;
			i--;
		}
	}

//write 2 file
	ofstream file;
	file.open("output.txt");

	file << slojno_index[0];
	file << ' ';
	file << slojno_index[n/2];
	file << ' ';
	file << slojno_index[n - 1];
	file << ' ';
	file.close();


}
