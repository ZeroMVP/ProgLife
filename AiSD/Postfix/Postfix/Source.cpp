#include <fstream>
#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
using namespace std;




void main(void)
{
	vector<int> stack;
	int n;
	ifstream read("input.txt");
	read >> n;
	for (int i = 0; i < n; i++)
	{
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
