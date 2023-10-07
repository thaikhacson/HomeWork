#include <stdio.h>

int DayofWeek(int day, int month, int year) {
    // Mảng chứa số ngày trong mỗi tháng
    int DayofMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận và cập nhật số ngày trong tháng 2
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        DayofMonth[2] = 29;
    }
    // Tính tổng số ngày từ ngày 1/1/1 đến ngày cần kiểm tra
    int totalDays = 0;
    for (int y = 1; y < year; y++) {
        totalDays += 365;
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            totalDays++;
        }
    }

    for (int m = 1; m < month; m++) {
        totalDays += DayofMonth[m];
    }

    totalDays += day;

    // Xác định ngày trong tuần
    int dayOfWeek = (totalDays % 7);

    switch (dayOfWeek) {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }
    return 0;
}

int main() {
    int day, month, year;
    printf("Day: ");
    scanf("%d",&day);
    printf("Month: ");
    scanf("%d",&month);
    printf("Year: ");
    scanf("%d", &year);
    DayofWeek(day, month, year);
    return 0;
}