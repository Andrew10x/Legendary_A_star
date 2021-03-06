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
	bool closed;
	pair<int, int> ij;
	cell* parent;
	cell();
};
class Astar
{
	int Rows;  // ����������� �����
	int Cols;  // ����������� �������
	int** arr; // �������� ���� ���
	cell** maze_details; //cell ��������
	pair<int, int> start;
	pair<int, int> finish;

public:
	Astar(int, int); // ������������� ��������
	void setMaze(int**);
	void setStart(int x, int y)
	{ start.first = x; start.second = y;}
	void setFinish(int x, int y)
	{ finish.first = x; finish.second = y;}

	bool inMaze(int, int);  //������� ��� �����
	bool isPath(int, int); 
	bool isFinish(int, int);

	int findH(int, int); // ����� � �����
	void outputMaze();
	void search();
	int search_side(int, int, int, int);
	void outputPath(int, int);
	void outputInFile(string);
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

class stack
{
	vector<pair<int, int>> stack;
public:
	void add(pair<int, int> p) { stack.push_back(p); }
	pair<int, int> get();
	bool is_empty() { return stack.empty(); }
};
