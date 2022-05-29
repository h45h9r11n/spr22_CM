#include <iostream>

#include <math.h>

#include <numbers>

using std::cout;
using std::cin;
using std::endl;
double R;
double func(int num, double x) {
  if (num == 1) {
    return x * x;
  } else if (num == 2) {
    return sin(x) * sin(x);
  } else if (num == 3) {
    return sin(2 * x) + cos(7 * x) + 8;
  } else if (num == 4) {
    return 2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24;
  } else if (num == 5) {
    return log(pow(x, 2) + 1) + sin(x / 3) + 17;
  } else if (num == 6) {
    return (5, x) + sin(x) + x + 11;
  } else if (num == 7) {
    return pow(x, 5) + 2 * pow(x, 4) + 3 * pow(x, 3) + 4 * pow(x, 2) + 5 * x + 6;
  }
  return 0;
}
double d4func(int num, double x) {
  if (num == 1) {
    return 0;
  } else if (num == 2) {
    return (8 * (pow(sin(x), 2) - pow(cos(x), 2)));
  } else if (num == 3) {
    return (16 * sin(2 * x) + 2401 * cos(7 * x));
  } else if (num == 4) {
    return 48;
  } else if (num == 5) {
    return -96 * (pow(x, 4) / pow(pow(x, 2) + 1, 4)) + 96 * (pow(x, 2) / pow(pow(x, 2) + 1, 3)) + sin(x / 3) / 81 - 12 / (pow(pow(x, 2) + 1, 2));
  } else if (num == 6) {
    return (pow(5, x) * pow(log(5), 4) + sin(x));
  } else if (num == 7) {
    return (24 * (5 * x + 2));
  }
  return 0;
}
double NC3(double a, double b, int num, int n) {
  R = 0;
  double result = func(num, a) - func(num, b), h = (b - a) / n;
  double x = a;
  for (int i = 0; i < n; i++) {
    result += 3 * (func(num, x + h / 3) + func(num, x + 2 * h / 3)) + 2 * func(num, x + h);
    R += d4func(num, x + h / 2);
    x += h;
  }
  R = -pow(h, 5) * R / 6480;
  return (result * h) / 8;
}
double NC4(double a, double b, int num, int n) {
  R = 0;
  double result = 7 * func(num, a) - 7 * func(num, b), h = (b - a) / n;
  double x = a;
  for (int i = 0; i < n; i++) {
    result += 32 * func(num, x + h / 4) + 12 * func(num, x + h / 2) + 32 * func(num, x + 3 * h / 4) + 14 * func(num, x + h);
    R += d4func(num, x + h / 2);
    x += h;
  }
  R = -pow(h, 7) * R / 1935360;
  return (result * h) / 90;
}
int main() {
  int num, n;
  double a, b;
  double err;
  cout << "Choose equation: " << endl;
  cin >> num;
  cout << "Enter interval and n: " << endl;
  cin >> a >> b >> n;
  cout << "Result NC3 " << NC3(a, b, num, n) << endl;
  cout << "R = " << R << endl;
  cout << "Result NC4 " << NC4(a, b, num, n) << endl;
  cout << "R = " << R << endl;
}