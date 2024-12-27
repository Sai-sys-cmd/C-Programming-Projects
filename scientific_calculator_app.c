#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2;
    int valid_input;

    while (1) {
        printf("\n==== Scientific Calculator ====\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Modulus\n");
        printf("6. Square Root\n");
        printf("7. Power\n");
        printf("8. Logarithm\n");
        printf("9. Trigonometry\n");
        printf("10. Exit\n");
        printf("-------------------------------\n");

        printf("Select an option (1-10): ");
        valid_input = scanf("%d", &choice);

        if (valid_input != 1) {
            printf("Invalid option. Please enter a number between 1 and 10.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {

            case 1:
                printf("\nEnter two numbers: ");
                valid_input = scanf("%lf %lf", &num1, &num2);
                if (valid_input != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", num1 + num2);
                break;

            case 2:
                printf("\nEnter two numbers: ");
                valid_input = scanf("%lf %lf", &num1, &num2);
                if (valid_input != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", num1 - num2);
                break;

            case 3:
                printf("\nEnter two numbers: ");
                valid_input = scanf("%lf %lf", &num1, &num2);
                if (valid_input != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", num1 * num2);
                break;

            case 4:
                printf("\nEnter two numbers: ");
                valid_input = scanf("%lf %lf", &num1, &num2);
                if (valid_input != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (num2 != 0) {
                    printf("Result: %.2lf\n", num1 / num2);
                } else {
                    printf("Can't divide by zero!\n");
                }
                break;

            case 5:
                printf("\nEnter two integers: ");
                valid_input = scanf("%lf %lf", &num1, &num2);
                if (valid_input != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.0lf\n", (int)num1 % (int)num2);
                break;

            case 6:
                printf("\nEnter a number: ");
                valid_input = scanf("%lf", &num1);
                if (valid_input != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (num1 >= 0) {
                    printf("Result: %.2lf\n", sqrt(num1));
                } else {
                    printf("Can't find the square root of a negative number.\n");
                }
                break;

            case 7:
                printf("\nEnter base and exponent: ");
                valid_input = scanf("%lf %lf", &num1, &num2);
                if (valid_input != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", pow(num1, num2));
                break;

            case 8:
                printf("\nEnter a number: ");
                valid_input = scanf("%lf", &num1);
                if (valid_input != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (num1 > 0) {
                    printf("Result: %.2lf\n", log(num1));
                } else {
                    printf("Can't find log of non-positive numbers.\n");
                }
                break;

            case 9:
                printf("\nSelect trigonometric function:\n");
                printf("1. Sin\n");
                printf("2. Cos\n");
                printf("3. Tan\n");
                printf("----------------------------\n");

                int trig_choice;
                valid_input = scanf("%d", &trig_choice);
                if (valid_input != 1) {
                    printf("Invalid choice. Please enter 1, 2, or 3.\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter an angle in radians: ");
                valid_input = scanf("%lf", &num1);
                if (valid_input != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (trig_choice == 1) {
                    printf("Sin: %.2lf\n", sin(num1));
                } 
                else if (trig_choice == 2) {
                    printf("Cos: %.2lf\n", cos(num1));
                } 
                else if (trig_choice == 3) {
                    printf("Tan: %.2lf\n", tan(num1));
                } 
                else {
                    printf("Invalid trigonometric function.\n");
                }
                break;

            case 10:
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please select a valid option (1-10).\n");
        }

        printf("\n-----------------------------------------\n");
    }

    return 0;
}
