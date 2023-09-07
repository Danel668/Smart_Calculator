
#include "calculate.h"

double Calculate(Stack input) {
  Stack numbers;
  initializeStack(&numbers);

  while (input.top != NULL) {
    StackNode tmp = pop(&input);

    // если число
    if (tmp.priority == 0) {
      push(&numbers, tmp.value, tmp.priority, tmp.type);
    } else {
      if (tmp.type == 1) {
        StackNode op2 = pop(&numbers);
        StackNode op1 = pop(&numbers);

        push(&numbers, op1.value + op2.value, 0, 0);
      } else if (tmp.type == 2) {
        StackNode op2 = pop(&numbers);
        StackNode op1 = pop(&numbers);

        push(&numbers, op1.value - op2.value, 0, 0);
      } else if (tmp.type == 3) {
        StackNode op2 = pop(&numbers);
        StackNode op1 = pop(&numbers);

        push(&numbers, op1.value * op2.value, 0, 0);
      } else if (tmp.type == 4) {
        StackNode op2 = pop(&numbers);
        StackNode op1 = pop(&numbers);

        push(&numbers, op1.value / op2.value, 0, 0);
      } else if (tmp.type == 5) {
        StackNode op2 = pop(&numbers);
        StackNode op1 = pop(&numbers);

        int oper1 = (int)op1.value;
        int oper2 = (int)op2.value;

        push(&numbers, oper1 % oper2, 0, 0);
      } else if (tmp.type == 6) {
        StackNode op2 = pop(&numbers);
        StackNode op1 = pop(&numbers);

        push(&numbers, pow(op1.value, op2.value), 0, 0);
      } else if (tmp.type == 7) {
        StackNode op1 = pop(&numbers);

        push(&numbers, sin(op1.value), 0, 0);
      } else if (tmp.type == 8) {
        StackNode op1 = pop(&numbers);

        push(&numbers, cos(op1.value), 0, 0);
      } else if (tmp.type == 9) {
        StackNode op1 = pop(&numbers);

        push(&numbers, tan(op1.value), 0, 0);
      } else if (tmp.type == 10) {
        StackNode op1 = pop(&numbers);

        push(&numbers, asin(op1.value), 0, 0);
      } else if (tmp.type == 11) {
        StackNode op1 = pop(&numbers);

        push(&numbers, acos(op1.value), 0, 0);
      } else if (tmp.type == 12) {
        StackNode op1 = pop(&numbers);

        push(&numbers, atan(op1.value), 0, 0);
      } else if (tmp.type == 13) {
        StackNode op1 = pop(&numbers);

        push(&numbers, sqrt(op1.value), 0, 0);
      } else if (tmp.type == 14) {
        StackNode op1 = pop(&numbers);

        push(&numbers, log(op1.value), 0, 0);
      } else if (tmp.type == 15) {
        StackNode op1 = pop(&numbers);

        push(&numbers, log10(op1.value), 0, 0);
      } else if (tmp.type == 18) {
        StackNode op1 = pop(&numbers);

        push(&numbers, -1 * op1.value, 0, 0);
      }
    }
  }

  double ans = 0;

  while (numbers.top != NULL) {
    ans += pop(&numbers).value;
  }

  return ans;
}