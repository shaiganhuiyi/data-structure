#include<stdio.h>
#include<stack>
using namespace std;
void swap(int& left, int& right)
{
	left ^= right;
	right ^= left;
	left ^= right;
}
void InsertSort(int array[], int curr)
{

}
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = (left + (right - left)) >> 1;
	if (array[left] < array[right-1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] < array[right-1])
			return mid;
		else  
			return  right - 1;
		
	}
	else
	{
		if (array[mid] < array[right - 1])
			return right - 1;
		else if (array[mid] < array[left])
			return left;
		else 
			return mid;

	
	}
}
//hoare�汾
int partion1(int array[], int left, int right)
{
	int MidIdex = GetMiddleIndex(array, left, right);
	swap(array[MidIdex], array[right - 1]);
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
		swap(array[begin], array[end]);

	}
	 if(begin !=right-1)
	swap(array[begin], array[right - 1]);
	 return begin;
}
int partion2(int array[], int left, int right)//�ڿӷ�
{
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{   //��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}
	    //��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ��
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
		{
			array[begin] = array[end];
			array++;
		}
	}
	array[begin] = key;
	return begin;
}
int partion3(int array[], int left, int right)//ǰ��ָ��
{
	int key = array[right - 1];
	int cur = left;
	int prev = cur-1;
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
		{
			swap(array[cur], array[prev]);
		}
		++cur;
	}
	if (++prev != right - 1)
	{
		swap(array[prev], array[right - 1]);
	}
	return prev;
}
void QuickSort(int array[], int left, int right)
{
	if (right - left < 16)
	{
		InsertSort(array + left, right - left);
	}
	else
	 {
		int  div = partion1(array, left, right);
		QuickSort(array, left, div);//�ݹ��׼ֵ�����
		QuickSort(array, div + 1, right);//�ݹ��׼ֵ���Ҳ�
	}
}
//�����汾�Ŀ��Ž���ջ���
void QuickSort(int array[], int size)
{
	stack<int> s;
	s.push(size);
	s.push(0);
	while (!s.empty())
	{
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();
		if (right - left > 1)
		{
			int div = partion1(array, left, right);
			//[div+1,right)
			s.push(right);
			s.push(div + 1);
			//[left,div)
			s.push(div);
			s.push(left);

		}
	}
}
void MergeSort(int array[], int left, int right, int* temp)
{

}