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
	 closed = false;
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


void Astar::setMaze(int** arr0)
{
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = arr0[i][j];
			maze_details[i][j].ij.first = i;
			maze_details[i][j].ij.second = j;
		}
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

int Astar::findH(int row, int col)
{
	int h = abs(finish.first - row)*10+abs(finish.second-col)*10;
	return h;
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

bool Astar::conditions(int i, int j)
{
	if (inMaze(i, j) && isPath(i, j)) return true;
	else return false;
}

void Astar::search()
{
	if (!(inMaze(start.first, start.second) || inMaze(finish.first, finish.second)))
	{
		cout << "Start or finish isn't in the maze!" << endl;
		return;
	}

	if (!(isPath(start.first, start.second) || isPath(finish.first, finish.second)))
	{
		cout << "Start or finish is blocked!" << endl;
		return;
	}

	if (isFinish(start.first, start.second))
	{
		cout << "We have riched our destination!" << endl;
		return;
	}

	int i, j; // координаты
	i = start.first;
	j = start.second;
	maze_details[i][j].f = 0;
	maze_details[i][j].g = 0;
	maze_details[i][j].h = 0;
	priorityQueue q;
	q.add_cell(maze_details[i][j]);

	while (!q.is_empty())
	{
		cell temp = q.get_first();
		i = temp.ij.first;
		j = temp.ij.second;
		maze_details[i][j].closed = true;

		int g1, h1, f1, i1, j1, k;

		// North
	    i1 = i - 1;
		j1 = j;
		k = search_side(i, j, i1, j1);
		if (k == 1) return;
		if(k == 2) q.add_cell(maze_details[i1][j1]);

		//South
		i1 = i + 1;
		j1 = j;
		k = search_side(i, j, i1, j1);
		if (k == 1) return;
		if (k == 2) q.add_cell(maze_details[i1][j1]);

		//West
		i1 = i;
		j1 = j-1;
		k = search_side(i, j, i1, j1);
		if (k == 1) return;
		if (k == 2) q.add_cell(maze_details[i1][j1]);

		//East
		i1 = i;
		j1 = j+1;
		k = search_side(i, j, i1, j1);
		if (k == 1) return;
		if (k == 2) q.add_cell(maze_details[i1][j1]);
	}

	cout << "The path doesn't exist!" << endl;
	exit(1);
}

int Astar::search_side(int i, int j, int i1, int j1)
{   
	int g1, h1, f1;
	if (isFinish(i1, j1))
	{
		cout << "We have riched our destination!";
		return 1;
	}
	if (inMaze(i1, j1) && isPath(i1, j1) && !maze_details[i1][j1].closed)
	{
		g1 = maze_details[i][j].g + 10;
		h1 = findH(i1, j1);
		f1 = g1 + h1;
		if (f1 < maze_details[i1][j1].f)
		{
			maze_details[i1][j1].f = f1;
			maze_details[i1][j1].g = g1;
			maze_details[i1][j1].h = h1;
			maze_details[i1][j1].parent = &maze_details[i][j];
			return 2;
		}
	} 
	return 0;
}