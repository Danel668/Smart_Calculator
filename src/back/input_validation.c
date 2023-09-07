#include "input_validation.h"

bool isValid(char* str) {
  if (str == NULL) return false;

  if (*str == '0') {
    if (str + 1 == NULL) return false;
    if (*(str + 1) != '.') return false;
  }

  bool digits = true;
  bool unarOp = true;
  bool opBracket = true;
  bool clBracket = false;
  bool xCan = true;
  bool unarMinus = true;
  bool operation = false;
  bool degree = false;

  bool mustDigits = false;

  bool nextStep = false;

  int countOpenBracket = 0;
  int countCloseBracket = 0;

  while (*str != '\0') {
    char cur_char = *str;

    // обработка цифр
    if (strchr(DIGITS, (int)cur_char) != NULL) {
      if (digits == false) return false;

      if (IsValidDigits(&str) == false) return false;

      digits = false;
      unarOp = false;
      opBracket = false;
      clBracket = true;
      xCan = false;
      unarMinus = false;
      operation = true;
      degree = true;

      mustDigits = false;

      nextStep = true;
    } else if (cur_char == '.') {
      return false;
    }
    // обработка унарных операций
    else if (strchr(FIRST_SYMBOL_UNAR_OPERAION, (int)cur_char)) {
      if (unarOp == false) return false;

      while (str != NULL && strchr(UNAR_OPERAION, (int)*str)) {
        str++;
      }

      if (str == NULL) return false;

      str--;

      digits = false;
      unarOp = false;
      opBracket = true;
      clBracket = false;
      xCan = false;
      unarMinus = false;
      operation = false;
      degree = false;

      mustDigits = true;

      nextStep = true;
    } else if (cur_char == '(') {
      if (opBracket == false) return false;

      countOpenBracket++;

      digits = true;
      unarOp = true;
      opBracket = true;
      clBracket = false;
      xCan = true;
      unarMinus = true;
      operation = false;
      degree = false;

      mustDigits = true;

      nextStep = true;
    } else if (cur_char == ')') {
      if (clBracket == false) return false;

      countCloseBracket++;
      if (countCloseBracket > countOpenBracket) return false;

      digits = false;
      unarOp = false;
      opBracket = false;
      clBracket = true;
      xCan = false;
      unarMinus = false;
      operation = true;
      degree = true;

      // mustDigits = false;

      nextStep = true;

    } else if (cur_char == 'x') {
      if (xCan == false) return false;

      digits = false;
      unarOp = false;
      opBracket = false;
      clBracket = true;
      xCan = false;
      unarMinus = false;
      operation = true;
      degree = true;

      mustDigits = false;

      nextStep = true;
    }
    // обработка операций
    else if (strchr(OPERAION, (int)cur_char) != NULL) {
      if (operation == false) {
        if (cur_char != '-') return false;
        if (unarMinus == false) return false;
      }

      if (cur_char == 'm') {
        if (str + 1 == NULL || str + 2 == NULL) return false;
        if (*(str + 1) != 'o' || *(str + 2) != 'd') return false;
        str += 2;
      }

      digits = true;
      unarOp = true;
      opBracket = true;
      clBracket = false;
      xCan = true;
      unarMinus = false;
      operation = false;
      degree = false;

      mustDigits = true;

      nextStep = true;
    } else if (cur_char == '^') {
      if (degree == false) return false;

      digits = false;
      unarOp = false;
      opBracket = true;
      clBracket = false;
      xCan = false;
      unarMinus = false;
      operation = false;
      degree = false;

      mustDigits = true;

      nextStep = true;
    }

    if (nextStep == false) return false;

    str++;
    nextStep = false;
  }

  if (mustDigits == true) return false;
  if (countOpenBracket != countCloseBracket) return false;

  return true;
}

bool IsValidDigits(char** p_str) {
  char* str = *p_str;  // Разыменование указателя на указатель

  char cur_dig = *str;
  bool dot = false;

  // если вначале ноль, то потом может быть только точка
  if (cur_dig == '0') {
    if (str[1] == '\0') return false;
    if (str[1] != '.') return false;
    str++;
  }

  while (*str != '\0' && strchr(DIGITS_AND_DOT, (int)*str) != NULL) {
    cur_dig = *str;

    if (cur_dig == '.') {
      if (dot == true) return false;
      dot = true;
    }
    str++;
  }
  str--;

  // если число заканчивается точкой
  if (dot == true) {
    if (*str == '.') return false;
  }

  *p_str = str;  // Изменение указателя на указатель
  return true;
}
