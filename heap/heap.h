#pragma once

typedef int HDataType;
int (*Cmp)(HDataType left, HDataType right);

typedef int(*CMP)(HDataType, HDataType);
typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp;
}Heap;

int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);
void HeapInit(Heap* hp, int intitCap,CMP cmp);
void HeapCreate(Heap* hp, int* array, int size,CMP cmp);
void HeapPush(Heap* hp, HDataType data);
void HeapPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);