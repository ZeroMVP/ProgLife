#include <fstream>
#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
using namespace std;



//int *tr;
int flag = 0;
vector<int> tr;

void check(int ind, int min, int max)
{
	int value = tr[ind];
	if (value == 0)
	{
		return;
	}
	if ((value < min) || (value > max))
	{
		flag = 1;
		return;
	}
	else
	{
		int a = tr[ind + 1];
		int b = tr[ind + 2];
		if (a != 0)
		{
			check((3 * a - 2), min, value);
		}
		if (b != 0)
		{
			check((3 * b - 2), value, max);
		}
		return;
	}
}


/*
void main(void)
{
	ifstream read("input.txt");
	string s;
	string ss;
	string answer;
	int num = 0;
	char data;
	getline(read, s);
	getline(read, ss);
	int s_len = s.length();
	s += "#";
	s += ss;
	int *b = prefix(s);
	for (int i = 0; i < (s.length()); i++)
	{
	if (b[i] == s_len)
	{
	num++;
	answer += to_string(i - 2 * s_len + 1);
	answer += " ";
	}

	}
	read.close();
	ofstream file;
	file.open("output.txt");
	file << to_string(num);
	file << "\n";
	file << answer;
	file.close();
}
*/

void main(void)
{
	int n;
	int a;
	ifstream read("input.txt");
	read >> n;
	if (n == 0)
	{
		ofstream file("output.txt");
		file << "YES";
		file.close();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		read >> a;
		tr.insert(tr.end(), a);
		read >> a;
		tr.insert(tr.end(), a);
		read >> a;
		tr.insert(tr.end(), a);
	}
	tr.insert(tr.begin(), 0);
	//tr[0] = 0;
	check(1, -99999999999, 100000000000);
	read.close();
	ofstream file("output.txt");
	if (flag == 0)
	{
		file << "YES";
	}
	else
	{
		file << "NO";
	}
	file.close();
}