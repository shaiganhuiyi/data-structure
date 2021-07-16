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
			:_bs(N / 8 + 1)//N/8+1表示N个比特位需要多少歌字节
		{}
		//将pos的比特位置1
		void set(size_t pos)
		{
			assert(pos < N);
			//字节位置
			size_t whichByte = pos / 8;

			//比特位置
			size_t whichBit = pos % 8;

			_bs[whichByte] != (1 << whichBit);
			++_conut;
		}
		//将pos的比特位置0
		void reset(size_t pos)
		{
			assert(pos < N);
			//字节位置
			size_t whichByte = pos / 8;

			//比特位置
			size_t whichBit = pos % 8;

			_bs[whichByte] &= ~(1 << whichBit);
		    --_conut;
		}
		//检测pos位置的比特位是否为1
		bool test(size_t pos)
		{
			assert(pos < N);
			//字节位置
			size_t whichByte = pos / 8;

			//比特位置
			size_t whichBit = pos % 8;
			return 0!= _bs[whichByte] & (1 << whichBit);
		}
		//为1的比特位的总数
		size_t count()const
		{
			return _count;
		}
		//比特位的总数
		size_t size()const
		{
			return N;
		}

	private:
		std::Vector<char> _bs;
		size_t _count; //表示为1的比特位的总数
	};

}