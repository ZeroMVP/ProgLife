#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int* prefix(string s) {
	int len = s.length();
	int *ar = new int[len];
	ar[0] = 0;
	for (int i = 1; i < (len - 1); ++i)
	{
		int k = ar[i - 1];
		while ((k > 0) && (s[i] != s[k]))
		{
			k = ar[k - 1];
		}

		if (s[i] == s[k])
		{
			k++;
		}
		ar[i] = k;
	}
	return ar;
}


void main(void)
{
	ifstream read("input.txt");
	string s;
	string ss;
	char data;
	while (!read.eof())
	{
		read >> data;
		s += data;
	}
	int *b = prefix(s);
	for (int i = 0; i < (s.length()- 1); i++)
	{
		ss += to_string(b[i]);
	    ss += " ";
	}
	read.close();
	ofstream file;
	file.open("output.txt");
	file << ss;
	file.close();
}



/*#include <fstream>
#include <iostream>
#include <string>
using namespace std;



int* prefix(string s) {
	int len = s.length();
	int *ar = new int[len];
	ar[0] = 0;
	for (int i = 1; i < (len); ++i)
	{
		int k = ar[i - 1];
		while ((k > 0) && (s[i] != s[k]))
		{
			k = ar[k - 1];
		}

		if (s[i] == s[k])
		{
			k++;
		}
		ar[i] = k;
	}
	return ar;
}


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
}*/


