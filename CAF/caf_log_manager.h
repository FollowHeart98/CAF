#ifndef _CAF_LOG_MANAGER_H_
#define _CAF_LOG_MANAGER_H_

#include <iostream>
#include <vector>
#include "caf_singleton.h"
#include "caf_logger.h"

namespace CAF
{
	class LogManager : public SingleTon<LogManager>
	{
	public:
		void init()
		{
			std::cout << "see" << std::endl;
		}
	
		void setLogger(LoggerPtr p)
		{
			_pLogger = p;
		}

		LoggerPtr getLogger() const
		{
			return _pLogger;
		}

	private:
		//logger������ͷ�ͳһ��������ָ��
		LoggerPtr _pLogger;
	};
}
#endif
