#include "autorization.hpp"
#include "account.hpp"
void Start()
{
	while (true)
	{
		if (Login())
		{

		}
		else 
		{
			system("cls");
			std::wcout << L"\n\n\n\t\tВсего доброго, гной\n\n\n";
			Sleep(1500);
			break;
		}
	}
}

bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t\t Здарова мучачос";
		std::wcout << L"\n\n\t\tШубка Сat of bus\n\n";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"\nДобро пожаловать " << loginArr[i] << L"\n\n";
					std::wcout << L"Ваш статус " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					Sleep(1500);
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль";
			Sleep(1500);
		}
	}
}
