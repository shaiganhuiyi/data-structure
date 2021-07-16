#pragma once
#include<vector>
#include<assert.h>
namespace BS
{
	template<size_t N>
	
	class bitset
	{
	public:
		biteste()
			:_bs(N / 8 + 1)//N/8+1��ʾN������λ��Ҫ���ٸ��ֽ�
		{}
		//��pos�ı���λ��1
		void set(size_t pos)
		{
			assert(pos < N);
			//�ֽ�λ��
			size_t whichByte = pos / 8;

			//����λ��
			size_t whichBit = pos % 8;

			_bs[whichByte] != (1 << whichBit);
			++_conut;
		}
		//��pos�ı���λ��0
		void reset(size_t pos)
		{
			assert(pos < N);
			//�ֽ�λ��
			size_t whichByte = pos / 8;

			//����λ��
			size_t whichBit = pos % 8;

			_bs[whichByte] &= ~(1 << whichBit);
		    --_conut;
		}
		//���posλ�õı���λ�Ƿ�Ϊ1
		bool test(size_t pos)
		{
			assert(pos < N);
			//�ֽ�λ��
			size_t whichByte = pos / 8;

			//����λ��
			size_t whichBit = pos % 8;
			return 0!= _bs[whichByte] & (1 << whichBit);
		}
		//Ϊ1�ı���λ������
		size_t count()const
		{
			return _count;
		}
		//����λ������
		size_t size()const
		{
			return N;
		}

	private:
		std::Vector<char> _bs;
		size_t _count; //��ʾΪ1�ı���λ������
	};

}