#include <fstream>
#include <iostream>
#include <string>
using namespace std;



void main(void) {
	int n;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n;
	int *my_stack = new int[n];
	ofstream file;
	file.open("output.txt");

	int start = 0;
	int end = 0;
	char quest;
	char plus = '+';
	for (int k = n; k > 0; k--)
	{
		read >> quest;
		if(quest == '+') 
		{
			read >> my_stack[end];
			end++;
		}
		else
		{
			file << int(my_stack[start]);
			file << '\n';
			start++;
		}
	}

	file.close();
	read.close();

}
