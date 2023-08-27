#include <stdio.h>

int main() {
	int x;
	int second;
	int minute;
	int hour;
	int day;

	printf("masukkan detik:"), scanf_s("%d", &x);

	second = x % 60;
	x = x - x % 60;

	minute = x / 60 % 60;
	x = x - minute * 60;

	hour = x / 3600 % 24;
	x = x - hour * 3600;

	day = x / 86400;

	printf("Ada %d hari, %d jam, %d menit, %d detik\n", day, hour, minute, second);

	return 0;

}
