#include "serviseFunction.hpp"

void Getline(std::wstring& str, wchar_t ch)
{
	std::getline(std::wcin, str, ch);
}
