#include<iostream>
#include<ctime>
#include<cstdlib>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int set_color = 15;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Console получение дискриптора окна
	SetConsoleTextAttribute(hConsole, set_color);

	// пытался сделать динамическое поле.
	/*
	int  rol, col;
	std::cout << "Введите размеры поля \n";
	std::cout << "Ширину -  ";
	std::cin >> col;
	std::cout << "Высоту -  ";
	std::cin >> rol;

	int** battle_field = new int* [rol];

	for (int i = 0; i < rol; i++)
	{
		battle_field[i] = new int[col];
	}
	*/

	int const rol = 20, col = 20;
	int battle_field[rol][col];
	int battle_field_2[rol][col];


	// ограничиваю размер поля 

	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0) battle_field[i][j] = 9;
			else if (i == rol - 1) battle_field[i][j] = 9;
			else if (j == 0) battle_field[i][j] = 9;
			else if (j == col - 1) battle_field[i][j] = 9;
			else battle_field[i][j] = 0;
		}
	}


	// выбор кораблей по умалчанию или игроком

	int lincor = 1, cruser = 1, convoy = 2, boat = 3;

	/*
	std::cout << "Введите количество кораблей \n";
	std::cout << "Введите количество линкоров -";
	std::cin >> lincor;
	std::cout << "Введите количество крейсеров  -";
	std::cin >> cruser;
	std::cout << "Введите количество эскортных кораблей - ";
	std::cin >> convoy;
	std::cout << "Введите количество торпедных катеров -";
	std::cin >> boat;
	*/
	//system("pause");

	// расстанавливаю линкоры
	for (int i = 0; i < lincor; i++)
	{
		while (true)
		{
			//system("pause");

			int x = rand() % col - 1;  // рандомное определение верхней правой точки корабля
			int y = rand() % rol - 1;
			int orientation = rand() % 2;
			//std::cout << orientation <<"\n";
			if (orientation == 0)  // ориентация корабля горизонтально или вертикаоьно
			{
				if (battle_field[x][y] != 0) continue;
				else if (battle_field[x + 1][y] != 0) continue;
				else if (battle_field[x + 2][y] != 0) continue;
				else if (battle_field[x + 3][y] != 0) continue;
				else
				{
					// 2- нахождение корпуса корабля 
					// 1- исключение вокруг корпуса
					battle_field[x - 1][y - 1] = 1;
					battle_field[x - 1][y] = 1;
					battle_field[x - 1][y + 1] = 1;
					battle_field[x][y] = 2;
					battle_field[x][y - 1] = 1;
					battle_field[x][y + 1] = 1;
					battle_field[x + 1][y] = 2;
					battle_field[x + 1][y - 1] = 1;
					battle_field[x + 1][y + 1] = 1;
					battle_field[x + 2][y] = 2;
					battle_field[x + 2][y - 1] = 1;
					battle_field[x + 2][y + 1] = 1;
					battle_field[x + 3][y] = 2;
					battle_field[x + 3][y - 1] = 1;
					battle_field[x + 3][y + 1] = 1;
					battle_field[x + 4][y - 1] = 1;
					battle_field[x + 4][y] = 1;
					battle_field[x + 4][y + 1] = 1;
				}
			}
			if (orientation == 1)
			{
				if (battle_field[x][y] != 0) continue;
				else if (battle_field[x][y + 1] != 0) continue;
				else if (battle_field[x][y + 2] != 0) continue;
				else if (battle_field[x][y + 3] != 0) continue;

				else
				{
					battle_field[x - 1][y - 1] = 1;
					battle_field[x][y - 1] = 1;
					battle_field[x + 1][y - 1] = 1;
					battle_field[x - 1][y] = 1;
					battle_field[x][y] = 2;
					battle_field[x + 1][y] = 1;
					battle_field[x][y + 1] = 2;
					battle_field[x - 1][y + 1] = 1;
					battle_field[x + 1][y + 1] = 1;
					battle_field[x][y + 2] = 2;
					battle_field[x - 1][y + 2] = 1;
					battle_field[x + 1][y + 2] = 1;
					battle_field[x][y + 3] = 2;
					battle_field[x - 1][y + 3] = 1;
					battle_field[x + 1][y + 3] = 1;
					battle_field[x][y + 4] = 1;
					battle_field[x - 1][y + 4] = 1;
					battle_field[x + 1][y + 4] = 1;

				}
			}

			break;
		}



	}
	for (int i = 0; i < cruser; i++)
	{
		while (true)
		{
			//system("pause");
			int x = rand() % col - 1;
			int y = rand() % rol - 1;
			int orientation = rand() % 2;
			//std::cout << orientation << "\n";
			if (orientation == 0)
			{
				if (battle_field[x][y] != 0) continue;
				else if (battle_field[x + 1][y] != 0) continue;
				else if (battle_field[x + 2][y] != 0) continue;
				else
				{
					battle_field[x - 1][y - 1] = 1;
					battle_field[x - 1][y] = 1;
					battle_field[x - 1][y + 1] = 1;
					battle_field[x][y] = 2;
					battle_field[x][y - 1] = 1;
					battle_field[x][y + 1] = 1;
					battle_field[x + 1][y] = 2;
					battle_field[x + 1][y - 1] = 1;
					battle_field[x + 1][y + 1] = 1;
					battle_field[x + 2][y] = 2;
					battle_field[x + 2][y - 1] = 1;
					battle_field[x + 2][y + 1] = 1;

					battle_field[x + 3][y - 1] = 1;
					battle_field[x + 3][y] = 1;
					battle_field[x + 3][y + 1] = 1;
				}
			}
			if (orientation == 1)
			{
				if (battle_field[x][y] != 0) continue;
				else if (battle_field[x][y + 1] != 0) continue;
				else if (battle_field[x][y + 2] != 0) continue;

				else
				{
					battle_field[x - 1][y - 1] = 1;
					battle_field[x][y - 1] = 1;
					battle_field[x + 1][y - 1] = 1;
					battle_field[x - 1][y] = 1;
					battle_field[x][y] = 2;
					battle_field[x + 1][y] = 1;
					battle_field[x][y + 1] = 2;
					battle_field[x - 1][y + 1] = 1;
					battle_field[x + 1][y + 1] = 1;
					battle_field[x][y + 2] = 2;
					battle_field[x - 1][y + 2] = 1;
					battle_field[x + 1][y + 2] = 1;

					battle_field[x][y + 3] = 1;
					battle_field[x - 1][y + 3] = 1;
					battle_field[x + 1][y + 3] = 1;

				}
			}

			break;
		}



	}
	for (int i = 0; i < convoy; i++)
	{
		while (true)
		{
			//system("pause");
			int x = rand() % col - 1;
			int y = rand() % rol - 1;
			int orientation = rand() % 2;
			//std::cout << orientation << "\n";
			if (orientation == 0)
			{
				if (battle_field[x][y] != 0) continue;
				else if (battle_field[x + 1][y] != 0) continue;
				else
				{
					battle_field[x - 1][y - 1] = 1;
					battle_field[x - 1][y] = 1;
					battle_field[x - 1][y + 1] = 1;
					battle_field[x][y] = 2;
					battle_field[x][y - 1] = 1;
					battle_field[x][y + 1] = 1;
					battle_field[x + 1][y] = 2;
					battle_field[x + 1][y - 1] = 1;
					battle_field[x + 1][y + 1] = 1;


					battle_field[x + 2][y - 1] = 1;
					battle_field[x + 2][y] = 1;
					battle_field[x + 2][y + 1] = 1;
				}
			}
			if (orientation == 1)
			{
				if (battle_field[x][y] != 0) continue;
				else if (battle_field[x][y + 1] != 0) continue;


				else
				{
					battle_field[x - 1][y - 1] = 1;
					battle_field[x][y - 1] = 1;
					battle_field[x + 1][y - 1] = 1;
					battle_field[x - 1][y] = 1;
					battle_field[x][y] = 2;
					battle_field[x + 1][y] = 1;
					battle_field[x][y + 1] = 2;
					battle_field[x - 1][y + 1] = 1;
					battle_field[x + 1][y + 1] = 1;

					battle_field[x][y + 2] = 1;
					battle_field[x - 1][y + 2] = 1;
					battle_field[x + 1][y + 2] = 1;

				}
			}

			break;
		}



	}
	for (int i = 0; i < boat; i++)
	{
		while (true)
		{
			//system("pause");
			int x = rand() % col - 1;
			int y = rand() % rol - 1;

			if (battle_field[x][y] != 0) continue;

			else
			{
				battle_field[x - 1][y - 1] = 1;
				battle_field[x - 1][y] = 1;
				battle_field[x - 1][y + 1] = 1;
				battle_field[x][y] = 2;
				battle_field[x][y - 1] = 1;
				battle_field[x][y + 1] = 1;
				battle_field[x + 1][y - 1] = 1;
				battle_field[x + 1][y] = 1;
				battle_field[x + 1][y + 1] = 1;
			}
			break;
		}



	}


	// заменяю 1 (исключение вокруг корпуса) на 9 - граница карты
	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0) battle_field[i][j] = 9;
			else if (i == rol - 1) battle_field[i][j] = 9;
			else if (j == 0) battle_field[i][j] = 9;
			else if (j == col - 1) battle_field[i][j] = 9;

		}
	}
	// отрисовываю карту
	/*
	std::cout << " Наша эскадра \n";
	for (int i = 0; i < rol-1; i++)
		{
		for (int j = 0; j < col-1; j++)
		{

			char simbol;
			if (j == 0) std::cout << i%10 << " ";
			else if (i == 0) std::cout << j%10 << " ";
				else
				{
					if (battle_field[i][j] == 0) simbol = '~';
					if (battle_field[i][j] == 1) simbol = '~';
					if (battle_field[i][j] == 2) simbol = '@';
					if (battle_field[i][j] == 9) simbol = ' ';
					std::cout << simbol << " ";
				}
			}
			std::cout << "\n";
		}
	*/




	/////////////////////////////////////////////////////////////////
