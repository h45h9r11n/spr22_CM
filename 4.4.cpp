#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

complex < double > operator!(complex < double > x) {
    return {x.real(), -x.imag()};
}
vector < vector < complex < double >>> operator * (vector < vector < complex < double >>> l, vector < vector < complex < double >>> r) {
    if (l[0].size() != r.size()) throw exception("wrong size");
    vector < vector < complex < double >>> result;
    for (int i = 0; i < l.size(); i++) {
        vector < complex < double >> tt;
        for (int j = 0; j < r[0].size(); j++) {
        complex < double > t = 0;
        for (int n = 0; n < l[0].size(); n++) {
            t = t + l[i][n] * r[n][j];
        }
        tt.push_back(t);
        }
        result.push_back(tt);
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector < vector < complex < double >>> base;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        base.push_back(vector < complex < double >> {{x,y}});
    }
    vector < vector < complex < double >>> matrix;
    for (int i = 0; i < n; i++) {
        vector < complex < double >> t;
        for (int j = 0; j < n; j++) {
        complex < double > c(0, 1);
        t.push_back(exp(c * (-2 * M_PI * i * j / n)) / sqrt(n));
        }
        matrix.push_back(t);
    }
    for (auto & a: matrix * vector < vector < complex < double >>> {base}) {
        for (auto & b: a) {
            cout << b << ' ';
        }
        cout << '\n';
    }
    vector < vector < complex < double >>> check;
    for (int i = 0; i < n; i++) {
        vector < complex < double >> t;
        for (int j = 0; j < n; j++) {
            t.push_back(!matrix[j][i]);
        }
        check.push_back(t);
    }
    cout << '\n';
    for (auto & a: check * (matrix * vector < vector < complex < double >>> {
        base
        })) {
        for (auto & b: a) {
        cout << b << ' ';
        }
        cout << '\n';
    }
    return 0;
}