#include "heap.h"
#include<malloc.h>
#include<assert.h>
#include<string.h>

int Less(HDataType left, HDataType right)
{
	return left < right;
}

int Greater(HDataType left, HDataType right)
{
	return left > right;
}
//��ʼ��һ����
void HeapInit(Heap* hp, int intitCap,CMP cmp)
{
	assert(hp);
	intitCap = intitCap < 10 ? 10 : intitCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType) * intitCap);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = intitCap;
	hp->size = 0;
	hp->Cmp = cmp; //���ձȽϷ�ʽ

}
void AdjustDown(Heap* hp, int parent)
{
	int size = hp->size;
	int* array = hp->array;
	int child = parent * 2 + 1;
	
	while (child<size)
	{
		if (child + 1 < size && hp->Cmp(array[child],array[child + 1]))
			child += 1;
		if (hp->Cmp(array[parent],array[child]))
		{
			swap(array[parent], array[child]);
				 parent=child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//�ѵ����ϵ����㷨
void AdjustUp(Heap* hp, int child)
{   
	int size = hp->size;
	HDataType* array = hp->array;
	int parent = ((child - 1) >> 1);
	while (child)
	{
		if (hp->Cmp(array[child] , array[parent]))
		{
			swap(array[child], array[parent]);
			
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		{
			return;
		}
	}
}
//�������е�Ԫ�ش�����
void HeapCreate(Heap* hp, int* array, int size,CMP cmp)
{
	//1.�Ƚ������е�Ԫ�ط��ڶѽṹ��
	HeapInit(hp, size,cmp);
	memcpy(hp->array, array, sizeof(HDataType)* size);
	hp->size = size;
	//2.���е���
	for (int root = (size - 2) / 2; root >= 0;root--)
		AdjustDown(hp, root);
}
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//1.�����¿ռ�
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType) * newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//2.����Ԫ��
		//memcpy(temp, hp->array, hp->size * sizeof(HDataType));
		for (int i = 0;i < hp->size;i++)
			temp[i] = hp->array[i];
		//3.�ͷžɿռ�
		free(hp->array);
		//4.ʹ���¿ռ�
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
//����һ����Ԫ��
void HeapPush(Heap* hp, HDataType data)
{
	assert(hp);
	//1.����Ƿ���Ҫ����
	CheckCapacity(hp);
	//2.����Ԫ�ز��뵽�����ĩβ����:����Ԫ�ز��뵽��ȫ�����������
	hp->array[hp->size++] = data;
	//3.����Ԫ�ز���󣬿��ܻ��ƻ��ѵ�����
	AdjustUp(hp, hp->size - 1);
}
void HeapPop(Heap* hp)
{
	if (!HeapEmpty(hp))
		return;
	swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp, 0);

}

//��ȡ�Ѷ�Ԫ��
HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}
int HeapEmpty(Heap* hp)  //��Ϊ�շ��ط�0ֵ
{
	assert(hp);
	return 0 == hp->size;
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void HeapDestroy(Heap* hp);
{
	assert(hp);
	free(hp->array);
	HeapPop->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}


//�ѵ����µ����㷨(С�ѣ� ��Ҫ������������ΪС��
//ʱ�临�Ӷȣ�log2(n))
int Heap(int array[],int size)
{


	int parent =  array[0];
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child] > array[child + 1])
			child += 1;
		if (array[parent] > array[child])
		{
			swap(array[parent],array[child]);

			parent = child;
			child = parent * 2 + 1;
		}
		else 
			return;

	}
}