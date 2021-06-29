#include "Table.h"

#include <iostream>
#include <algorithm>

Table::Table(TABLE_MATRIX cells) : cells(cells) {
	column_count = cells.size();
	row_count = cells[0].size();
}

Table::Table(int column_count, int row_count)
	: row_count(row_count), column_count(column_count) {
	cells = TABLE_MATRIX(column_count, std::vector<std::string>(row_count, ""));
}

void Table::setCell(std::string value, int column_index, int row_index) {
	cells[column_index][row_index] = value;
}

void Table::setRow(std::vector<std::string> value, int row_index) {
	for (int c = 0; c < column_count; c++) {
		cells[c][row_index] = value[c];
	}
}

void Table::setColumn(std::vector<std::string> value, int column_index) {
	cells[column_index] = value;
}

size_t getWidthOfColumn(std::vector<std::string> column);
void printIntersection(std::vector<size_t> column_widths, char divideChar);

void Table::print() {
	std::vector<size_t> column_widths(column_count);
	for (int c = 0; c < column_count; c++) {
		column_widths[c] = getWidthOfColumn(cells[c]);
	}

	printIntersection(column_widths, ' ');
	for (int r = 0; r < row_count; r++) {
		for (int c = 0; c < column_count; c++) {
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