/*
	for (int i = 0; i < rol; i++)
	{
		delete [] battle_field[i] ;
	}
	delete[] battle_field;
*/

// Рисую вражий флот



	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0) battle_field_2[i][j] = 9;
			else if (i == rol - 1) battle_field_2[i][j] = 9;
			else if (j == 0) battle_field_2[i][j] = 9;
			else if (j == col - 1) battle_field_2[i][j] = 9;
			else battle_field_2[i][j] = 0;
		}
	}



	for (int i = 0; i < lincor; i++)
	{
		while (true)
		{
			//system("pause");

			int x = rand() % col - 1;  // рандомное определение верхней правой точки корабля
			int y = rand() % rol - 1;
			int orientation = rand() % 2;
			//std::cout << orientation <<"\n";
			if (orientation == 0)  // ориентация корабля горизонтально или вертикаоьно
			{
				if (battle_field_2[x][y] != 0) continue;
				else if (battle_field_2[x + 1][y] != 0) continue;
				else if (battle_field_2[x + 2][y] != 0) continue;
				else if (battle_field_2[x + 3][y] != 0) continue;
				else
				{
					// 2- нахождение корпуса корабля 
					// 1- исключение вокруг корпуса
					battle_field_2[x - 1][y - 1] = 1;
					battle_field_2[x - 1][y] = 1;
					battle_field_2[x - 1][y + 1] = 1;
					battle_field_2[x][y] = 2;
					battle_field_2[x][y - 1] = 1;
					battle_field_2[x][y + 1] = 1;
					battle_field_2[x + 1][y] = 2;
					battle_field_2[x + 1][y - 1] = 1;
					battle_field_2[x + 1][y + 1] = 1;
					battle_field_2[x + 2][y] = 2;
					battle_field_2[x + 2][y - 1] = 1;
					battle_field_2[x + 2][y + 1] = 1;
					battle_field_2[x + 3][y] = 2;
					battle_field_2[x + 3][y - 1] = 1;
					battle_field_2[x + 3][y + 1] = 1;
					battle_field_2[x + 4][y - 1] = 1;
					battle_field_2[x + 4][y] = 1;
					battle_field_2[x + 4][y + 1] = 1;
				}
			}
			if (orientation == 1)
			{
				if (battle_field_2[x][y] != 0) continue;
				else if (battle_field_2[x][y + 1] != 0) continue;
				else if (battle_field_2[x][y + 2] != 0) continue;
				else if (battle_field_2[x][y + 3] != 0) continue;

				else
				{
					battle_field_2[x - 1][y - 1] = 1;
					battle_field_2[x][y - 1] = 1;
					battle_field_2[x + 1][y - 1] = 1;
					battle_field_2[x - 1][y] = 1;
					battle_field_2[x][y] = 2;
					battle_field_2[x + 1][y] = 1;
					battle_field_2[x][y + 1] = 2;
					battle_field_2[x - 1][y + 1] = 1;
					battle_field_2[x + 1][y + 1] = 1;
					battle_field_2[x][y + 2] = 2;
					battle_field_2[x - 1][y + 2] = 1;
					battle_field_2[x + 1][y + 2] = 1;
					battle_field_2[x][y + 3] = 2;
					battle_field_2[x - 1][y + 3] = 1;
					battle_field_2[x + 1][y + 3] = 1;
					battle_field_2[x][y + 4] = 1;
					battle_field_2[x - 1][y + 4] = 1;
					battle_field_2[x + 1][y + 4] = 1;

				}
			}

			break;
		}



	}
	for (int i = 0; i < cruser; i++)
	{
		while (true)
		{
			//system("pause");
			int x = rand() % col - 1;
			int y = rand() % rol - 1;
			int orientation = rand() % 2;
			//std::cout << orientation << "\n";
			if (orientation == 0)
			{
				if (battle_field_2[x][y] != 0) continue;
				else if (battle_field_2[x + 1][y] != 0) continue;
				else if (battle_field_2[x + 2][y] != 0) continue;
				else
				{
					battle_field_2[x - 1][y - 1] = 1;
					battle_field_2[x - 1][y] = 1;
					battle_field_2[x - 1][y + 1] = 1;
					battle_field_2[x][y] = 2;
					battle_field_2[x][y - 1] = 1;
					battle_field_2[x][y + 1] = 1;
					battle_field_2[x + 1][y] = 2;
					battle_field_2[x + 1][y - 1] = 1;
					battle_field_2[x + 1][y + 1] = 1;
					battle_field_2[x + 2][y] = 2;
					battle_field_2[x + 2][y - 1] = 1;
					battle_field_2[x + 2][y + 1] = 1;

					battle_field_2[x + 3][y - 1] = 1;
					battle_field_2[x + 3][y] = 1;
					battle_field_2[x + 3][y + 1] = 1;
				}
			}
			if (orientation == 1)
			{
				if (battle_field_2[x][y] != 0) continue;
				else if (battle_field_2[x][y + 1] != 0) continue;
				else if (battle_field_2[x][y + 2] != 0) continue;

				else
				{
					battle_field_2[x - 1][y - 1] = 1;
					battle_field_2[x][y - 1] = 1;
					battle_field_2[x + 1][y - 1] = 1;
					battle_field_2[x - 1][y] = 1;
					battle_field_2[x][y] = 2;
					battle_field_2[x + 1][y] = 1;
					battle_field_2[x][y + 1] = 2;
					battle_field_2[x - 1][y + 1] = 1;
					battle_field_2[x + 1][y + 1] = 1;
					battle_field_2[x][y + 2] = 2;
					battle_field_2[x - 1][y + 2] = 1;
					battle_field_2[x + 1][y + 2] = 1;

					battle_field_2[x][y + 3] = 1;
					battle_field_2[x - 1][y + 3] = 1;
					battle_field_2[x + 1][y + 3] = 1;

				}
			}

			break;
		}



	}
	for (int i = 0; i < convoy; i++)
	{
		while (true)
		{
			//system("pause");
			int x = rand() % col - 1;
			int y = rand() % rol - 1;
			int orientation = rand() % 2;
			//std::cout << orientation << "\n";
			if (orientation == 0)
			{
				if (battle_field_2[x][y] != 0) continue;
				else if (battle_field_2[x + 1][y] != 0) continue;
				else
				{
					battle_field_2[x - 1][y - 1] = 1;
					battle_field_2[x - 1][y] = 1;
					battle_field_2[x - 1][y + 1] = 1;
					battle_field_2[x][y] = 2;
					battle_field_2[x][y - 1] = 1;
					battle_field_2[x][y + 1] = 1;
					battle_field_2[x + 1][y] = 2;
					battle_field_2[x + 1][y - 1] = 1;
					battle_field_2[x + 1][y + 1] = 1;


					battle_field_2[x + 2][y - 1] = 1;
					battle_field_2[x + 2][y] = 1;
					battle_field_2[x + 2][y + 1] = 1;
				}
			}
			if (orientation == 1)
			{
				if (battle_field_2[x][y] != 0) continue;
				else if (battle_field_2[x][y + 1] != 0) continue;


				else
				{
					battle_field_2[x - 1][y - 1] = 1;
					battle_field_2[x][y - 1] = 1;
					battle_field_2[x + 1][y - 1] = 1;
					battle_field_2[x - 1][y] = 1;
					battle_field_2[x][y] = 2;
					battle_field_2[x + 1][y] = 1;
					battle_field_2[x][y + 1] = 2;
					battle_field_2[x - 1][y + 1] = 1;
					battle_field_2[x + 1][y + 1] = 1;

					battle_field_2[x][y + 2] = 1;
					battle_field_2[x - 1][y + 2] = 1;
					battle_field_2[x + 1][y + 2] = 1;

				}
			}

			break;
		}



	}
	for (int i = 0; i < boat; i++)
	{
		while (true)
		{
			//system("pause");
			int x = rand() % col - 1;
			int y = rand() % rol - 1;

			if (battle_field_2[x][y] != 0) continue;

			else
			{
				battle_field_2[x - 1][y - 1] = 1;
				battle_field_2[x - 1][y] = 1;
				battle_field_2[x - 1][y + 1] = 1;
				battle_field_2[x][y] = 2;
				battle_field_2[x][y - 1] = 1;
				battle_field_2[x][y + 1] = 1;
				battle_field_2[x + 1][y - 1] = 1;
				battle_field_2[x + 1][y] = 1;
				battle_field_2[x + 1][y + 1] = 1;
			}
			break;
		}



	}


	// заменяю 1 (исключение вокруг корпуса) на 9 - граница карты
	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0) battle_field[i][j] = 9;
			else if (i == rol - 1) battle_field[i][j] = 9;
			else if (j == 0) battle_field[i][j] = 9;
			else if (j == col - 1) battle_field[i][j] = 9;

		}
	}
	for (int i = 0; i < rol; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0) battle_field_2[i][j] = 9;
			else if (i == rol - 1) battle_field_2[i][j] = 9;
			else if (j == 0) battle_field_2[i][j] = 9;
			else if (j == col - 1) battle_field_2[i][j] = 9;

		}
	}
	// отрисовываю карту
	std::cout << " Наша эскадра                " << "     Вражеская эскадра \n";
	for (int i = 0; i < rol - 1; i++)
	{
		for (int j = 0; j < col - 1; j++)
		{

			char simbol;
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << i % 10 << " ";
			}
			else if (i == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << j % 10 << " ";
			}
			else
			{
				if (battle_field[i][j] == 0)
				{
					SetConsoleTextAttribute(hConsole, 3);
					simbol = '~';
				}
				if (battle_field[i][j] == 1)
				{
					SetConsoleTextAttribute(hConsole, 3);
					simbol = '~';
				}
				if (battle_field[i][j] == 2)
				{
					SetConsoleTextAttribute(hConsole, 8);
					simbol = '@';
				}
				if (battle_field[i][j] == 9)
				{
					SetConsoleTextAttribute(hConsole, 1);
					simbol = ' ';
				}
				std::cout << simbol << " ";
			}
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "         ";
		for (int j = 0; j < col - 1; j++)
		{

			char simbol;
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << i % 10 << " ";
			}
			else if (i == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << j % 10 << " ";
			}
			else
			{
				if (battle_field_2[i][j] == 0)
				{
					SetConsoleTextAttribute(hConsole, 3);
					simbol = '~';
				}
				if (battle_field_2[i][j] == 1)
				{
					SetConsoleTextAttribute(hConsole, 3);
					simbol = '~';
				}
				if (battle_field_2[i][j] == 2)
				{
					SetConsoleTextAttribute(hConsole, 3);
					simbol = '~';
				}
				if (battle_field_2[i][j] == 9)
				{
					SetConsoleTextAttribute(hConsole, 1);
					simbol = ' ';
				}
				std::cout << simbol << " ";
			}
		}
		std::cout << "\n";
	}




	int player_hp = lincor * 4 + cruser * 3 + convoy * 2 + boat*1, enemy_hp = lincor * 4 + cruser * 3 + convoy * 2 + boat*1;
        int fire_x, fire_y, fire_x_2, fire_y_2;
		int fire_status =0, fire_status_2 =0;

	while (player_hp > 0 and enemy_hp > 0)
	{
		// Ход игрока 

		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		system("cls");
		//std::cout << player_hp << "  " << enemy_hp;
		

		while (true)
		{

			fire_x = rand() % rol - 1;
			fire_y = rand() % col - 1;

			if (battle_field_2[fire_x][fire_y] == 3)  continue; // исключаем стрельбу где были промахи
			if (battle_field_2[fire_x][fire_y] == 4) continue;   // где были попадания
			if (battle_field_2[fire_x][fire_y] == 5) continue;   // где корабль не может быть размещен

			
			if (battle_field_2[fire_x][fire_y] == 0 or battle_field_2[fire_x][fire_y] == 1)
			{
				battle_field_2[fire_x][fire_y] = 3; //промах
				fire_status = 0;
				break;
			}
			if (battle_field_2[fire_x][fire_y] == 2)
			{
				battle_field_2[fire_x][fire_y] = 4; // попадание
				fire_status = 1;
				// проверка на ренение
				if (battle_field_2[fire_x-1][fire_y] == 2) fire_status = 2;
				if (battle_field_2[fire_x + 1][fire_y] == 2) fire_status = 2;
				if (battle_field_2[fire_x][fire_y-1] == 2) fire_status = 2;
				if (battle_field_2[fire_x][fire_y+1] == 2) fire_status = 2;
				///
				enemy_hp--;
				break;
			}
			
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Выстрел ИГРОКА " << fire_x << " - " << fire_y << "\n";
			if (fire_status == 0) std::cout << "Мимо \n";
			if (fire_status == 1)
			{
				std::cout << "Убил \n";
				// убираем углы 
				battle_field_2[fire_x - 1][fire_y - 1] = 5;
				battle_field_2[fire_x + 1][fire_y - 1] = 5;
				battle_field_2[fire_x - 1][fire_y + 1] = 5;
				battle_field_2[fire_x + 1][fire_y + 1] = 5;

			}
			if (fire_status == 2)
			{
				std::cout << "Ранил\n";
				battle_field_2[fire_x - 1][fire_y - 1] = 5;
				battle_field_2[fire_x + 1][fire_y - 1] = 5;
				battle_field_2[fire_x - 1][fire_y + 1] = 5;
				battle_field_2[fire_x + 1][fire_y + 1] = 5;
			}
				

		std::cout << " Наша эскадра                " << "     Вражеская эскадра \n";
		for (int i = 0; i < rol - 1; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{

				char simbol;
				if (j == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << i % 10 << " ";
				}
				else if (i == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << j % 10 << " ";
				}
				else
				{
					if (battle_field[i][j] == 0)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field[i][j] == 2)
					{
						SetConsoleTextAttribute(hConsole, 8);
						simbol = '@';
					}
					if (battle_field[i][j] == 3)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field[i][j] == 4)
					{
						SetConsoleTextAttribute(hConsole, 12);
						simbol = '#';
					}
					if (battle_field[i][j] == 5)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field[i][j] == 9)
					{
						SetConsoleTextAttribute(hConsole, 1);
						simbol = ' ';
					}
					std::cout << simbol << " ";
				}
			}
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "         ";
			for (int j = 0; j < col - 1; j++)
			{

				char simbol;
				if (j == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << i % 10 << " ";
				}
				else if (i == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << j % 10 << " ";
				}
				else
				{
					if (battle_field_2[i][j] == 0)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field_2[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field_2[i][j] == 2)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field_2[i][j]==3)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field_2[i][j] == 4)
					{
						SetConsoleTextAttribute(hConsole, 12);
						simbol = '#';
					}
					if (battle_field_2[i][j] == 5)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field_2[i][j] == 9)
					{
						SetConsoleTextAttribute(hConsole, 1);
						simbol = ' ';
					}


					std::cout << simbol << " ";
				}
			}
			std::cout << "\n";
		}

		// Ход опонента

		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		system("cls");



		while (true)
		{

			fire_x_2 = rand() % rol - 1;
			fire_y_2 = rand() % col - 1;

			if (battle_field[fire_x_2][fire_y_2] == 3)  continue; // исключаем стрельбу где были промахи
			if (battle_field[fire_x_2][fire_y_2] == 4) continue;   // где были попадания
			if (battle_field[fire_x_2][fire_y_2] == 5) continue;   // где корабль не может быть размещен


			if (battle_field[fire_x_2][fire_y_2] == 0 or battle_field[fire_x_2][fire_y_2] == 1)
			{
				battle_field[fire_x_2][fire_y_2] = 3; //промах
				fire_status_2 = 0;
				break;
			}
			if (battle_field[fire_x_2][fire_y_2] == 2)
			{
				battle_field[fire_x_2][fire_y_2] = 4; // попадание
				fire_status_2 = 1;
				// проверка на ренение
				if (battle_field[fire_x_2 - 1][fire_y_2] == 2) fire_status_2 = 2;
				if (battle_field[fire_x_2 + 1][fire_y_2] == 2) fire_status_2 = 2;
				if (battle_field[fire_x_2][fire_y_2 - 1] == 2) fire_status_2 = 2;
				if (battle_field[fire_x_2][fire_y_2 + 1] == 2) fire_status_2 = 2;
				///
				player_hp--;
				break;
			}

		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Выстрел ОПОНЕНТА " << fire_x_2 << " - " << fire_y_2 << "\n";
		if (fire_status_2 == 0) std::cout << "Мимо \n";
		if (fire_status_2 == 1)
		{
			std::cout << "Убил \n";
			// убираем углы 
			battle_field[fire_x_2 - 1][fire_y_2 - 1] = 5;
			battle_field[fire_x_2+ 1][fire_y_2- 1] = 5;
			battle_field[fire_x_2- 1][fire_y_2 + 1] = 5;
			battle_field[fire_x_2 + 1][fire_y_2+ 1] = 5;

		}
		if (fire_status_2 == 2)
		{
			std::cout << "Ранил\n";
			battle_field[fire_x_2 - 1][fire_y_2 - 1] = 5;
			battle_field[fire_x_2 + 1][fire_y_2 - 1] = 5;
			battle_field[fire_x_2 - 1][fire_y_2 + 1] = 5;
			battle_field[fire_x_2 + 1][fire_y_2 + 1] = 5;
		}


		std::cout << " Наша эскадра                " << "     Вражеская эскадра \n";
		for (int i = 0; i < rol - 1; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{

				char simbol;
				if (j == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << i % 10 << " ";
				}
				else if (i == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << j % 10 << " ";
				}
				else
				{
					if (battle_field[i][j] == 0)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field[i][j] == 2)
					{
						SetConsoleTextAttribute(hConsole, 8);
						simbol = '@';
					}
					if (battle_field[i][j] == 3)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field[i][j] == 4)
					{
						SetConsoleTextAttribute(hConsole, 12);
						simbol = '#';
					}
					if (battle_field[i][j] == 5)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field[i][j] == 9)
					{
						SetConsoleTextAttribute(hConsole, 1);
						simbol = ' ';
					}
					std::cout << simbol << " ";
				}
			}
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "         ";
			for (int j = 0; j < col - 1; j++)
			{

				char simbol;
				if (j == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << i % 10 << " ";
				}
				else if (i == 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << j % 10 << " ";
				}
				else
				{
					if (battle_field_2[i][j] == 0)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field_2[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field_2[i][j] == 2)
					{
						SetConsoleTextAttribute(hConsole, 3);
						simbol = '~';
					}
					if (battle_field_2[i][j] == 3)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field_2[i][j] == 4)
					{
						SetConsoleTextAttribute(hConsole, 12);
						simbol = '#';
					}
					if (battle_field_2[i][j] == 5)
					{
						SetConsoleTextAttribute(hConsole, 7);
						simbol = '^';
					}
					if (battle_field_2[i][j] == 9)
					{
						SetConsoleTextAttribute(hConsole, 1);
						simbol = ' ';
					}


					std::cout << simbol << " ";
				}
			}
			std::cout << "\n";
		}

	}
	SetConsoleTextAttribute(hConsole, 15);
	if (player_hp == 0) std::cout << "ОПОНЕНТ выиграл!\n";
	if (enemy_hp == 0) std::cout << "ИГРОК выиграл!\n";







	return 0;
}