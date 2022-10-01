#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_heap(vector<int>);
void heapify_up(vector<int>&);
void heapify_down(vector<int> &v, int root);
void heap_sort(vector<int>&);


int main(void)
{
	vector<int> v;
	v.push_back(0);
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		v.push_back(n);
	}
	heapify_up(v);
	print_heap(v);
	cout << endl << endl;
	heap_sort(v);
	
	return 0;
}



void print_heap(vector<int> v)
{
	int n = 0;
	cout << endl << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
		if (i == pow(2, n) - 1)
		{
			cout << '\n';
			n++;
		}
	}
	cout << endl;
}


//�����
void heapify_up(vector<int>& v)
{
	int root;
	int count;

	for (int i = 2; i<v.size(); i++)
	{
		count = i;
		while (count>1)
		{
			root = count / 2;

			if (v[root] < v[count])
			{
				swap(v[root], v[count]);
				count /= 2;
			}
			else
				break;
		}

	}


}


//�����
//�ڽĳ�尡 �������������� �迭�����ʰ��� �Ͼ�� ¥����
//�ݺ����Ἥ ������ ��������
//�̷����ϸ� �θ��带 �������� �ؿ� �ڽ�2�� �����ϱ⶧���� �� ������
//�������� �ʾƵ� �ǹǷ� n/2*logn���� �Ҽ�����
//�ٵ� ������̳� ������̳� �Ȱ����ߴµ� ������� n*logn�ۿ� �����ȳ�

void heapify_down(vector<int> &v,int size)
{
	int flag, root = 1;
	while (1)
	{

		
		//�ڽĳ�尡 ����� Ȯ���ϱ����� flag (�迭�ε����ʰ� ����)
		flag = size - 2 * root;
		if (flag <= 0)
			return;
		else if (flag == 1)
		{
			if (v[root] < v[2 * root])
			{
				swap(v[root], v[2 * root]);
				root *= 2;
			}
			else
				break;
		}
		else
		{
			if (v[2 * root] < v[2 * root + 1])
			{
				if (v[root] < v[2 * root + 1])
				{
					swap(v[root], v[2 * root + 1]);
					root = root * 2 + 1;
				}
				else
					break;
			}
			else
			{
				if (v[root] < v[2 * root])
				{
					swap(v[root], v[2 * root]);
					root *= 2;
				}
				else
					break;
			}
		}
	}
}




void heap_sort(vector<int>& v)
{
	for (int size = v.size() - 1; size > 0; size--)
	{
		swap(v[1], v[size]);
		heapify_down(v, size);
		print_heap(v);
	}


}