#include "serviseFunction.hpp"

void Getline(std::wstring& str, wchar_t ch)
{
	std::getline(std::wcin, str, ch);
}

bool isNumber(const std::wstring& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::wcout << L"Ошибка длинны. Максимум 9 значные числа";
		Sleep(1500);
		return false;
	}

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::wcout << L"Введённые данные не являеются числом";
			Sleep(1500);
			return false;
		}
	}
	return true;
}
