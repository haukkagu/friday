#include "Table.h"

#include <iostream>

int main() {
	Table table1(5, 5);

	table1.setCell("Monday", 0, 0);
	table1.setCell("Tuesday", 1, 0);
	table1.setCell("Wednesday", 2, 0);
	table1.setCell("Thursday", 3, 0);
	table1.setCell("Friday", 4, 0);

	table1.print();

	return 0;
}