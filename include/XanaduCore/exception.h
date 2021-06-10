#ifndef			_XANADU_CORE_EXCEPTION_H_
#define			_XANADU_CORE_EXCEPTION_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

// Xanadu namespace
namespace Xanadu
{
	///  <summary>
	///  Exception handling class of Xanadu
	///  </summary>
	class XANADU_CORE_EXPORT exception
	{
	private:
		// Exception description
		XString				_explain;

	public:
		// constructor
		exception() noexcept;

		// constructor
		explicit exception(const wchar_t* _Explain) noexcept;

		// constructor
		explicit exception(const XString& _Explain) noexcept;

		// constructor
		exception(const exception& _Exception) noexcept;

		// destructor
		virtual ~exception() noexcept;

	public:
		// Operator overloading =
		exception& operator = (const wchar_t* _Explain) noexcept;

		// Operator overloading =
		exception& operator = (const XString& _Explain) noexcept;

		// Operator overloading =
		exception& operator = (const exception& _Exception) noexcept;

	public:
		// Get exception description
		virtual const wchar_t* what() const noexcept;
	};
}

#endif
