#include<bitset>
#include<iostream>
using namespace std;
void TestBitSet()
{
	int array[] = { 1,2,21,33,44,88,10 };
	bitset<100>bs;
	//将集合中的数据向位图中进行映射
	for (auto e : array)
		bs.set(e);//置1
	cout << bs.count() << endl;
	cout << bs.size() << endl;
	if (bs.test(33))
		cout << "33 is in bitset" << endl;
	else
		cout << "33 is not in bitset" << endl;
	//置0
	bs.reset(33);
	
}
int main()
{
	TestBitSet();
	return 0;
}