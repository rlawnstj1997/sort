#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>&,int ,int ,int );
void divide(vector<int>&, int, int);
vector<int> t;


//O(nlogn)
//배열을 1개가 될때까지 반으로쪼갠후 정렬하면서 다시합침

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

//start = 분할된 앞쪽 벡터의 시작
//mid = 분할된 앞쪽 벡터의 끝
//end = 분할된 뒤쪽 벡터의 끝
void merge(vector<int> &v, int start, int mid, int end)
{
	int i = start, j = mid + 1;
	int k = start;
	//비교하며 t벡터에 정렬
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
	//i와j중 남은쪽 데이터 정렬
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
	//t벡터를 v벡터로 옮김
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
