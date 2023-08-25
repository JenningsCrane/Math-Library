#include "math.h"

int abs(int x) { return x > 0 ? x : -x; }

long double acos(double x) {
  long double result = 0;
  if (x == 0) {
    result = CH_PI / 2;
  } else if (x == -1) {
    result = CH_PI;
  } else if (x == 1) {
    result = 0;
  } else if (x == 0.70710678) {
    result = CH_PI / 4;
  } else if (x == -0.70710678) {
    result = CH_PI - CH_PI / 4;
  } else if (x > 0. && x < 1.) {
    result = atan(sqrt(1 - x * x) / x);
  } else if (x > -1. && x < 0) {
    result = CH_PI + atan(sqrt(1 - x * x) / x);
  } else {
    result = CH_NAN;
  }
  return result;
}

long double asin(double x) {
  long double result = 0;
  if (x == 1) {
    result = CH_PI / 2;
  } else if (x == -1) {
    result = -CH_PI / 2;
  } else if (x == 0.70710678) {
    result = CH_PI / 4;
  } else if (x == -0.70710678) {
    result = -CH_PI / 4;
  } else if (x > -1. && x < 1.) {
    result = atan(x / sqrt(1 - pow(x, 2)));
  } else {
    result = CH_NAN;
  }
  return result;
}

