#include <iostream>
#include <math.h>
#include <numbers>
using std::cout;
using std::cin;
using std::endl;

double infunc (int num, double x){
    if (num == 1){
        return cos(x) - 0.1 + x;
    }
    if (num == 2){
        return pow((1000 - x), (1.0 / 3));
    }

    if (num == 3){
        return pow((pow(x, 4) + pow(x, 2) + x + 5), (1.0 / 5));
    }
    if (num == 4){
        return pow((x + 1), (1.0 / 3));
    }
    if (num == 5){
        return sqrt(2.25 * x - log(x) * x);
    }
}

void solve(double (*f)(int, double), double x0, double err, int num){
    double x1 = f(x0, num);
    int count = 0;
    while (fabs(x0 - x1) >= err){
        x0 = x1;
        x1 = f(num, x0);
        count++;
    }
    cout << "Root: "<< x1 << endl;
    cout << "Number of loops: "<< count << "\n" << endl;
}

int main(){
    int num;
    cout << "Choose equation: " << endl;
    cin >> num;
    double err, x0;
    cout << "Initial approximation : ";
    cin >> x0;
    cout << "Accuracy: ";
    cin >> err;
    solve(infunc, x0, err, num);
}