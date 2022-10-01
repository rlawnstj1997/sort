#include <iostream>

#include <vector>
using namespace std;

/*
������ ���� index ������ �պκ� ������ ����κп� ���� �������� �Ǵ��Ͽ� ����
���ĵ� ���¿� ���� �ӵ����̰� ���̳���
���� ���ĵ� ���¿��� ������ ȿ������ �˰���
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