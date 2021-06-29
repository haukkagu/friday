#pragma once
#include "Table.h"

#include <string>

class CalendarTable : public Table {
private:
	int first_week;
	int last_week;
public:
	CalendarTable(int first_week, int last_week);

	void setDay(std::string value, int week, int weekday);
};