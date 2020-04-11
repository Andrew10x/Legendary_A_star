#include "Header.h"


int main()
{
	int** field;
	int rows, cols;
	read_field_from_file("field.txt", &field, &rows, &cols);
	Astar way(rows, cols); 
	way.setMaze(field);
	way.outputMaze();

	int x, y;
	cout << "Input start point: " <<endl;
	cin >> x; cin >> y;
	way.setStart(x-1, y-1);
	cout << "Input finish point: " << endl;
	cin >> x; cin >> y;
	way.setFinish(x-1, y-1);

	way.search();
	//cell a, b, c, d, dd, rrr;
	//priorityQueue q;
	//
	//a.f = 2;
	//b.f = 1;
	//c.f = 3;
	//d.f = 1;
	//dd.f = 13;
	//rrr.f = -5;
	//q.add_cell(a);
	//q.add_cell(b);
	//q.add_cell(c);
	////q.add_cell(d);
	////q.add_cell(dd);
	//q.add_cell(rrr);
	//q.output();
	//cout << endl << q.get_first().f << endl;
	//cout << q.get_first().f << endl;
	//cout << "Output" << endl;
	//q.output();
	//if (q.is_empty())
	//	cout << "hhhhhhhhh";

}

