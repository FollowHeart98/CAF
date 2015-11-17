#ifndef _CAF_MUTEX_H_
#define _CAF_MUTEX_H_

#include "caf_common.h"
#include "caf_time.h"

namespace CAF
{ 
	/*
		ʵ���̼߳以�����
	*/
	class CAF_Mutex
	{
	public:
		CAF_Mutex();

		//************************************
		// Method:    ����
		// FullName:  CAF::CAF_Mutex::~CAF_Mutex
		// Access:    public
		// Returns:   
		// Qualifier: 
		//************************************
		~CAF_Mutex();

		//************************************
		// Method:    ����
		// FullName:  CAF::CAF_Mutex::lock
		// Access:    public 
		// Returns:   int32_t �ɹ�����0�� ʧ�ܷ��ش�����
		// Qualifier:
		// Parameter: uint32_t millseconds, 
		//************************************
		int32_t lock(uint32_t millseconds = CAF_MUTEX_LOCK_WAIT_TIME);
		
		//************************************
		// Method:    unlock
		// FullName:  CAF::CAF_Mutex::unlock
		// Access:    public
		// Returns:   int32_t
		// Qualifier:
		//************************************
		int32_t unlock();
		
		//************************************
		// Method:    tryLock
		// FullName:  CAF::CAF_Mutex::tryLock
		// Access:    public 
		// Returns:   int32_t
		// Qualifier:
		//************************************
		int32_t tryLock();

	//���໹��Ҫʹ��
	protected:
		CAF_Mutex(const CAF_Mutex&);
		CAF_Mutex& operator=(const CAF_Mutex&);
	
	private:
		pthread_mutex_t _mutex;
	};
}

#endif
