#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read_field_from_file(const char*, int***, int*, int*);
struct cell
{
	int f, g, h;
	cell* parent;
	cell();
};
class Astar
{
	int Rows;  // колличество строк
	int Cols;  // колличество колонок
	int** arr; // лабиринт типа инт
	cell** maze_details;
	pair<int, int> start;
	pair<int, int> finish;
public:
	Astar(int, int);
	void setArr(int**);
	void setH(int, int);
	void setStart(int x, int y)
	{
		start.first = x; start.second = y;
	}

	void setFinish(int x, int y)
	{
		finish.first = x; finish.second = y;
	}

	void outputMaze();
	bool inMaze(int, int);
	bool isPath(int, int);
	bool isFinish(int, int);

};

class priorityQueue
{
	vector<cell> queue;
public:
	void add_cell(cell);
	void output();
	cell get_first();
	bool is_empty();
};