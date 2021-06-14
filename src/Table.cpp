#include "Table.h"

#include <iostream>
#include <algorithm>

Table::Table(TABLE_MATRIX cells) : cells(cells) {
	columns = cells.size();
	rows = cells[0].size();
}

Table::Table(int columns, int rows)
	: rows(rows), columns(columns) {
	cells = TABLE_MATRIX(columns, std::vector<std::string>(rows, ""));
}

void Table::setCell(std::string value, int column, int row) {
	cells[column][row] = value;
}

size_t getWidthOfColumn(std::vector<std::string> column);
void printIntersection(std::vector<size_t> column_widths, char divideChar);

void Table::print() {
	std::vector<size_t> column_widths(columns);
	for (int c = 0; c < columns; c++) {
		column_widths[c] = getWidthOfColumn(cells[c]);
	}

	printIntersection(column_widths, ' ');
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			std::cout << "|" << cells[c][r];

			for (size_t i = cells[c][r].size(); i < column_widths[c]; i++) {
				std::cout << " ";
			}
		}
		std::cout << "|\n";

		printIntersection(column_widths, '|');
	}
}

// HELPER FUNCTIONS
size_t getWidthOfColumn(std::vector<std::string> column) {
	size_t widest_cell = 0;
	for (int i = 0; i < column.size(); i++) {
		widest_cell = std::max(widest_cell, column[i].size());
	}

	return widest_cell;
}

void printIntersection(std::vector<size_t> column_widths, char divideChar) {
	for (int c = 0; c < column_widths.size(); c++) {
		std::cout << divideChar;
		for (int i = 0; i < column_widths[c]; i++) {
			std::cout << "_";
		}
	}
	std::cout << divideChar << "\n";
}
