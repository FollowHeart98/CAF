#ifndef _CAF_SHAREABLE_H_
#define _CAF_SHAREABLE_H_

#include "caf_mutex.h"
#include "caf_guard.h"

namespace CAF
{
	class CAF_Shareable
	{
	public:
		//���̳�
		virtual ~CAF_Shareable();

		void incRef();
		int32_t decRef();
		int32_t getCount() const;
		
	protected:
		//��ֹ��ʽ����, ��ͨ�����๹��
		CAF_Shareable();

	private:
		int _count;
		CAF_Mutex _mutex;
	
	private:
		//����
		CAF_Shareable(const CAF_Shareable&);
		CAF_Shareable& operator=(const CAF_Shareable&);
	};
}

#endif //
