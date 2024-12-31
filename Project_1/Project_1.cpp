#include <iostream>
#include <string>
#include "SimpleVector.h"

using namespace std;



int main()
{
	SimpleVector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i * 2);

	vec.push_back(3);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

}
