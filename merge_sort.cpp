#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>&,int ,int ,int );
void divide(vector<int>&, int, int);
vector<int> t;


//O(nlogn)
//�迭�� 1���� �ɶ����� �������ɰ��� �����ϸ鼭 �ٽ���ħ

int main(void)
{
	vector<int> v;
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		v.push_back(n);
		t.push_back(n);
	}
	divide(v, 0, v.size() - 1);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}

//start = ���ҵ� ���� ������ ����
//mid = ���ҵ� ���� ������ ��
//end = ���ҵ� ���� ������ ��
void merge(vector<int> &v, int start, int mid, int end)
{
	int i = start, j = mid + 1;
	int k = start;
	//���ϸ� t���Ϳ� ����
	while (i <= mid&&j <= end)
	{
		if (v[i] <= v[j])
		{
			t[k] = v[i];
			i++;
		}
		else
		{
			t[k] = v[j];
			j++;
		}
		k++;
	}
	//i��j�� ������ ������ ����
	if (i > mid)
	{
		while (j <= end)
		{
			t[k] = v[j];
			j++;
			k++;
		}
	}
	if (j > end)
	{
		while (i <= mid)
		{
			t[k] = v[i];
			i++;
			k++;
		}
	}
	//t���͸� v���ͷ� �ű�
	for (; start <= end; start++)
	{
		v[start] = t[start];

	}

}


void divide(vector<int> &v, int start, int end)
{
	if (start >= end)
		return;
	else
	{
		int mid = (start + end ) / 2;
		divide(v, start, mid);
		divide(v, mid + 1, end);
		merge(v, start, mid, end);
	}

}
