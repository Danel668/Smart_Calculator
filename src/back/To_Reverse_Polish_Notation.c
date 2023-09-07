#include "To_Reverse_Polish_Notation.h"

Stack To_Reverse_Polish_Notation(Stack input) {
  Stack output;
  initializeStack(&output);

  Stack support;
  initializeStack(&support);

  while (input.top != NULL) {
    StackNode tmp = pop(&input);

    // число
    if (tmp.priority == 0) {
      push(&output, tmp.value, tmp.priority, tmp.type);
    }
    // функция или открывающая скобка
    else if (tmp.priority == 4 || tmp.type == 16) {
      push(&support, tmp.value, tmp.priority, tmp.type);
    }
    // бинарный оператор
    else if (tmp.priority >= 1 && tmp.priority <= 3) {
      while (support.top != NULL) {
        StackNode peek = pop(&support);

        if (peek.priority > tmp.priority) {
          push(&output, peek.value, peek.priority, peek.type);
        } else {
          push(&support, peek.value, peek.priority, peek.type);
          break;
        }
      }
      push(&support, tmp.value, tmp.priority, tmp.type);
    }
    // закрывающая скобка
    else if (tmp.type == 17) {
      while (support.top != NULL) {
        StackNode peek = pop(&support);

        if (peek.type == 16) break;

        push(&output, peek.value, peek.priority, peek.type);
      }

      if (support.top != NULL) {
        StackNode peek = pop(&support);
        if (peek.priority == 4) {
          push(&output, peek.value, peek.priority, peek.type);
        } else {
          push(&support, peek.value, peek.priority, peek.type);
        }
      }
    }
  }

  while (support.top != NULL) {
    StackNode peek = pop(&support);
    push(&output, peek.value, peek.priority, peek.type);
  }

  Stack reverse_Stack;
  initializeStack(&reverse_Stack);
  int stack_count = size(&output);

  while (stack_count > 0) {
    StackNode poppedNode = pop(&output);
    push(&reverse_Stack, poppedNode.value, poppedNode.priority,
         poppedNode.type);
    stack_count--;
  }

  return reverse_Stack;
}