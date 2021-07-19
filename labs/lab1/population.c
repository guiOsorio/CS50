#include <stdio.h>

// this program determines how long it takes for a population to reach a certain size

int main(void)
{
    // Get starting and ending sizes
    int current;
    do
    {
        printf("Start size: ");
        scanf("%d", &current);
    }
    while(current < 9);
    int end;
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    }
    while(end < current);
    // Initialize a year variable to store how long it will take
    int year = 0;
    // Loop that checks how many years for a population to reach the end size
    while(current < end)
    {
        int born = current / 3;
        int dead = current / 4;
        current += born;
        current -= dead;
        year++;
    }
    printf("Years: %i\n", year);
}
