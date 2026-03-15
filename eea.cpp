#include <iostream>
#include <stdint.h>
using namespace std;

// m(x) = x^10 + x^3 + 1
const uint32_t mod = 0x409;

int get_degree(uint32_t poly) {
  if (poly == 0)
    return -1;
  int deg = 0;
  while (poly >>= 1)
    deg++;
  return deg;
}

pair<uint32_t, uint32_t> poly_div(uint32_t dividend, uint32_t divisor) {
  uint32_t q = 0;
  int deg_dividend = get_degree(dividend);
  int deg_divisor = get_degree(divisor);

  while (deg_dividend >= deg_divisor && dividend != 0) {
    int shift = deg_dividend - deg_divisor;
    q |= (1 << shift);
    dividend ^= (divisor << shift);
    deg_dividend = get_degree(dividend);
  }
  return {q, dividend};
}

uint32_t poly_mul(uint32_t a, uint32_t b) {
  uint32_t res = 0;
  for (int i = 0; i <= get_degree(b); i++) {
    if ((b >> i) & 1)
      res ^= (a << i);
  }
  return res;
}

uint32_t EEA(uint32_t a, uint32_t m) {
  uint32_t old_r = a, r = m;
  uint32_t old_s = 1, s = 0;

  while (r != 0) {
    auto [q, remainder] = poly_div(old_r, r);
    old_r = r;
    r = remainder;
    cout << "\n" << r;
    uint32_t tmp_s = old_s;
    old_s = s;
    s = tmp_s ^ poly_mul(q, s);
    cout << "\n" << s;
  }

  if (old_r != 1)
    return 0;
  return old_s;
}

int main() {
  uint32_t poly_1 = 0x20B; // 523
  uint32_t poly_2 = 0x3F7; // 1015
  uint32_t inv_1 = EEA(poly_1, mod);
  uint32_t inv_2 = EEA(poly_2, mod);

  cout << "\nPolynomial: " << poly_1 << " (Hex)" << endl;
  cout << "Inverse:    " << inv_1 << " (Hex)" << endl;
  cout << "\nPolynomial: " << poly_2 << " (Hex)" << endl;
  cout << "Inverse:    " << inv_2 << " (Hex)" << endl;

  return 0;
}
