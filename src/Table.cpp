#include "Table.h"

#include <iostream>
#include <algorithm>

Table::Table(TABLE_MATRIX cells) : m_cells(cells) {
	m_column_count = cells.size();
	m_row_count = cells[0].size();
}

Table::Table(int column_count, int row_count)
	: m_row_count(row_count), m_column_count(column_count) {
	m_cells = TABLE_MATRIX(column_count, std::vector<std::string>(row_count, ""));
}

void Table::setCell(std::string value, int column_index, int row_index) {
	m_cells[column_index][row_index] = value;
}

void Table::setRow(std::vector<std::string> value, int row_index) {
	for (int c = 0; c < m_column_count; c++) {
		m_cells[c][row_index] = value[c];
	}
}

void Table::setColumn(std::vector<std::string> value, int column_index) {
	m_cells[column_index] = value;
}

size_t getWidthOfColumn(std::vector<std::string> column);
void printIntersection(std::vector<size_t> column_widths, char divide_char);

void Table::print() {
	std::vector<size_t> column_widths(m_column_count);
	for (int c = 0; c < m_column_count; c++) {
		column_widths[c] = getWidthOfColumn(m_cells[c]);
	}

	printIntersection(column_widths, ' ');
	for (int r = 0; r < m_row_count; r++) {
		for (int c = 0; c < m_column_count; c++) {
			std::cout << "|" << m_cells[c][r];

			for (size_t i = m_cells[c][r].size(); i < column_widths[c]; i++) {
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

void printIntersection(std::vector<size_t> column_widths, char divide_char) {
	for (int c = 0; c < column_widths.size(); c++) {
		std::cout << divide_char;
		for (int i = 0; i < column_widths[c]; i++) {
			std::cout << "_";
		}
	}
	std::cout << divide_char << "\n";
}
