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


//상향식
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


//하향식
//자식노드가 꽉차있지않으면 배열범위초과가 일어나서 짜증남
//반복문써서 끝까지 내려야함
//이렇게하면 부모노드를 기준으로 밑에 자식2을 조사하기때문에 맨 끝단은
//조사하지 않아도 되므로 n/2*logn으로 할수있음
//근데 상향식이나 하향식이나 똑같다했는데 상향식은 n*logn밖에 생각안남

void heapify_down(vector<int> &v,int size)
{
	int flag, root = 1;
	while (1)
	{

		
		//자식노드가 몇개인지 확인하기위한 flag (배열인덱스초과 방지)
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