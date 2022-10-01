#include <iostream>

#include <vector>
using namespace std;

/*
루프를 돌며 index 원소의 앞부분 수열중 어느부분에 들어가면 적절할지 판단하여 삽입
정렬된 상태에 따라 속도차이가 많이난다
거의 정렬된 상태에선 굉장히 효율적인 알고리즘
O(n^2)

*/

int main(void)
{
	int a[10] = { 3,10,2,5,4,6,8,7,9,1 };
	int temp, index;
	for (int i = 1; i < 10; i++)
	{
		index = i;
		while (a[index] < a[index - 1] && index>0)
		{
			temp = a[index];
			a[index] = a[index - 1];
			a[index - 1] = temp;
			index--;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	
	
	return 0;
}