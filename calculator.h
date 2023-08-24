/*
 * calculator.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed Abosreea
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "std_lib.h"
#include "std_types.h"

// Function to check if a character is an operator
uint16 isOperator(uint8 ch) ;

// Function to get precedence of operators
uint16 getPrecedence(uint8 operator) ;

// Function to perform arithmetic operations
f32 performOperation(f32 operand1, f32 operand2, uint8 operator) ;

// Function to evaluate infix expression
f32 evaluateInfixExpression(uint8 expression[]) ;

#endif /* CALCULATOR_H_ */
