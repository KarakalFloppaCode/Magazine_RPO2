#include "storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

double maxPrice = 574000;

size_t maxStorageSize = 3500;
extern size_t currentStorageSize = 0;

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

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArr[i];
		}


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

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Товар\t"
			<< L"      Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\tПополнить товары \"Шубка cat of bus\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Товар\t"
			<< L"      Кол-во\t" << L"\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i]  << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Осталось на складе " << maxStorageSize - currentStorageSize << L" мест.\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\tСписать товары \"Шубка cat of bus\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Товар\t"
			<< L"      Кол-во\t" << L"\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\tИзменить цены \"Шубка cat of bus\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Товар\t"
			<< L"      Цена\t" << L"\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"\nЗавершение операции пополнение товара\n\n";
			Sleep(1500);
			return;
		}
		else if (isNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1 )
			{
				Err();
			}
			else
			{
				std::wcout << L"\nВведите количество товара для пополнения: ";
				Getline(chooseCount);

				if (isNumber(chooseCount))
				{
					size_t count = std::stoi(chooseCount);
					if (count <= 0 && count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректный кол-во! На складе осталось "
							<< maxStorageSize - currentStorageSize << L" Свободных мест\n\n";
						Sleep(1500);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << "\n\n";
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"\t  Подтвердить?\n\n  1 - Да\t\t2 - Нет\n\nВвод: ";
							Getline(choose);
								if (choose == L"1")
								{
									std::wcout << L"\nТовар успешно пополнен\n\n";
									countArr[id] += count;
									currentStorageSize += count;
									Sleep(1500);
									break;
								}
								else if (choose == L"2")
								{
									std::wcout << L"Отмена пополнения товара " << nameArr[id] << L"\n\n";
									Sleep(1500);
									break;
								}
								else
								{
									Err();
								}
						}
					}
				}

			}
		}
		else
		{
			Err();
		}

	}

}

void removeProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(2);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"\nЗавершение операции списания товара\n\n";
			Sleep(1500);
			return;
		}
		else if (isNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"\nВведите количество товара для списания: ";
				Getline(chooseCount);

				if (isNumber(chooseCount))
				{
					size_t count = std::stoi(chooseCount);
					if (count <= 0 || count > countArr[id])
					{
						std::wcout << L"\nНекорректный кол-во! На складе осталось "
							<< countArr[id] << L" штук" << nameArr[id] << "\n\n";
						Sleep(1500);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << "\n\n";
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] - count << L"\n\n";
							std::wcout << L"\t  Подтвердить?\n\n  1 - Да\t\t2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"\nТовар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания товара " << nameArr[id] << L"\n\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}

			}
		}
		else
		{
			Err();
		}

	}
}

void changePrice()
{
	std::wstring chooseId, choosePrice, choose;

	while (true)
	{
		ShowStorage(3);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"\nЗавершение операции изменения ценника товара\n\n";
			Sleep(1500);
			return;
		}
		else if (isNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"\nВведите новый ценник для товара: ";
				Getline(choosePrice);

				if (isNumber(choosePrice))
				{
					double count = std::stoi(choosePrice);

					if (count <= 0 || count > maxPrice)
					{
						std::wcout << L"\nНекорректный ценник! Ценник не может быть больше 574000.";
						Sleep(1500);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << "\n\n";
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] - count << L"\n\n";
							std::wcout << L"\t  Подтвердить?\n\n  1 - Да\t\t2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"\nТовар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания товара " << nameArr[id] << L"\n\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}

			}
		}
		else
		{
			Err();
		}

	}
}
