#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
public:
	Astar(int, int);
	void setArr(int**);
	void outputMaze();

};