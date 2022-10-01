#include <iostream>

#include <vector>
using namespace std;


/*
순회하며 가장 작은숫자를 선택하여 앞으로 뺌
O(n^2) 
*/
int main(void)
{
	int a[10] = { 3,10,2,5,4,6,8,7,9,1 };
	int temp, index;
	int min;

	for (int i = 0; i < 10; i++)
	{
		min = 11;
		for (int j = i; j < 10; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				index = j;
			}
		}
		temp = min;
		a[index] = a[i];
		a[i] = min;
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';


	return 0;
}
