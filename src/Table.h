#pragma once
#include <vector>
#include <string>

using TABLE_MATRIX = std::vector<std::vector<std::string>>;

class Table {
public:
	int columns, rows;
	TABLE_MATRIX cells;

	Table(TABLE_MATRIX cells);
	Table(int columns, int rows);

	void setCell(std::string value, int column, int row);
	void print();
};