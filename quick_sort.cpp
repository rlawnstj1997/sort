#include <iostream>

#include <vector>
using namespace std;

void quicksort(int *a, int start, int end);

/*
분할정복을 사용
피벗(기준값ex)a[0])을 잡아 왼쪽에는 작은값을 오른쪽에는 큰값을 정렬
다정리된 피벗값은 정렬 완료로 치고 왼쪽집합과 오른쪽집합에서 
다시 각각 피벗값을 잡아 정렬이끝날때까지 반복

평균속도 Θ(N*logN)
최악의 경우 O(n^2):이미 정렬이 많이 되어있는경우 분할정복을 거의 사용하지않는다
이땐 삽입정렬이 훨씬 유리
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
		return;//원소가 1개인경우
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
		//while 문으로 구현하는게 훨씬 편할듯함
		//부등호만 바꾸면 내림차순구현도 가능
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