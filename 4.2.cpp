#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void prt_mat(vector<vector<double>> a, int n) {          
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << " " << setprecision(6) << fixed << a[i][j] << " \t";
        cout << "\n";
    }
}
double length(vector < double > a) {
    double l = 0;
    for (int i = 0; i < a.size(); i++)
        l += a[i] * a[i];
    return sqrt(l);
}

double scalar(vector < double > a, vector < double > b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) 
        sum += a[i] * b[i];
    return sum;
}

vector < double > norm(vector < double > a) {
    double len = length(a);
    vector < double > e = {};
    for (int i = 0; i < a.size(); i++) 
        e.push_back(a[i] / len);
    return e;
}

vector < double > proj_vec(vector < double > a, vector < double > b) {
    vector < double > res = b;
    if (scalar(b, b) != 0) {
        for (int i = 0; i < res.size(); i++) 
            res[i] *= scalar(a, b)/scalar(b, b);
    }
    return res;
}

void gram_schmidt(vector <vector <double>> a, int n){
    vector < double > proj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            proj = proj_vec(a[i], a[j]);
            for (int k = 0; k < n; k++) 
                a[i][k] -= proj[k];
        }
    }
    cout << "System of orthogonal : \n";
    prt_mat(a,n);

    for (int i = 0; i < n; i++) 
        a[i] = norm(a[i]);
    cout << "System of orthonormal\n";
    prt_mat(a,n);
    
    cout << "Checking: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            double s = 0;
            for (int k = 0; k < n; k++) 
                s += a[i][k] * a[j][k];
            cout << s << "\t";
        }
        cout << endl;
    }
    double l;
    for (int i = 0; i < n; i++) {
        l = 0;
        for (int j = 0; j < n; j++) 
            l += a[i][j] * a[i][j];
        cout << sqrt(l) << '\t';
    }
}

int main() {
    int n;
    double tmp;
    vector < vector < double >> matrix;
    vector < vector < double >> save_a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        matrix.push_back({});
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            matrix[i].push_back(tmp);
        }
    }
    
    gram_schmidt(matrix, n);

    return 0;
    
}