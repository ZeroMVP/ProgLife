#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>

using namespace std;





void main(void)
{
	ifstream read("input.txt");
	string toFind; //2 work with posl
	string maStroke;
	string answer;
	int i = 0;
	getline(read, toFind);
	getline(read, maStroke);
	read.close();

	ofstream file("output.txt");
	for (i = 0; i < maStroke.length(); i++)
	{
		int k = i;
		int j;
		for (j = 0; j < toFind.length(); j++)
		{
			if (maStroke[k] != toFind[j]) 
			{
				break;
			}
			k++;
		}
		if (j == (toFind.length()))
			answer = answer + to_string(k - toFind.length() + 1) + " ";
	}
	stringstream iss(answer);
	int number;
	std::vector<int> myNumbers;
	while (iss >> number)
		myNumbers.push_back(number);
	sort(myNumbers.begin(), myNumbers.end());
	file << myNumbers.size();
	file << "\n";
	for (int q : myNumbers)
	{
		file << q;
		file << " ";
	}
	file.close();

}
