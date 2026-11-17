#include "storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

void CreateStorage(int mode)
{
	if (mode == 0)
	{
		const size_t staticSize = 10;
		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Шубка из эльфа", L"Шубка из сфинкса", 
			L"Шубка из дворняги", L"Шубка из персидской кошки",
			L"Шубка из мейн-куна", L"Шубка из бомбейской кошки",
			L"Шубка из гаваны", L"Шубка из бразильской короткошерсткой кошки",
			L"Шубка из шотландского вислоуха", L"Шубка из рэгдолла",
		};
		size_t countArrStatic[staticSize]{ 6, 7, 999, 4, 10, 11, 9, 32, 1, 6 };
		double priceArrStatic[staticSize]{ 7777.77, 11990.99, 1990.99, 60000.0, 32000.50, 14990.9, 31000.10, 6700.00, 7070.01, 2990.99 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];



		FillArray(idArr, idArrStatic, sizeSt);
		FillArray(nameArr, nameArrStatic, sizeSt);
		FillArray(countArr, countArrStatic, sizeSt);
		FillArray(priceArr, priceArrStatic, sizeSt);

		isStorageCreated = true;
	}
	else if (mode == 1)
	{
		//todo
	}
	else
	{
		std::wcout << L"Склад Уже создан\n\n";
		Sleep(1500);
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\tТовары\"Шубка cat of bus\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40)
			<< L"Кол-во\t" << L"Цена\n\n";
	}
}
