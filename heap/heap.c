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
//初始化一个堆
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
	hp->Cmp = cmp; //接收比较方式

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
//堆的向上调整算法
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
//用数组中的元素创建堆
void HeapCreate(Heap* hp, int* array, int size,CMP cmp)
{
	//1.先将数组中的元素放在堆结构中
	HeapInit(hp, size,cmp);
	memcpy(hp->array, array, sizeof(HDataType)* size);
	hp->size = size;
	//2.进行调整
	for (int root = (size - 2) / 2; root >= 0;root--)
		AdjustDown(hp, root);
}
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//1.开辟新空间
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType) * newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//2.拷贝元素
		//memcpy(temp, hp->array, hp->size * sizeof(HDataType));
		for (int i = 0;i < hp->size;i++)
			temp[i] = hp->array[i];
		//3.释放旧空间
		free(hp->array);
		//4.使用新空间
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
//插入一个新元素
void HeapPush(Heap* hp, HDataType data)
{
	assert(hp);
	//1.检测是否需要扩容
	CheckCapacity(hp);
	//2.将新元素插入到数组的末尾，即:将新元素插入到完全二叉树的最后
	hp->array[hp->size++] = data;
	//3.将新元素插入后，可能会破坏堆的性质
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

//获取堆顶元素
HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}
int HeapEmpty(Heap* hp)  //堆为空返回非0值
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


//堆的向下调整算法(小堆） 需要左右子树必须为小堆
//时间复杂度（log2(n))
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