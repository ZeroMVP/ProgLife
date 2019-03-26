#include <fstream>
#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
using namespace std;




void main(void)
{
	vector<int> tree;
	int n;
	int a;
	ifstream read("input.txt");
	read >> n;
	for (int i = 0; i < n; i++)
	{
		read >> a;
		tree.insert(tree.begin(), a);
		read >> a;
		tree.insert(tree.begin(), a);
		read >> a;
		tree.insert(tree.begin(), a);
	}
	tree.insert(tree.begin(), 0);
	for (int i = 1; i < n; i = i + 3)
	{

	}
		string symbol;
		read >> symbol;
		if (symbol == "+")
		{
			int a = stack[0];
			int b = stack[1];
			a = a + b;
			stack.erase(stack.begin());
			stack.erase(stack.begin());
			stack.insert(stack.begin(), a);
		}
		else if (symbol == "-")
		{
			int a = stack[0];
			int b = stack[1];
			a = b - a;
			stack.erase(stack.begin());
			stack.erase(stack.begin());
			stack.insert(stack.begin(), a);
		}
		else if (symbol == "*")
		{
			int a = stack[0];
			int b = stack[1];
			a = a * b;
			stack.erase(stack.begin());
			stack.erase(stack.begin());
			stack.insert(stack.begin(), a);
		}
		else if (symbol == "/")
		{
			int a = stack[0];
			int b = stack[1];
			a = b / a;
			stack.erase(stack.begin());
			stack.erase(stack.begin());
			stack.insert(stack.begin(), a);
		}
		else
		{
			int symbyl = stoi(symbol);
			stack.insert(stack.begin(), symbyl);
		}
	}
	read.close();
	ofstream file("output.txt");
	file << stack[0];
	file.close();
}