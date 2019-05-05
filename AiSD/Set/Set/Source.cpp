#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;
map <int, set<long long>> maMap;
ofstream file("output.txt");

int getHash(long long value)
{
	return ((value % 5) + (value % 47) + (value % 1000));
} 

void callA(long long num)
{
	int a = getHash(num);

	if (maMap.find(a) == maMap.end())
	{
		set <long long> maSet;
		maSet.insert(num);
		maMap[a] = maSet;
	}
	else
	{
		maMap[a].insert(num);
	}
	
}

void callD(long long num)
{
	int a = getHash(num);
	if (maMap.find(a) != maMap.end())
	{
		maMap[a].erase(num);
	}
}

int callQ(int num)
{
	int a = getHash(num);
	if (maMap.find(a) != maMap.end())
	{
		if (maMap[a].find(num) != maMap[a].end())
		{
			return 1;
		} 
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void cMove(string s, long long num)
{
	if (s[0] == 'A')
	{
		callA(num);
	}
	else if (s[0] == 'D')
	{
		callD(num);
	}
	else if (s[0] == '?')
	{
		int a = callQ(num);
		if (a == 1)
		{
			file << "Y" << '\n';
		}
		else
		{
			file << "N" << '\n';
		}
	}
}


void main(void)
{
	ifstream read("input.txt");
	string word;
	long long num;
	int n; //start input
	read >> n;
	for (int i = 0; i < n; i++)
	{
		read >> word;
		read >> num;
		cMove(word, num);
	}
	read.close();
	file.close();

}
/*void main(void)
{
	int b;
	set <int> maSet;
	maSet.insert(2);
	map <int, set<int>> maMap;
	maMap.insert(pair<int, set<int>>(3, maSet));
	maMap.insert(pair<int, set<int>>(4, maSet));
	maMap[3].insert(3);
	maMap[5] = maSet;
	if (maMap.find(5) == maMap.end()) 
	{
		cout << "bad";
	}
	else 
	{
		cout << "is nice";
	}
	auto mySet = maMap[5];
	copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
	cin >> b;
}*/