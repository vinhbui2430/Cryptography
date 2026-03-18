#include <iomanip> // std::setw
#include <iostream>
using namespace std;
#define MAX 255

int S[MAX], T[]{};
int K[]{2, 4, 1, 7};

void init_status(int *S, int n) {
  for (int i = 0; i < n; i++) {
    S[i] = i;
  }
}

void display(int *c, int n) {
  for (int i = 0; i < n; i++)
    cout << c[i];
}

int main() {
  cout << setw(4);
  init_status(S, 10);
  display(S, 10);
  return 0;
}
