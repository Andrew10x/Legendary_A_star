#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_field_from_file(const char*, int***, int*, int*);

int main()
{
	int** field;
	int rows, cols;
	read_field_from_file("field.txt", &field, &rows, &cols);
	//cout << rows << " " << cols;
}

void read_field_from_file(const char* file_name, int*** arr, int* arrRows, int* arrCols)
{
	ifstream file(file_name);

	if (!file.is_open())
		return;

	int rows = 0, cols = 0;
	string str;

	//file >> str; cout << str;
	getline(file, str); //cout << str;
	cols = str.size();

	while (!file.eof())
	{
		getline(file, str);
		rows++;
	}

	*arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		(*arr)[i] = new int[cols];
	}

	*arrRows = rows;
	*arrCols = cols;

	file.close();

	file.open(file_name);
	if (!file.is_open())
	{
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		getline(file, str);

		for (int j = 0; j < cols; j++)
		{
			if (str[j] == 'X')
				(*arr)[i][j] = -1;
			else
				(*arr)[i][j] = 0;
		}
	}

	file.close();
}
