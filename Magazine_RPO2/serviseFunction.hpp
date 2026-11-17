#ifndef _SERVISEFUNCTION_HPP_
#define _SERVISEFUNCTION_HPP_
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

void Getline(std::wstring& str, wchar_t ch = L'\n');
template <class ArrType>
void FillArray(ArrType* dynamicArr, ArrType* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
inline void Err()
{
	std::wcout << L"Некорретный ввод\n\n";
	Sleep(1500);
}



#endif // !_SERVISEFUNCTION_HPP_