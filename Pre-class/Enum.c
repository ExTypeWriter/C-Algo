#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    ERROR_DATE
} Weekdays;

Weekdays dayInput()
{
    char day[256] = {'\0'};
    char *token;
    bool inputCheck = false;
    while (!inputCheck)
    {
        printf("Input day ( full name ): ");
        if (fgets(day, sizeof(day), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return 1;
        }
        if (day[strlen(day) - 1] == '\n')
        {
            day[strlen(day) - 1] = '\0';
        }
        for (int i = 0; day[i]; i++)
        {
            day[i] = tolower(day[i]);
        }
        if (strcmp(day, "monday") == 0)
            return MONDAY;
        if (strcmp(day, "tuesday") == 0)
            return TUESDAY;
        if (strcmp(day, "wednesday") == 0)
            return WEDNESDAY;
        if (strcmp(day, "thursday") == 0)
            return THURSDAY;
        if (strcmp(day, "friday") == 0)
            return FRIDAY;
        if (strcmp(day, "saturday") == 0)
            return SATURDAY;
        if (strcmp(day, "sunday") == 0)
            return SUNDAY;
        return ERROR_DATE;
    }
}

int main()
{
    Weekdays today = dayInput();
    if(today == ERROR_DATE){
        printf("Invalid day input exiting..\n");
        return 0;
    }
    if (today == WEDNESDAY)
    {
        printf("It's Wednesday!\n");
    }

    return 0;
}
