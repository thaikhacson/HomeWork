#include <stdio.h>

int DayofWeek(int day, int month, int year) {
    int h, q, m, K, J;
    // h là ngày trong tuần (0 = Thứ Bảy, 1 = Chủ Nhật, 2 = Thứ Hai, …, 6 = Thứ Sáu)
    // q là ngày trong tháng
    // m là tháng (3 = tháng 3, 4 = tháng 4, 5 = tháng 5, …, 14 = tháng 2)
    // K là năm của thế kỷ (năm %100).
    // J là thế kỷ dựa trên số 0 (thực tế là ⌊ năm/100 ⌋) 
    if(month == 1) {
        month = 13;
        year--;
    }
    if(month == 2) {
        month = 14;
        year--;
    } 

    q = day; m = month; K = year % 100; J = year / 100;
    h = q + 13 * (m + 1) / 5 + K / 4 + K + J / 4 + 5 * J;
    h = h % 7;

    switch (h)
    {
    case 0:
        printf("Saturday");
        break;
    case 1: 
        printf("Sunday");
        break;
    case 2:
        printf("Monday");
        break;
    case 3:
        printf("Tuesday");
        break;
    case 4:
        printf("Wednesday");
        break;
    case 5:
        printf("Thursday");
        break;
    case 6:
        printf("Friday");
        break;
    }
    return 0;
}

int main() {
    int day, month, year;
    DayofWeek(3, 10, 2023);
    return 0;
}