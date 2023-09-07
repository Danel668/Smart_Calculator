#include "c_stack.h"

// Инициализация стека
void initializeStack(Stack *stack) { stack->top = NULL; }

// Добавление элемента в стек
void push(Stack *stack, double value, int priority, int type) {
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  if (newNode == NULL) {
    return;
  }

  newNode->value = value;
  newNode->priority = priority;
  newNode->type = type;
  newNode->next = stack->top;

  stack->top = newNode;
}

// Удаление верхнего элемента стека и возврат его
StackNode pop(Stack *stack) {
  if (stack->top == NULL) {
    StackNode emptyNode = {0.0, 0, 0, NULL};  // Возвращаем пустую структуру
    return emptyNode;
  }

  StackNode *temp = stack->top;
  StackNode poppedNode = *temp;
  stack->top = temp->next;
  free(temp);

  return poppedNode;
}

int size(const Stack *stack) {
  int count = 0;
  StackNode *current = stack->top;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}