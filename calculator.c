/*
 * calculator.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Mohamed Abosreea
 */
#include "calculator.h"

#include <string.h>
#include <ctype.h>  // Include this header for isdigit() function

uint16 flag = 0 ;
// Function to check if a character is an operator
uint16 isOperator(uint8 ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
// Function to get precedence of operators
uint16 getPrecedence(uint8 operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0; // For '('
}

// Function to perform arithmetic operations
f32 performOperation(f32 operand1, f32 operand2, uint8 operator)
{
    switch (operator)
    {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;
    default:  return 0; // Invalid operator
    }
}

// Function to evaluate infix expression
f32 evaluateInfixExpression(uint8 expression[])
{
    f32 operandStack[20]; // Array to store operands
    sint8 operatorStack[20]; // Array to store operators
    sint16 operandTop = -1;
    sint16 operatorTop = -1;
    sint16 i = 0 ;
    // check expression

    if (isOperator(expression[0]) || isOperator(expression[strlen(expression) - 1]))
    {
        flag = 1 ;
    }
    else
    {
        for (i = 0; expression[i] != '\0'; i++)
        {
            if (isOperator(expression[i]) && isOperator(expression[i+1]))
            {
                flag = 1 ;
                break ;
            }
            if (isdigit(expression[i]) && expression[i+1] == '/' && expression[i+2] == '0')
            {
                flag = 2 ;
                break ;
            }
        }
    }
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            f32 operand = 0.0;
            while (isdigit(expression[i]))
            {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Move back one step after the loop
            ++operandTop ;
            operandStack[operandTop] = operand;
        }
        else if (isOperator(expression[i]))
        {
            while (operatorTop != -1 &&
                    getPrecedence(expression[i]) <= getPrecedence(operatorStack[operatorTop]))
            {
                f32 operand2 = operandStack[operandTop--];
                f32 operand1 = operandStack[operandTop--];
                uint8 operator = operatorStack[operatorTop--];
                f32 result = performOperation(operand1, operand2, operator);
                operandStack[++operandTop] = result;
            }
            operatorStack[++operatorTop] = expression[i];
        }
    }

    while (operatorTop != -1)
    {
        f32 operand2 = operandStack[operandTop--];
        f32 operand1 = operandStack[operandTop--];
        uint8 operator = operatorStack[operatorTop--];
        f32 result = performOperation(operand1, operand2, operator);
        operandStack[++operandTop] = result;
    }

    return operandStack[operandTop];
}


