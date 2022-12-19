#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year);
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add);

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31}; 

int main() {
    int mm, dd, yy, days_left_to_add;
    printf("Enter a date bt 1800 and 10000 (mm dd yy \"days to add\"):\n");
    scanf("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("New date: %d %d %d", mm, dd, yy);
}

bool is_leap_year(int year){
  if(year % 4 == 0){
    if(year % 100 == 0){
      if (year % 400 == 0){
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add){
  
  int days_left_in_month;

  while(days_left_to_add > 0){
    days_left_in_month = days_in_month[*mm] - *dd;
    
    if (*mm == 2 && is_leap_year(*yy)){
      days_left_in_month++;
    } 

    if (days_left_to_add > days_left_in_month){
      days_left_to_add -= days_left_in_month;
      days_left_to_add --;
      *dd = 1;
      if (*mm == 12){
        *mm = 1;
        *yy += 1; 
        } else {
          *mm += 1;
        }
    } else {
      *dd += days_left_to_add;
      days_left_to_add = 0;
    }

    // For debugging: 
    // printf("Days left in month: %d\n", days_left_in_month);
    // printf("Date in while loop: %d %d %d\n", *mm, *dd, *yy);
  }
}