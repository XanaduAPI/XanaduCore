#ifndef			_XANADU_CORE_MUTEX_H_
#define			_XANADU_CORE_MUTEX_H_

#include <XanaduCore/XHeader.h>

// Xanadu namespace
namespace Xanadu
{
	///  <summary>
	///  Implementation of cross platform mutex
	///  </summary>
	class XANADU_CORE_EXPORT mutex
	{
	public:
		// Types of mutex
		enum RecursionMode
		{
			Recursive,
			NonRecursive,
		};

	private:
		// Private data of mutex
		HANDLE				_mutex_data;

		// Types of locks
		RecursionMode			_mutex_mode;

	public:
		// constructor
		explicit mutex(RecursionMode _Mode = Recursive) noexcept;

		// destructor
		virtual ~mutex() noexcept;

	public:
		// Gets the type of the lock
		virtual RecursionMode type() const noexcept;

	public:
		// Lock
		virtual void lock() noexcept;

		// Unlock
		virtual void unlock() noexcept;
	};

	///  <summary>
	///  A class that can release mutex automatically
	///  </summary>
	class XANADU_CORE_EXPORT mutex_auto
	{
	private:
		Xanadu::mutex&				_data_mutex;

	public:
		// constructor
		explicit mutex_auto(Xanadu::mutex& _Mutex) noexcept;

		// destructor
		virtual ~mutex_auto() noexcept;
	};
}

// Macro used to call auto destruct lock conveniently
#define				XANADU_MUTEX_AUTO(_Mutex)				Xanadu::mutex_auto	_XanaduMutexAuto(_Mutex)

#endif
