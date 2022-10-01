#include <iostream>

#include <vector>
using namespace std;

void quicksort(int *a, int start, int end);

/*
���������� ���
�ǹ�(���ذ�ex)a[0])�� ��� ���ʿ��� �������� �����ʿ��� ū���� ����
�������� �ǹ����� ���� �Ϸ�� ġ�� �������հ� ���������տ��� 
�ٽ� ���� �ǹ����� ��� �����̳��������� �ݺ�

��ռӵ� ��(N*logN)
�־��� ��� O(n^2):�̹� ������ ���� �Ǿ��ִ°�� ���������� ���� ��������ʴ´�
�̶� ���������� �ξ� ����
*/

int main(void)
{
	int a[10] = { 1,3,5,6,8,9,10,4,7,2 };
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	quicksort(a, 0, 9);
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	
	return 0;
}

void quicksort(int *a,int start,int end)
{
	if (start >= end)
		return;//���Ұ� 1���ΰ��
	int i, j, temp;
	while (1)
	{
		for (i = start + 1; i <= end; i++)
		{
			if (a[start] <= a[i])
				break;
			if (i == end)
				i++;

		}
		//while ������ �����ϴ°� �ξ� ���ҵ���
		//�ε�ȣ�� �ٲٸ� �������������� ����
		for (j = end; j >= start; j--)
		{
			if (a[start] >= a[j])
				break;
		}
		if (j < i)
		{
			temp = a[start];
			a[start] = a[j];
			a[j] = temp;
			break;
		}
		else
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}

	}
	quicksort(a, start, j - 1);
	quicksort(a, j + 1, end);

}