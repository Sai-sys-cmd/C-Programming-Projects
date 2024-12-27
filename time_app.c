#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

#define TIMEZONE_OFFSET -5
#define WORK_SESSION 25
#define BREAK_SESSION 5

void showMenu()
{
    printf("\n===== Time App =====\n");
    printf("1. Set Alarm\n");
    printf("2. Stopwatch\n");
    printf("3. Timer\n");
    printf("4. Real-Time Clock\n");
    printf("5. Pomodoro\n");
    printf("6. Exit\n");
    printf("\nPress 'q' to exit anytime.\n");
    printf("Choose an option: ");
}

int checkKeyPress()
{
    struct timeval tv = {0, 0};
    fd_set fds;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

void setAlarm()
{
    int hour, minute;
    char exitChoice;

    printf("\nEnter alarm time (hour minute): ");
    scanf("%d %d", &hour, &minute);

    printf("\nAlarm set for %02d:%02d\n", hour, minute);

    while (1)
    {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        tm_info->tm_hour += TIMEZONE_OFFSET;

        int remainingHours = hour - tm_info->tm_hour;
        int remainingMinutes = minute - tm_info->tm_min;

        if (remainingMinutes < 0)
        {
            remainingMinutes += 60;
            remainingHours -= 1;
        }

        if (remainingHours < 0)
        {
            remainingHours += 24;
        }

        printf("\rTime until alarm: %02d:%02d", remainingHours, remainingMinutes);
        fflush(stdout);

        if (remainingHours == 0 && remainingMinutes == 0)
        {
            printf("\nTime's up! Alarm triggered!\n");
            break;
        }

        sleep(1);
    }

    printf("\nPress 'q' to exit or any other key to return to menu: ");
    scanf(" %c", &exitChoice);

    if (exitChoice == 'q')
    {
        return;
    }
}

void startStopwatch()
{
    char exitChoice;
    int seconds = 0;

    printf("\nStopwatch started.\n");

    while (1)
    {
        printf("\rStopwatch: %02d:%02d:%02d", seconds / 3600, (seconds / 60) % 60, seconds % 60);
        fflush(stdout);
        sleep(1);
        seconds++;

        if (checkKeyPress())
        {
            scanf(" %c", &exitChoice);

            if (exitChoice == 'q')
            {
                break;
            }
        }
    }

    printf("\nStopwatch stopped. Final time: %02d:%02d:%02d\n", seconds / 3600, (seconds / 60) % 60, seconds % 60);
}

void startTimer()
{
    float minutes;
    char exitChoice;
    int totalSeconds;

    printf("\nEnter timer duration (minutes): ");
    scanf("%f", &minutes);

    totalSeconds = (int)(minutes * 60);

    while (totalSeconds > 0)
    {
        printf("\rTime remaining: %02d:%02d", totalSeconds / 60, totalSeconds % 60);
        fflush(stdout);
        sleep(1);
        totalSeconds--;
    }

    printf("\nTime's up! Timer finished.\n");

    printf("\nPress 'q' to exit or any other key to return to menu: ");
    scanf(" %c", &exitChoice);

    if (exitChoice == 'q')
    {
        return;
    }
}

void showRealTimeClock()
{
    char exitChoice;

    while (1)
    {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        tm_info->tm_hour += TIMEZONE_OFFSET;

        printf("\rCurrent time: %02d:%02d:%02d", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
        fflush(stdout);
        sleep(1);

        if (checkKeyPress())
        {
            scanf(" %c", &exitChoice);

            if (exitChoice == 'q')
            {
                return;
            }
        }
    }
}

void startPomodoro()
{
    char exitChoice;
    int workTime = WORK_SESSION * 60;
    int breakTime = BREAK_SESSION * 60;

    while (1)
    {
        while (workTime > 0)
        {
            printf("\rWork session: %02d:%02d", workTime / 60, workTime % 60);
            fflush(stdout);
            sleep(1);
            workTime--;

            if (checkKeyPress())
            {
                scanf(" %c", &exitChoice);

                if (exitChoice == 'q')
                {
                    return;
                }
            }
        }

        printf("\nWork session complete! Time for a break.\n");

        while (breakTime > 0)
        {
            printf("\rBreak session: %02d:%02d", breakTime / 60, breakTime % 60);
            fflush(stdout);
            sleep(1);
            breakTime--;

            if (checkKeyPress())
            {
                scanf(" %c", &exitChoice);

                if (exitChoice == 'q')
                {
                    return;
                }
            }
        }

        printf("\nBreak session complete! Time to work again.\n");
    }
}

int main()
{
    char choice;

    while (1)
    {
        showMenu();
        scanf(" %c", &choice);
        getchar();

        if (choice == '1')
        {
            setAlarm();
        }
        else if (choice == '2')
        {
            startStopwatch();
        }
        else if (choice == '3')
        {
            startTimer();
        }
        else if (choice == '4')
        {
            showRealTimeClock();
        }
        else if (choice == '5')
        {
            startPomodoro();
        }
        else if (choice == '6' || choice == 'q')
        {
            printf("\nGoodbye!\n");
            break;
        }
        else
        {
            printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}
