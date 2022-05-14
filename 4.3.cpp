#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

void prt(vector<complex<double>> a, int n){
    for (int i = 0; i < n; i++) 
        cout << a[i] << "\n";
}

void fourier(vector<complex<double>> a, int n){
    vector<complex<double>> res;
    complex < double > coeff(0, 1);
    coeff *= -2 * M_PI / n;
    for (int i = 0; i < n; i++) {
        complex < double > t;
        for (int j = 0; j < n; j++) {
            t += a[j] * exp(coeff * (double)(i * j));
        }
        res.push_back(t);
    }
    cout << "Solution\n";
    prt(res, n);

    vector<complex<double>> check;
    for (int i = 0; i < n; i++) {
        complex < double > t = {0,0};
        for (int j = 0; j < n; j++) {
            t += res[j] * exp(-coeff * (double)(i * j));
        }
        check.push_back(t / (double)(n));
    }
    cout << "\nChecking\n";
    prt(check, n);
}

int main() {
    int n;
    cin >> n;
    vector < complex < double >> base, result, check;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        base.push_back({x,y});
    }
    fourier(base, n);
    return 0;
}