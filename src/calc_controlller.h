#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <iso646.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "back/To_Reverse_Polish_Notation.h"
#include "back/c_stack.h"
#include "back/calculate.h"
#include "back/input_validation.h"
#include "back/pars.h"

int api_calculate(const char* str, double x, double* res);

#endif  // CALC_CONTROLLER_H
