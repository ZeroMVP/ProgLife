#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	printf("well");
	//read data
	cin >> n;
	int *q = new int[n];
	cout << (sizeof(q) / sizeof(*q));
	cin >> n;
	/*ifstream read("input.txt");
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
	ofstream file;
	file.open("output.txt");

	for (int j = 1; j < n; j++)
	{
	int i = j;
	int start = i;
	while ((i > 0) && (slojno[i - 1] > slojno[i]))
	{
	int temp = slojno[i - 1];
	slojno[i - 1] = slojno[i];
	slojno[i] = temp;
	i--;


	}
	if (i != start)
	file << "Swap elements at indices " << i + 1 << " and " << start + 1 << ".\n";
	}

	//write 2 file

	file << "No more swaps needed.\n";
	for (int i = 0; i < n; i++)
	{
	file << int(slojno[i]);
	file << ' ';
	}
	file.close();
	*/

}