long double atan(double x) {
  long double result = 0;
  if (_isnan(x)) {
    result = CH_NAN;
  } else if (x == CH_INF) {
    result = CH_PI / 2;
  } else if (x == -CH_INF) {
    result = -CH_PI / 2;
  } else if (x == 1) {
    result = CH_PI / 4;
  } else if (x == -1) {
    result = -CH_PI / 4;
  } else if (x > -1. && x < 1.) {
    for (int i = 0; i < 500; i++) {
      result += pow(-1, i) * pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 500; i++) {
      result += pow(-1, i) * pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = CH_PI * sqrt(x * x) / (2 * x) - result;
  }
  return result;
}

long double ceil(double x) {
  long double result = 0;
  if (x == 1.0 / 0.0) {
    result = 1.0 / 0.0;
  } else if (x == -1.0 / 0.0) {
    result = -1.0 / 0.0;
  } else if (_isnan(x)) {
    result = CH_NAN;
  } else if (x > 0) {
    if (fabs(x) - arr_to_ld(ld_to_arr(fabs(x))) >
        0.000000000000001) {
      result = arr_to_ld(ld_to_arr(x)) + 1;
    } else {
      result = arr_to_ld(ld_to_arr(x));
    }
  } else if (x < 0) {
    result = -arr_to_ld(ld_to_arr(fabs(x)));
  } else {
    result = 0;
  }
  return result;
}

long double cos(double x) { return sin(x + CH_PI / 2); }

long double exp_sum(double x, double res, long int n) {
  if (n > N_EXP) return 0;
  return res + exp_sum(x, res * x / n, n + 1);
}

long double exp(double x) {
  long double result = 1;
  if (x >= 710 || x == 1.0 / 0.0) {
    result = CH_INF;
  } else if (x == -1.0 / 0.0) {
    result = 0.0;
  } else if (_isnan(x)) {
    result = 0.0 / 0.0;
  } else {
    long double y = x;
    while (y < -11) {
      y = y + 10;
      result = result / EXP_10;
    }
    while (y > 11) {
      y = y - 10;
      result = result * EXP_10;
    }
    result = result * exp_sum(y, 1, 1);
  }
  return result;
}

long double fabs(double x) { return x > 0 ? x : -x; }

long double floor(double x) {
  long double result = 0;
  if (x == 1.0 / 0.0) {
    result = 1.0 / 0.0;
  } else if (x == -1.0 / 0.0) {
    result = -1.0 / 0.0;
  } else if (_isnan(x)) {
    result = CH_NAN;
  } else if (x > 0) {
    result = arr_to_ld(ld_to_arr(x));
  } else if (x < 0) {
    if (fabs(x) - arr_to_ld(ld_to_arr(fabs(x))) >
        0.000000000000001) {
      result = -arr_to_ld(ld_to_arr(fabs(x))) - 1;
    } else {
      result = -arr_to_ld(ld_to_arr(fabs(x)));
    }
  } else {
    result = 0;
  }
  return result;
}

long double fmod(double x, double y) {
  long double result = 0;
  if (0 == y || x == 1.0 / 0.0 || x == -1.0 / 0.0)
    result = -0.0 / 0.0;
  else if (0 == x)
    result = 0.0;
  else if (y == 1.0 / 0.0 || y == -1.0 / 0.0)
    result = x;
  else if (x == y)
    result = 0.0;
  else
    result = (x - (x / fabs(x)) * floor(fabs(x) / fabs(y)) *
                      fabs(y));
  return result;
}

// insted log(x) we can use log((1+x)/(1-x))
long double log_sum(double x, double res, long int n) {
  if (n > N_LOG) return 0;
  return res / n + log_sum(x, res * x * x, n + 2);
}

long double log(double x) {
  long double result = 0;
  if (_isnan(x)) {
    result = CH_NAN;
  } else if (x == 1.0 / 0.0) {
    result = 1.0 / 0.0;
  } else if (x == -1.0 / 0.0) {
    result = 0.0 / 0.0;
  } else if (x < 0) {
    result = 0.0 / 0.0;
  } else if (x == 0) {
    result = -1.0 / 0.0;
  } else {
    long double y = x;
    while (y > 11) {
      y = y / 10;
      result = result + LOG_10;
    }
    while (y < 2) {
      y = y * 10;
      result = result - LOG_10;
    }
    long double z = (y - 1) / (y + 1);
    result = result + 2 * log_sum(z, z, 1);
  }
  return result;
}

long double pow(double base, double t_exp) {
  long double result = 1;
  long double d_base = base;
  long double d_exp = t_exp;
  int bool_return = 0;
  if (d_base == 0.0 && _isnan(d_exp)) {
    result = CH_NAN;
    bool_return = 1;
  } else if (t_exp == 1.0) {
    result = d_base;
    bool_return = 1;
  } else if (d_base == -0.0 && d_exp == -CH_INF && bool_return == 0) {
    result = CH_INF;
    bool_return = 1;
  } else if (-1 < d_base && d_base < 1 && d_exp == CH_INF && bool_return == 0) {
    result = 0;
    bool_return = 1;
  } else if (_isnan(d_base) && d_exp == CH_INF && bool_return == 0) {
    result = CH_NAN;
    bool_return = 1;
  } else if (d_base == -1.0 && d_exp == CH_INF && bool_return == 0) {
    result = 1;
    bool_return = 1;
  } else if (d_base == 0.0 && d_exp == 0.0 && bool_return == 0) {
    result = 1;
    bool_return = 1;
  } else if (d_base == 1 && bool_return == 0) {
    result = 1;
    bool_return = 1;
  } else if ((d_exp == 0.0 || d_base == 1.0) && bool_return == 0) {
    result = 1;
    bool_return = 1;
  } else if (d_base == 0.0 && d_exp != 0.0 && bool_return == 0) {
    result = 0.0;
    bool_return = 1;
  } else if (d_exp == CH_INF && d_base != -1.0 && bool_return == 0) {
    result = CH_INF;
    bool_return = 1;
  } else if (d_base < 0.0 && d_exp != CH_INF && d_exp != floor(d_exp) &&
             bool_return == 0) {
    result = CH_NAN;
    bool_return = 1;
  } else if (d_base == -1 && d_exp == -CH_INF && bool_return == 0) {
    result = 1;
    bool_return = 1;
  }
  if (d_base < 0.0 && bool_return == 0) {
    d_base = -d_base;
    if (fmod(floor(d_exp), 2) != 0) {
      result = -1;
    }
  }
  if (d_exp < 0.0 && bool_return == 0) {
    d_exp = -d_exp;
    d_base = 1 / d_base;
  }
  if (bool_return == 0) {
    result = result * exp(d_exp * log(d_base));
  }
  return result;
}

long double sin(double x) {
  double e = 0.0000001;
  long double result = 0;
  double check = 1;
  int i = 1;
  if (x > 2 * CH_PI || x < -2 * CH_PI) {
    x = fmod(x, 2 * CH_PI);
  }
  while (fabs(check) >= e) {
    result += (pow((-1), i - 1) * pow(x, (2 * i) - 1)) /
              factorial((2 * i) - 1);
    check = (pow((-1), i - 1) * pow(x, (2 * i) - 1)) /
            factorial((2 * i) - 1);
    i++;
  }
  if (x == CH_PI || x == -CH_PI || x == 2 * CH_PI || x == -2 * CH_PI) {
    result = -result;
  }
  return result;
}

long double sqrt(double x) { return pow(x, 0.5); }

long double tan(double x) { return sin(x) / cos(x); }

long double factorial(int N) {
  if (N < 0.) return 0;
  if (N == 0.)
    return 1;
  else
    return N * factorial(N - 1);
}

int init_arr(int *arr) {
  for (int i = 0; i < N_FLOOR; i++) {
    arr[i] = 0;
  }
  return 1;
}

int *ld_to_arr(long double ld_number) {
  static int arr[N_FLOOR];
  init_arr(arr);
  long double x = ld_number;
  int n = 0;
  while (1 < x) {
    x = x / 10;
    n++;
  }
  for (int i = 1; i <= n; i++) {
    x = x * 10;
    if (i == 1) {
      arr[1] = (int)x;
      arr[0] = i;
    } else if (i < N_FLOOR) {
      arr[i] = (int)(x - arr_to_ld(arr) * 10 + CH_EPS);
      arr[0] = i;
    } else {
      arr[0] = i;
    }
  }
  return arr;
}

long double arr_to_ld(int *arr) {
  int size = abs(arr[0]);
  long double ld_number = 0;
  int number = 1;
  while (size > 0) {
    if (number < N_FLOOR) {
      ld_number = ld_number * 10 + arr[number++];
    } else {
      ld_number = ld_number * 10;
    }

    size--;
  }
  return ld_number;
}
