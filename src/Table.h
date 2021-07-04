#pragma once

#include <vector>
#include <string>

using TABLE_MATRIX = std::vector<std::vector<std::string>>;

class Table {
protected:
	int m_column_count, m_row_count;
	TABLE_MATRIX m_cells;
public:
	Table(TABLE_MATRIX cells);
	Table(int column_count, int row_count);

	inline int getColumnCount() { return m_column_count; }
	inline int getRowCount() { return m_row_count; }

	void setCell(std::string value, int column_index, int row_index);
	void setRow(std::vector<std::string> value, int row_index);
	void setColumn(std::vector<std::string> value, int column_index);

	void print();
};
