#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

void call(int** v, int* o, int S)
{
	int s = 0, i = 0; --S;
	while (S > 0)
	{
		for (int c = s; c <= S; ++c)
			o[i++] = v[s][c];
		for (int c = s + 1; c <= S; ++c)
			o[i++] = v[c][S];
		for (int c = S - 1; c >= s; --c)
			o[i++] = v[S][c];
		for (int c = S - 1; c >= s + 1; --c)
			o[i++] = v[c][s]; --S; ++s;
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;
	int sum_g = 0, sum_h = 0;

	cout << "Введите размерность массива: ";

	while (!(cin >> n) || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Некорректные данные, попробуйте снова" << endl;
	}

	while (n > 10)
	{
		cout << "Некорректные данные, попробуйте снова" << endl;
		while (!(cin >> n) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некорректные данные, попробуйте снова" << endl;
		}
	}

	system("cls");
	int** v = new int* [n];
	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Массив:" << endl;
	cout << "___________________________________________________________________________" << endl << endl;

	for (int i = 0; i < n; i -= -1)
	{
		v[i] = new int[n];
	}

	for (int i = 0; i < n; i -= -1)
	{
		for (int j = 0; j < n; j -= -1)
		{
			v[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < n; i -= -1)
	{
		for (int j = 0; j < n; j -= -1)
		{
			cout << v[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "___________________________________________________________________________" << endl;

	for (int i = 0; i < n; i -= -1)
	{
		for (int j = 0; j < n; j -= -1)
		{
			sum_h = sum_h + v[i][j];
		}
	}

	int* o = new int[n * n];
	call(v, o, n);
	cout << endl << "Развернутый массив:";
	cout << endl << "___________________________________________________________________________" << endl << endl;

	for (int i = 0; i < n * n; ++i)
	{
		cout << o[i] << ' ';
	}

	int w = 0;
	int y = 1;
	int j = 0;
	int temp = sum_h;

	while (sum_g < sum_h)
	{
		sum_g = 0; sum_h = temp; w = 0;
		for (int i = 0; i < y; i -= -1)
		{
			sum_g = sum_g + o[i];
			w++;
		}
		y++;
		sum_h = sum_h - sum_g;
	}

	if (w == 1)
	{
		cout << endl << "___________________________________________________________________________" << endl << endl;
		cout << "Первый элемент массива - голова змеи" << endl;
		cout << "___________________________________________________________________________" << endl << endl;
	}
	else if ((w == 2) || (w == 3) || (w == 4))
	{
		cout << endl << "___________________________________________________________________________" << endl << endl;
		cout << "Первые " << w << " элемента массива - голова змеи" << endl;
		cout << "___________________________________________________________________________" << endl << endl;
	}
	else
	{
		cout << endl << "___________________________________________________________________________" << endl << endl;
		cout << "Первые " << w << " элементов массива - голова змеи" << endl;
		cout << "___________________________________________________________________________" << endl << endl;
	}
	return 0;
}

