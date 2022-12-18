#include <iostream>
#include <Windows.h>
#include <locale.h>
using namespace std;

void smezh(int m,int n, int**G1)
{
	int** G2 = (int**)malloc(sizeof(int*) * n); // создание 2 массива
	for (int i = 0; i < n; i++)
	{
		G2[i] = (int*)malloc(sizeof(int*) * m);
	}
	int k = 0;
	for (int i = 0; i < n; i++) // вывод 2 массива
	{
		for (int j = 0; j < m; j++)
		{
			G2[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) // заполнение 2 массива
	{
		for (int j = 0; j < n; j++)
		{
			if (G1[i][j] == 1)
			{
				G2[i][k] = 1;
				G2[j][k] = 1;
				k++;
			}
		}
	}
	for (int i = 0; i < n; i++) // вывод 2 массива
	{
		for (int j = 0; j < m; j++)
		{
			cout << G2[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int n = 0, m = 0;
	cout << "Количество вершин: ";
	cin >> n;
	int** G1 = (int**)malloc(sizeof(int*) * n); // создание 1 массива
	for (int i = 0; i < n; i++)
	{
		G1[i] = (int*)malloc(sizeof(int*) * n);
	}

	for (int i = 0; i < n; i++) // заполнение 1 массива
	{
		for (int j = 0; j < n; j++)
		{
			G1[i][j] = rand() % 2;
			G1[j][i] = G1[i][j];
			if (i == j)
				G1[i][j] = 0;
		}
	}
	cout << "Матрица смежности";
	cout << endl;
	for (int i = 0; i < n; i++) // вывод 1 массива
	{
		for (int j = 0; j < n; j++)
		{
			cout << G1[i][j] << " ";
			if (G1[i][j] == 1)
				m++;
		}
		cout << endl;
	}
	m = m / 2;
	cout << endl;
	cout << m << " - размер графа";
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++) // подсчет вершин
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (G1[i][j] != 0)
			{
				sum++;
			}
		}
		if (sum == n - 1)
		{
			cout << i << " - доминирующая";
			cout << endl;
		}
		if (sum == 1)
		{
			cout << i << " - концевая";
			cout << endl;
		}
		if (sum == 0)
		{
			cout << i << " - изолированная";
			cout << endl;
		}
	}
	cout << endl;
	smezh(m, n, G1);
	cout << endl;
	cout << m << " - размер графа";
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++) // подсчет вершин
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (G1[i][j] != 0)
			{
				sum++;
			}
		}
		if (sum == n - 1)
		{
			cout << i << " - доминирующая";
			cout << endl;
		}
		if (sum == 1)
		{
			cout << i << " - концевая";
			cout << endl;
		}
		if (sum == 0)
		{
			cout << i << " - изолированная";
			cout << endl;
		}
	}
	cout << endl;
	system("pause");
}