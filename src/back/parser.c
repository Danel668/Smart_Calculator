#include "pars.h"

Stack ParseInTokens(char* str, double x) {
  Stack stack;
  initializeStack(&stack);

  char* first = str;

  while (*str != '\0') {
    char cur_ch = *str;

    if (strchr(DIGITS, (int)cur_ch) != NULL) {
      char tmp[256] = "";
      int i = 0;

      while (*str != '\0' && strchr(DIGITS_AND_DOT, (int)*str) != NULL) {
        tmp[i] = *str;
        str++;
        i++;
      }

      str -= 1;

      double res = strtod(tmp, NULL);
      push(&stack, res, 0, 0);
    } else if (cur_ch == 'x') {
      push(&stack, x, 0, 0);
    } else if (strchr(OPERAION, (int)cur_ch) != NULL) {
      if (cur_ch == '+') {
        push(&stack, 0, 1, 1);
      } else if (cur_ch == '-') {
        if (str == first || *(str - 1) == '(' ||
            strchr(OPERAION, (int)*(str - 1))) {
          push(&stack, 0, 2, 18);
        } else {
          push(&stack, 0, 1, 2);
        }

      } else if (cur_ch == '*') {
        push(&stack, 0, 2, 3);
      } else if (cur_ch == '/') {
        push(&stack, 0, 2, 4);
      } else if (cur_ch == 'm') {
        push(&stack, 0, 2, 5);
        str += 2;
      }
    } else if (cur_ch == '^') {
      push(&stack, 0, 3, 6);
    } else if (strchr(FIRST_SYMBOL_UNAR_OPERAION, (int)cur_ch) != NULL) {
      if (cur_ch == 's') {
        if (*(str + 1) == 'i') {
          push(&stack, 0, 4, 7);
          str += 2;
        } else if (*(str + 1) == 'q') {
          push(&stack, 0, 4, 13);
          str += 3;
        }
      } else if (cur_ch == 'c') {
        push(&stack, 0, 4, 8);
        str += 2;
      } else if (cur_ch == 't') {
        push(&stack, 0, 4, 9);
        str += 2;
      } else if (cur_ch == 'a') {
        if (*(str + 1) == 's') {
          push(&stack, 0, 4, 10);
        } else if (*(str + 1) == 'c') {
          push(&stack, 0, 4, 11);
        } else if (*(str + 1) == 't') {
          push(&stack, 0, 4, 12);
        }
        str += 3;
      } else if (cur_ch == 'l') {
        if (*(str + 1) == 'n') {
          push(&stack, 0, 4, 14);
          str += 1;
        } else if (*(str + 1) == 'o') {
          push(&stack, 0, 4, 15);
          str += 2;
        }
      }
    } else if (cur_ch == '(') {
      push(&stack, 0, -1, 16);
    } else if (cur_ch == ')') {
      push(&stack, 0, -1, 17);
    }

    str += 1;
  }

  first = NULL;

  Stack reverse_Stack;
  initializeStack(&reverse_Stack);
  int stack_count = size(&stack);

  while (stack_count > 0) {
    StackNode poppedNode = pop(&stack);
    push(&reverse_Stack, poppedNode.value, poppedNode.priority,
         poppedNode.type);
    stack_count--;
  }

  return reverse_Stack;
}