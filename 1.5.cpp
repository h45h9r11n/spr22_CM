#include <iostream>
#include <cmath>
#include <complex>

// using std::cout;
// using std::cin;
// using std::endl;
// using std::complex;
using namespace std;

complex<double> infunc (int num, complex<double> z){
    if (num == 1){
        return 4.0*pow(z,4)+2.0*pow(z,2)+1.3;
    }
    if (num == 2){
        return pow(z,2) + 2.71;
    }
    if (num == 3){
        return 2.0*exp(z) + sqrt(2.0);
    }
}

complex<double> dfunc (int num, complex<double> z){
    if (num == 1){
        return 16.0*pow(z,3)+4.0*z;
    }
    if (num == 2){
        return 2.0*z;
    }
    if (num == 3){
        return 2.0*exp(z);
    }
}

void solve(complex<double> (*f)(int, complex<double>), complex<double> (*df)(int, complex<double>), complex<double> z0, double err, int num){
    complex<double> z1 = z0 - f(num, z0)/df(num, z0);
    int count = 0;
    while (abs(z1.real()-z0.real()) > err || abs(z1.imag()-z0.imag()) > err){
        z0 = z1;
        z1 = z0 - f(num, z0)/df(num, z0);
        count++;
    }
    cout << "Solution: "<< z1 << endl;
    cout << "Number of loops: "<< count << "\n" << endl;

}

int main(){
    int num;
    cout << "Choose equation: " << endl;
    cin >> num;
    double err;
    complex<double> z0 = {1,1};
    cout << "Accuracy: ";
    cin >> err;
    solve(infunc, dfunc, z0, err, num);
}