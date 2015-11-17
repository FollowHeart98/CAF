#include "caf_shareable.h"

namespace CAF
{
	//��ʼ����Ϊ0
	CAF_Shareable::CAF_Shareable() : _count(0)
	{}

	CAF_Shareable::~CAF_Shareable()
	{
		//����Ҫ���κ���, ���Ա����ջ�Ϸ����
	}

	void CAF_Shareable::incRef()
	{
		CAF_Guard<CAF_Mutex> locker(&_mutex);
		++_count;
	}

	int32_t CAF_Shareable::decRef()
	{
		CAF_Guard<CAF_Mutex> locker(&_mutex);
		if(_count > 0)
		{ 
			--_count;
		}
		return _count;
	}

	int32_t CAF_Shareable::getCount() const
	{
		CAF_Guard<CAF_Mutex> locker(&_mutex);
		return _count;
	}
}