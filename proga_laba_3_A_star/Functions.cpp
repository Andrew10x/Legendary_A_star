#include "Header.h"

void read_field_from_file(const char* file_name, int*** arr, int* arrRows, int* arrCols)
{
	ifstream file(file_name);

	if (!file.is_open())
		return;

	int rows = 0, cols = 0;
	string str;

	getline(file, str);
	cols = str.size();
	rows++;

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
	for (int i = 0; i < rows; i++)
	{
		getline(file, str);

		for (int j = 0; j < cols; j++)
		{
			if (str[j] == 'X')
				(*arr)[i][j] = 0;
			else
				(*arr)[i][j] = 1;
		}
	}
	file.close();

}

cell::cell()
{
	 f = INT_MAX;
	 g = INT_MAX;
	 h = INT_MAX;
	 parent = NULL;
}

Astar::Astar(int rows, int cols)
{
	Rows = rows;
	Cols = cols;
	arr = new int* [rows];
	maze_details = new cell * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		maze_details[i] = new cell[cols];
	}
}


void Astar::setArr(int** arr0)
{
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++)
		 arr[i][j] = arr0[i][j]; 
}


void Astar:: outputMaze()
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j]) cout << ' ';
			else cout << 'X'; cout << ' ';
		} cout << endl;
	} cout << endl;
}

bool Astar:: inMaze(int row, int col)
{
	if (row >= 0 && row < Rows && col >= 0 && col < Cols)
		return true;
	else 
		return false;
}

bool Astar::isPath(int row, int col)
{
	if (arr[row][col] == 1) return true;
	else 
		return false;
}

bool Astar::isFinish(int row, int col)
{
	if (row == finish.first && col == finish.second)
		return true;
	else return false;
}

void Astar::setH(int row, int col)
{
	maze_details[row][col].h = abs(finish.first - row)*10+abs(finish.second-col)*10;
}


void priorityQueue::add_cell(cell a)
{   
	queue.push_back(a);
	for (int i = 0; i < queue.size()-1; i++)
		for(int j = i+1; j< queue.size(); j++)
	{
			if (queue[i].f > queue[j].f)
				swap(queue[i], queue[j]);
	}
}

void priorityQueue::output()
{
	for (int i = 0; i < queue.size(); i++)
	{
		cout << queue[i].f << " ";
	}
}

cell priorityQueue::get_first()
{
	cell temp = queue[0];
	for (int i = 0; i < queue.size() - 1; i++)
		queue[i] = queue[i + 1];
	queue.pop_back();
	return temp;
}

bool priorityQueue::is_empty()
{
	return (queue.empty());
}
