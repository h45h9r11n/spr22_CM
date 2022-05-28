#include <vector>
#include <array>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef array < double, 4 > polynome;
int main() {
    double a, b;
    int n;
    printf("Boundaries: ");
    scanf("%lf %lf", & a, & b);
    printf("N: ");
    scanf("%d", & n);
    double h = (b - a) / n;
    vector < double > x = {}, f = {}, m = {};
    for (int i = 0; i <= n; i++) {
        x.push_back(a + i * h);
        printf("f(%lf): ", x[i]);
        double tmp;
        scanf("%lf", & tmp);
        f.push_back(tmp);
    }
    m.push_back((4 * f[1] - f[2] - 3 * f[0]) / (2 * h));
    for (int i = 1; i < n; i++) m.push_back((f[i + 1] - f[i - 1]) / (2 * h));
    m.push_back((3 * f[n] - f[n - 2] - 3 * f[n - 1]) / (2 * h));
    for (int i = 0; i < n; i++) {
        polynome s = {
            (-2 * x[i] * pow(x[i + 1], 2) + h * pow(x[i + 1], 2)) / pow(h, 3) * f[i] + (2 * x[i + 1] * pow(x[i], 2) + h * pow(x[i], 2)) / pow(h, 3) * f[i + 1] + (x[i] * pow(x[i + 1], 2)) / pow(h, 2) * m[i] + (x[i + 1] * pow(x[i], 2)) / pow(h, 2) * m[i + 1], (2 * pow(x[i + 1], 2) + 4 * x[i] * x[i + 1] - 2 * x[i + 1] * h) / pow(h, 3) * f[i] + (-4 * x[i] * x[i + 1] - 2 * x[i] * h - 2 * pow(x[i], 2)) / pow(h, 3) * f[i + 1] + (pow(x[i + 1], 2) + 2 * x[i] * x[i + 1]) / pow(h, 2) * m[i] + (2 * x[i] * x[i + 1] + pow(x[i], 2)) / pow(h, 2) * m[i + 1], (-4 * x[i + 1] - 2 * x[i] + h) / pow(h, 3) * f[i] + (4 * x[i] + 2 * x[i + 1] + h) / pow(h, 3) * f[i + 1] + (-2 * x[i + 1] - x[i]) / pow(h, 2) * m[i] + (-2 * x[i] - x[i + 1]) / pow(h, 2) * m[i + 1], 2 / pow(h, 3) * f[i] - 2 / pow(h, 3) * f[i + 1] + 1 / pow(h, 2) * m[i] + 1 / pow(h, 2) * m[i + 1],
        };
        double check = (s[3] * (pow(x[i], 3) + pow(x[i + 1], 3)) +
            s[2] * (pow(x[i], 2) + pow(x[i + 1], 2)) +
            s[1] * (x[i] + x[i + 1])) / 2 + s[0];
            s[0] -= (check - (f[i] + f[i + 1]) / 2);
        printf("x in [%lf, %lf], S3(x) = (%lf)x^3 + (%lf)x^2 + (%lf)x + (%lf)\n",x[i], x[i + 1], s[3], s[2], s[1], s[0]);
    }
    return 0;
}