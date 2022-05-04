#include <iostream>
#include <vector>
#include <complex>
using namespace std;

vector < complex < double >> operator - (vector < complex < double >> l, vector < complex < double >> r) {
  if (l.size() != r.size()) throw exception("wrong size");
  vector < complex < double >> result;
  for (int i = 0; i < l.size(); i++) {
    result.push_back(l[i] - r[i]);
  }
  return result;
}
vector < complex < double >> operator * (vector < complex < double >> l, complex < double > r) {
  vector < complex < double >> result;
  for (int i = 0; i < l.size(); i++) {
    result.push_back(l[i] * r);
  }
  return result;
}

int main() {
  vector < vector < complex < double >>> base;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  //ввод исходных векторов 
  {
    vector < complex < double >> t;
    for (int j = 0; j < n; j++) {
      double x, y;
      cin >> x >> y;
      t.push_back({x,y});
    }
    base.push_back(t);
  }
  vector < complex < double >> ans, result;
  //ввод свободных членов 
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    ans.push_back({x,y});
  }
  for (int i = 0; i < n - 1; i++) //метод Гаусса 

  {
    if ((base[i][i].real() != 0) || (base[i][i].imag() != 0)) {
      ans[i] = ans[i] * (1.0 / base[i][i]);
      base[i] = base[i] * (1.0 / base[i][i]);
      for (int j = i + 1; j < n; j++) {
        ans[j] = ans[j] - (ans[i] * (base[j][i] / base[i][i]));
        base[j] = base[j] - (base[i] * (base[j][i] / base[i][i]));
      }
    } else {
      int j;
      for (j = i + 1; j < n; j++) {
        if ((base[j][i].real() != 0) || (base[j][i].imag() != 0)) break;
      }
      if (!((base[j][i].real() != 0) || (base[j][i].imag() != 0))) {
        continue;
      }
      swap(base[i], base[j]);
      swap(ans[i], ans[j]);
      i--;
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      ans[j] = ans[j] - (ans[i] * (base[j][i] / base[i][i]));
    }
  }
  ans[n - 1] = ans[n - 1] * (1.0 / base[n - 1][n - 1]);
  for (auto & a: ans) {
    cout << a << '\n';
  }
  for (auto & a: result) {
    cout << a << '\n';
  }
  cout << '\n';
  return 0;
}