#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*ifstream read("input.txt");
ofstream file;
file.open("output.txt");

void line_check() {
	int end = 1;
	int flag = 1;
	while (read.get(quest))
	{
		if (quest == '\n')  // If the file has been opened in
		{
			break;        // text mode then it will correctly decode the
		}
		if (quest == '(')
		{
			my_stack[end] = '(';
			end++;
		}
		else if (quest == '[')
		{
			my_stack[end] = '[';
			end++;
		}
		else
		{
			end--;
			if ((quest == ']') && (my_stack[end] == '['))
			{
				my_stack[end] = '1';
			}
			else if ((quest == ')') && (my_stack[end] == '('))
			{
				my_stack[end] = '1';
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag == 0)
	{
		file << "NO";
		file << '\n';
	}
	else
	{
		file << "YES";
		file << '\n';
	}
}

char *my_stack = new char[10000];

int main(void) {
	int n;
	printf("well");
	//read data
	ifstream read("input.txt");
	//read.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	read >> n;
	ofstream file;
	file.open("output.txt");
	int start = 0;
	int end = 0;
	my_stack[end] = '2';
	char quest = '1';
	char plus = '+';
	read.get(quest);
	for (int i = 0; i < n; i++)
	{
		
	}
	file.close();
	read.close();

	return 1;
}*/
int check(string s)
{
	int flag = 0;
	int n = s.length();
	int stackLen = 0;
	vector<int> stack(n);
	char b = s[0];
	if ((b != '(') && (b != '['))
		return 0;
	for (int i = 0; i < n; i++)
	{
		char a = s[i];
		if (a == '(')
		{
			stack[stackLen] = 1;
			stackLen++;
		}
		else if (a == '[')
		{
			stack[stackLen] = 2;
			stackLen++;
		}
		else if ((a == ')') && (stack[stackLen - 1] == 1))
		{
			stack[stackLen - 1] = 0;
			stackLen--;
		}
		else if ((a == ']') && (stack[stackLen - 1] == 2))
		{
			stack[stackLen - 1] = 0;
			stackLen--;
		}
		else
			return 0;

	}
	if (stackLen == 0)
		return 1;
	else
		return 0;
}


void main(void) 
{
	ifstream read("input.txt");
	int n; //start input
	string s; //2 work with posl
	string buff;
	read >> n;
	vector<string> posled(n + 1);
	int i = 0;
	while (getline(read, buff))
	{
		posled[i] = buff;
		i++;
	}
	read.close();
	ofstream file("output.txt");
	for (i = 1; i < n + 1; i++)
	{
		int a = check(posled[i]);
		if (a == 1)
			file << "YES" << '\n';
		else
			file << "NO" << '\n';
	}
	file.close();

}