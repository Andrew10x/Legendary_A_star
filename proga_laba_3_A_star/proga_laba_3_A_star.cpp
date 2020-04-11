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
}

