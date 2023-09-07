#include "calc_controlller.h"

int api_calculate(const char* str, double x, double* res) {
  if (str == NULL || res == NULL) {
    return 0;
  }

  char input_data[256] = {'\0'};
  strncpy(input_data, str, 255);

  if (!isValid(input_data)) return 0;

  Stack tokens = ParseInTokens(input_data, x);

  Stack polish_notation = To_Reverse_Polish_Notation(tokens);

  *res = Calculate(polish_notation);

  if (isnan(*res) || isinf(*res)) return 0;

  return 1;
}