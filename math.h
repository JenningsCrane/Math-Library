#ifndef MATH_H_
#define MATH_H_

#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define N_EXP 100
#define N_FLOOR 100
#define N_LOG 1000
#define LOG_10 2.302585092994
#define EXP_10 22026.465795
#define CH_PI 3.14159265358979323846
#define CH_EXP 2.71828182845904523536
#define _isnan(x) __builtin_isnan(x)
#define _isinf(x) __builtin_isinf(x)

#define CH_NAN (0.0 / 0.0)
#define CH_INF (1.0 / 0.0)
#define CH_EPS 1e-6

int abs(int x);
long double acos(double x);
long double asin(double x);
long double atan(double x);
long double ceil(double x);
long double cos(double x);
long double exp_sum(double x, double res, long int n);
long double exp(double x);
long double fabs(double x);
long double floor(double x);
long double fmod(double x, double y);
long double log_sum(double x, double res, long int n);
long double log(double x);
long double pow(double base, double exp);
long double sin(double x);
long double sqrt(double x);
long double tan(double x);

long double factorial(int n);
int init_arr(int *arr);
int *ld_to_arr(long double ld_number);
long double arr_to_ld(int *arr);

#endif  // MATH_H_
