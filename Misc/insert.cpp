
#include <iostream>
using namespace std;

void insert( int A[], int &n, int q, int e, int k) {
  if (n>=q) {
    cout << "Array is full. cannot insert element" << '\n';
    return;
  }
  if (k<0 || k < n) {
    cout << "Invalid position" << '\n';
  }
}
int k = 2;
for (int i = n; i > k; --i) {
  A[i] = A[i-1]
}
A[k] = e;
++n;

int main() {
  int A[10] = {1,2,3,4,5};
  int n = 5;
  int q = 10;
  insert (A, n, q, 10, 2);
  for (int i = 0; i < n; ++i) {
    cout << A[i] << "";
  }
  cout << endl;
  return 0;
}

/*
Require A, e, k, n, q //arreglo, elemento, posicion, tamaño, capacidad
Ensure 0 < n < q; 0<=k<=n //metodo void
n = n+1
while  n < k+1 {
  A[n] = A[n-1]
  n--
A[k] = e
n++
*/
