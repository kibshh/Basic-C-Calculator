#include <stdio.h>
#include <math.h>


double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if((int)b != 0)
    {
        return a / b;       
    }
    else
    {
        printf("Division by zero not allowed\n");
        return NAN;
    }
}

typedef double(*operation)(double, double);

operation calc_ops[] = {
    ['+'] = add,
    ['-'] = subtract,
    ['*'] = multiply,
    ['/'] = divide
};

void read_number(char *message, double *storage_var)
{
    int success = 0;
    do
    {
        printf("%s", message);
        success = scanf("%lf", storage_var);
        if(1 != success)
        {
            printf("Invalid input. Try again.\n");
            while(getchar() != '\n');
        }
    } while (success != 1);
}

void read_char(char *message, char *operator)
{
    int success = 0;
    do 
    {
        printf("%s", message);
        if (scanf(" %c", operator) == 1 && calc_ops[*operator] != NULL) 
        {
            success = 1;
        } 
        else 
        {
            printf("Invalid operator. Try again.\n");
            while (getchar() != '\n');
        }
    } while (!success);
}


int main()
{
    double num1, num2;
    char operator;

    read_number("Enter first number: ", &num1);

    read_char("Enter operator (+, -, *, /): ", &operator);

    read_number("Enter second number: ", &num2);

    double result = (calc_ops[operator])(num1, num2);
    if(!isnan(result))
    {
        printf("%.2lf\n", result);
    }

    return 0;
}