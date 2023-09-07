#ifndef C_STACK_H
#define C_STACK_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS "1234567890"
#define DIGITS_AND_DOT "1234567890."
#define UNAR_OPERAION "coslnlogsintansqrtasinacosatan"
#define FIRST_SYMBOL_UNAR_OPERAION "clsta"
#define OPERAION "+-*/mod"

// Структура для элемента стека
typedef struct StackNode {
  double value;
  int priority;
  int type;
  struct StackNode *next;
} StackNode;

// Структура для стека
typedef struct {
  StackNode *top;
} Stack;

void initializeStack(Stack *stack);
void push(Stack *stack, double value, int priority, int type);
StackNode pop(Stack *stack);
int size(const Stack *stack);

#endif  // C_STACK_H
