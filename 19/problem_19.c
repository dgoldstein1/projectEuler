#include <stdio.h>

struct Tuple {
	int index; // index at first of next year
	int count; // number of days in that year
};

/**
 * calculates the number of sundays on the first day of the month for
 * @param {int} day the year started on (0 = sunday, 6 = saturday)
 * @param {int} year (i.e. 1900 - 2000)
 * @return {Tuple} { new index at beginning of next year, number of sundays on first day of month in that year}
 **/
struct Tuple sundaysOnFirstDay(int startingDay, int year) {

	// number of days in each month
	int daysInMonths[12] = {
		31, // january
		28, // february
		31, // march
		30, // april
		31, // may
		30, // june
		31, // july
		31, // august
		30, // september
		31, // october
		30, // nomvember
		31  // december
	};

	// update february if leap year
	int isLeapYear = // year is divisible by 4 AND (is not century or is 400th century)
		(year % 4 == 0) && ((year % 100 != 0) || year % 400 == 0);

	// if it's a leap year, february has an extra day
	if (isLeapYear) daysInMonths[1] = 29;

	// go through months adding if index is on first
	// for (int i = 0; i < 12; ++i) {
	// 	if (startingDay == 0) * currCount ++;

	// }

	// TODO
	struct Tuple t = { 1, 1 };

	return t;

}

int main() {
	
	// number of sundays on first of the month
	int sundaysOnFirst = 0;
	int currIndex = 1; // 1 jan 1901 is a monday

	// loop through years Jan 1901 => Dec 31 2000
	for (int year = 1900; year <= 2000; ++year) {
		Tuple t = sundaysOnFirstDay(currIndex, year);
		sundaysOnFirst += t.count;
		currIndex = t.index;
	}
	printf("%i\n", sundaysOnFirst);
	return 0;
}
