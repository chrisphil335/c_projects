#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
unsigned char stack[STACK_SIZE];
int stack_pointer = -1;


void push(unsigned char value)
{
    if(stack_pointer >= STACK_SIZE - 1)
    {
        printf("The stack is full!");
        return;
    }
    else
    {
        stack_pointer += 1;
        stack[stack_pointer] = value;
    }
}


unsigned char pop()
{
    if(stack_pointer < 0)
    {
        printf("The stack is empty!");
        return 0;
    }
    else
    {
        unsigned char value = stack[stack_pointer];
        stack_pointer -= 1;
        return value;
    }
}


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("No user arguments!\n");
        return 0;
    }
    for(int i = 1; i < argc; i += 1)
    {
        if(strcmp(argv[i], "+") == 0)
        {
            // handle addition
            if(stack_pointer < 1)
            {
                printf("Not enough operands for addition!\n");
                return 1;
            }
            unsigned char operand_2 = pop();
            unsigned char operand_1 = pop();
            unsigned char result = operand_1 + operand_2;
            push(result);
        }
        else if(strcmp(argv[i], "-") == 0)
        {
            // handle subtraction
            if(stack_pointer < 1)
            {
                printf("Not enough operands for subtraction!\n");
                return 1;
            }
            unsigned char operand_2 = pop();
            unsigned char operand_1 = pop();
            unsigned char result = operand_1 - operand_2;
            push(result);
        }
        else if(strcmp(argv[i], "*") == 0)
        {
            // handle multiplication
            if(stack_pointer < 1)
            {
                printf("Not enough operands for multiplication!\n");
                return 1;
            }
            unsigned char operand_2 = pop();
            unsigned char operand_1 = pop();
            unsigned char result = operand_1 * operand_2;
            push(result);
        }
        else if(strcmp(argv[i], "/") == 0)
        {
            // handle division
            if(stack_pointer < 1)
            {
                printf("Not enough operands for division!\n");
                return 1;
            }
            unsigned char operand_2 = pop();
            unsigned char operand_1 = pop();
            if(operand_2 == 0)
            {
                printf("Error: division by 0!\n");
                return 1;
            }
            unsigned char result = operand_1 / operand_2;
            push(result);
        }
        else
        {
            int value = atoi(argv[i]);
            unsigned char unsigned_char_value = (unsigned char)value;
            push(unsigned_char_value);
        }
    }
    if(stack_pointer != 0)
    {
        printf("Error: Too many operands remaining on the stack!\n");
        return 1;
    }
    unsigned char final_result = stack[stack_pointer];
    printf("final result: %u\n", final_result);
    return 0;
}