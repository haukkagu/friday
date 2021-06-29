#include "CalendarTable.h"

int weekCount(int first_week, int last_week) {
	int week_count = last_week - first_week + 1;

	// Happens after the turn of a new year
	if (last_week < first_week) {
		week_count = 52 - first_week;
		week_count += last_week + 1;
	}

	return week_count;
}

CalendarTable::CalendarTable(int first_week, int last_week) 
	: Table(8, weekCount(first_week, last_week) + 1) , first_week(first_week), last_week(last_week) {

	setRow({ "Week", "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday" }, 0);
	
	// Set week number column
	int weeks_left = row_count - 1;

	while (weeks_left--) {
		int week = (first_week + weeks_left - 1) % 52 + 1;
		setCell(std::to_string(week), 0, 1 + weeks_left);
	}
}

void CalendarTable::setDay(std::string value, int week, int weekday) {
	int column_index = weekday;
	int row_index = week-first_week+1;

	setCell(value, column_index, row_index);
}