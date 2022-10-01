#include <iostream>

#include <vector>
using namespace std;

/*
옆숫자랑 비교해서 작은값을 앞으로 보냄
O(n^2)
*/

int main(void)
{
	int a[10] = { 3,10,2,5,4,6,8,7,9,1 };
	int temp;
	for (int i = 9; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';


	return 0;
}