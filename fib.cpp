#include <bits/stdc++.h>
using namespace std;
vector<int> inter(int n)
{
  vector<int> res;
  if (n >= 1)
  {
    res.push_back(0);
  }
  if (n >= 2)
  {
    res.push_back(1);
  }
  for (int i = 2; i < n; i++)
  {
    int val = res[i - 1] + res[i - 2];
    res.push_back(val);
  }
  return res;
}

void fib_rec(vector<int> &array, int n)
{
  if (n <= 0)
  {
    return;
  }
  fib_rec(array, n - 1);
  int fib = (n == 1) ? 0 : (n == 2) ? 1
                                    : array[n - 2] + array[n - 3];
  array.push_back(fib);
}

int main()
{
  int n1;
  cout << "Enter the value of number 1" << endl;
  cin >> n1;
  vector<int> final = inter(n1);
  for (int i = 0; i < final.size(); i++)
  {
    cout << final[i];
  }

  int n2;
  cout << "Enter the value of number 2" << endl;
  cin >> n2;
  vector<int> final2;
  fib_rec(final2, n2);
  for (int i = 0; i < final.size(); i++)
  {
    cout << final2[i];
  }
  return 0;
}