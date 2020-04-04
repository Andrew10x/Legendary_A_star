#include "Header.h"


int main()
{
	int** field;
	int rows, cols;
	read_field_from_file("field.txt", &field, &rows, &cols);
	Astar way(rows, cols); 
	way.setArr(field);
	way.outputMaze();

	int x, y;
	cout << "Input start point: " <<endl;
	cin >> x; cin >> y;
	way.setStart(x, y);
	cout << "Input finish point: " << endl;
	cin >> x; cin >> y;
	way.setFinish(x, y);

}

