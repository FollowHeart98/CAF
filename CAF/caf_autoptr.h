#ifndef _CAF_AUTOPTR_H_
#define _CAF_AUTOPTR_H_

namespace CAF
{ 
	/*
		����ָ����, ����ָ��������ʱ������Դ���գ����������Դָ����ʵ�ּ���
		T ����̳���CAF_Shareable
	*/
	template<class T>
	class CAF_AutoPtr
	{
	public:
		CAF_AutoPtr(const T* ptr = NULL) : _pElem(ptr)
		{
			if (!_pElem)
			{
				pElem->incRef();
			}
		}

		/*
			c++��ĳ�Ա��������ֱ�ӷ���������˽�б���, ��������ͬһ����
		*/
		CAF_AutoPtr(const CAF_AutoPtr& other) : _pElem(other._pElem)
		{
			if (!_pElem)
			{
				_pElem->incRef();
			}
		}
		
		/*
			����other�뵱ǰ�಻��ͬ,�������޷�ֱ�ӷ���other��˽�б���
		*/
		template<class U>
		CAF_AutoPtr(const CAF_AutoPtr<U>& other) : _pElem(NULL)
		{
			_pElem = other.get();
			if (!_pElem)
			{
				_pElem->incRef();
			}
		}

		//�����̳�
		~CAF_AutoPtr()
		{
			if (!_pElem)
			{
				if (0 == _pElem->decRef())
				{
					delete _pElem;
					_pElem = NULL;
				}
			}
		}

		CAF_AutoPtr& operator=(const CAF_AutoPtr& r)
		{
			if (_pElem != r._pElem)
			{
				if (!r._pElem)
				{
					r._pElem->incRef();
				}

				if (!_pElem)
				{
					if(0 == _pElem->decRef())
					{
						delete _pElem;
						_pElem = NULL;
					}
				}

				_pElem = r._pElem;
			}
			
			return *this;
		}

		template<class U>
		CAF_AutoPtr& operator=(const CAF_AutoPtr<U>& r) {};
	
		T* operator->() const
		{
			return _pElem;
		}

		CAF_AutoPtr& operator*() const 
		{
			return *_pElem;
		}

		T* get() const
		{
			return _pElem;
		}

		bool isValid() const
		{
			return _pElem ? true : false;
		}
	private:
		T* _pElem;
	};
}

#endif
