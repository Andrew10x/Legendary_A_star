#include "Header.h"


int main()
{
	int** field;
	int rows, cols;
	read_field_from_file("field.txt", &field, &rows, &cols);
	Astar way(rows, cols); 
	way.setArr(field);


}

