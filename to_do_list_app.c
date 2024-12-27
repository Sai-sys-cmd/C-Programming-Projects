#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 100

char tasks[MAX_TASKS][MAX_TASK_LENGTH];
int taskCount = 0;

void addTask() 
{
    if (taskCount < MAX_TASKS) 
    {
        printf("Enter task: ");
        fgets(tasks[taskCount], MAX_TASK_LENGTH, stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0';
        taskCount++;
        printf("Task added successfully!\n\n");
    } 
    else 
    {
        printf("Task list is full! Can't add more tasks.\n\n");
    }
}

void viewTasks() 
{
    if (taskCount == 0) 
    {
        printf("\nNo tasks to show.\n\n");
    } 
    else 
    {
        printf("\n==== Your To-Do List ====\n");
        for (int i = 0; i < taskCount; i++) 
        {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
        printf("\n");
    }
}

void deleteTask() 
{
    int taskNumber;
    printf("Enter task number to delete: ");
    scanf("%d", &taskNumber);
    getchar();

    if (taskNumber >= 1 && taskNumber <= taskCount) 
    {
        for (int i = taskNumber - 1; i < taskCount - 1; i++) 
        {
            strcpy(tasks[i], tasks[i + 1]);
        }
        taskCount--;
        printf("Task deleted successfully!\n\n");
    } 
    else 
    {
        printf("Invalid task number.\n\n");
    }
}

int main() 
{
    int choice;
    
    while (1) 
    {
        printf("==== To-Do List Application ====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar();

        if (choice == 1) 
        {
            addTask();
        } 
        else if (choice == 2) 
        {
            viewTasks();
        } 
        else if (choice == 3) 
        {
            deleteTask();
        } 
        else if (choice == 4) 
        {
            printf("Goodbye! Have a nice day!\n");
            break;
        } 
        else 
        {
            printf("Invalid option. Please try again.\n\n");
        }
    }
    
    return 0;
}
