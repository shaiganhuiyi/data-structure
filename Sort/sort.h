#pragma once
#include<stdio.h>
#include<stack>
void Swap(int* left, int* right)
{
	*left ^= *right;
	*right ^= *left;
	*left ^= *right;
}

void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


//��������
void InsertSort(int* array, int size)
{
	for (int i = 1;i < size;i++) //O(N)
	{
		int key = array[i];
		int end = i - 1;
		//�Ҵ�����Ԫ�ص�λ��
		while (end>=0&&key<array[end])//����
		{   //���ÿ�β���Ԫ�ض���ǰ���Ѳ����Ԫ�ؼ������ţ�O��1��
			//Ŀǰ��СO(N)
			array[end + 1] = array[end];
			end--;
		}
		//����Ԫ��
		array[end + 1] = key;
	}
	//ʱ�临�Ӷ�O(N^2) �ռ临�Ӷ�0(1)  �ȶ�
}
//ϣ������
void ShellSort(int* array, int size)
{ 
	int gap = size;
	while (gap>=1)
	{
		gap = gap / 3 + 1;
		for (int i = gap;i < size;i++) 
		{
			int key = array[i];
			int end = i - gap;
			//�Ҵ�����Ԫ�ص�λ��
			while (end >= 0 && key < array[end])//����
			{

				array[end + gap] = array[end];
				end-=gap;
			}
			//����Ԫ��
			array[end + gap] = key;
		}
		
	}
	//ʱ�临�Ӷ�       �ռ临�Ӷ�O(1)   ���ȶ�
	
}

void SelectSort(int* array, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int maxPos = 0;
		for (int j = 1;j < size - i;++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}
		if (maxPos != size - i - 1)
			Swap(&array[maxPos], &array[size - i - 1]);
	}
}

void SelectSortOP(int* array, int size)
{
	int begin = 0, end = size - 1;
	while (begin < end)
	{
		//�ҵ��������СԪ�ص�λ��
		int minPos = begin;
		int maxPos = begin;
		int index = begin + 1;
		while (index <= end)
		{
			if (array[index] > array[maxPos])
				maxPos = index;
			if (array[index] < array[minPos])
				minPos = index;
			++index;
		}
		//���Ҳ�λ�ÿ��ܴ洢���ǵ�ǰ����Сֵ
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);
		//������Ҳ�λ�ÿ��ܴ洢���ǵ�ǰ����Сֵ��������������֮����Сֵλ���Ѿ������ı�
		//����Ҫ����minPos
		if (minPos == end)
			minPos = maxPos;
		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);
		++begin;
		--end;
	}
}
//������
void HeapAdjust(int* array, int size, int parent)
{
	//��Ч������ӣ���Ϊ��ʵ��������ȫ����������Ϊ��ȫ����������ֻ������û���Һ���
	int child = parent * 2 + 1;
	while (child>size)
	{
		//�ҵ��������������ĺ���
		if (child+1<size&&array[child + 1] > array[child])
			child += 1;
		//���˫���Ƿ�Ƚϴ�ĺ��Ӵ�
		if (array[child] > array[parent])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}

}
void HeapSort(int* array, int size)
{   
	int end = size - 1;
  	//1.����
	//�ҵ�����һ����Ҷ�ӽڵ�
	for (int root = (size - 2) >> 1;root >= 0;--root)
	{
		HeapAdjust(array, size, root);
	}
	//2.���ö�ɾ����˼������������
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}
void BubbleSort(int* array, int size)
{
	int flag = 1;
	int i = size - 1;
	while (flag)
	{
		flag = 0;
		for (int j = 1; j <= i; j++)
		{
			if (array[j - 1] > array[j]) {
			Swap(&array[j - 1], &array[j]);
			flag = 1;
			}
		}
		i--;
	}
}
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = (left + (right - left)) >> 1;
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] < array[right - 1])
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
	Swap(&array[MidIdex], &array[right - 1]);
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
			Swap(&array[begin], &array[end]);

	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);
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
	int prev = cur - 1;
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
		{
			Swap(&array[cur], &array[prev]);
		}
		++cur;
	}
	if (++prev != right - 1)
	{
		Swap(&array[prev], &array[right - 1]);
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
void QuickSortNor(int* array, int size)
{
	std::stack<int> s;
	s.push(size);
	s.push(0);
	int left = 0, right = 0;
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();
		if (right - left > 1)
		{
			int div = partion1(array, left, right);
			s.push(right);
			s.push(div + 1);
			s.push(div);
			s.push(left);
		}
	}
}
void Merge(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
		{
			temp[index++] = array[begin2++];
		}

	}
	while (begin1 < end1)
		temp[index++] = array[begin1++];
	while (begin2 < end2)
		temp[index++] = array[begin2++];
	
}
void MergeSort(int* array, int left, int right, int* temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		MergeSort(array, left, mid, temp);
		MergeSort(array, mid, right, temp);
		Merge(array, left, mid, right, temp);
		memcpy(array + left, temp + left, right - left);
	}
}
void TestSort()
{
	int array[] = { 4,1,8,3,0,7,2,9,5,6 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}