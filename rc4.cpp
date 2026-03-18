#include <iomanip> // std::setw
#include <iostream>
using namespace std;
#define MAX 255

int S[MAX], T[]{};
int K[]{2, 4, 1, 7};
int key[]{};

void init_status(int *S, int n) {
  for (int i = 0; i < n; i++) {
    S[i] = i;
    T[i] = K[i % 4];
  }
}

void display(int *c, int n) {
  for (int i = 0; i < n; i++)
    cout << c[i];
}

void swap(int *a, int *b) {
  int *temp;
  temp = a;
  a = b;
  b = temp;
}

void init_permut() {
  int j = 0;
  for (int i = 0; i < 10; i++) {
    j = (j + S[i] + T[i]) % 10;
    swap(S[i], S[j]);
  }
}

void stream_gen() {
  int i = 0, j = 0;
  while (true) {
    i = (i + 1) % 10;
    j = (j + S[i]) % 10;
    swap(S[i], S[j]);
    int t = (S[i] + S[j]) % 10;
    *key = S[t];
  }
} // still need to convert message to binary sequence to encrypt

int main() {
  char m[] = "cryptography";
  cout << setw(4);
  init_status(S, 10);
  display(T, 10);
  cout << endl;
  init_permut();
  display(S, 10);
  return 0;
}
