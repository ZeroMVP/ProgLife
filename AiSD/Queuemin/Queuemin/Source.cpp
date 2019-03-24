#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>  

using namespace std;


#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool condition(int a, int b)
{
	if (a <= b)
		return 1;
	else
		return 0;
}

void main(void) {
	int n;
	printf("well");
	//read data
	ifstream read("input.txt");
	read >> n;
	vector<int> my_stack;
	vector<int> my_min = {1000000000};
	ofstream file;
	file.open("output.txt");

	
	char quest;
	char plus = '+';
	for (int k = n; k > 0; k--)
	{
		read >> quest;
		if (quest == '+')
		{
			int t;
			int j;
			read >> t;
			my_stack.push_back(t);
			auto result1 = find_if(my_min.begin(), my_min.end(), );
			/*for(j = 0; j < my_min.size(); j++)
			{
				if (t < my_min[j])
				{
					my_min.insert(my_min.begin() + j, t);
					break;
				}
			}
			if (j == my_min.size())
				my_min.push_back(t);*/

		}
		else if (quest == '?')
		{
			file << my_min[0];
			file << "\n";
		}
		else
		{
			int value = my_stack[0];
			my_stack.erase(my_stack.begin());
			vector<int>::iterator iter = std::find(my_min.begin(), my_min.end(), value);
			if (iter != my_min.end())
				my_min.erase(iter);
			//auto it = find(my_min.begin(), my_min.end(), value);
			//if(it != my_stack.end())
			//	my_min.erase(it);
			//my_min.erase(remove(my_min.begin(), my_min.end(), value), my_min.end());
			//my_min.erase(find(my_min.begin(), my_min.end(), 20));
			/*for (int j = 0; j < my_min.size(); j++)
			{
				if (value == my_min[j])
				{
					my_min.erase(my_min.begin() + j);
					break;
				}
			}*/

		}
	}
	for (int i = 0; i < my_min.size(); i++)
		cout << my_min[i];
	int yello;
	//cin >> yello;
	file.close();
	read.close();

}

/*void main(void) {
	vector<int> vec = { 10,20,20,20,30 };
	auto it = vec;
	vec.insert(vec.begin() + 2, 55);
	vec.push_back(15);
	vec.erase(vec.begin() + 2);
	/*vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 20);
	if (iter != vec.end())
		vec.erase(iter);*/
	/*int a = vec.size();
	vec.erase(remove(vec.begin(), vec.end(), 20), vec.end());
	int b = vec.size();
	for (int i = 0; i < b - a; i++)
	{
		vec.insert(it, 20);
	}*/
	//for (int i = 0; i < vec.size(); i++)
	//	cout << vec[i];
	//int a;
	//cin >> a;
//}*/
