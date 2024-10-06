#include <iostream>
using namespace std;

void countSortNaive(int arr[], int k, int n) {
  int count[k];
  for (int i = 0; i < k; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }
  int index = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < count[i]; j++) {
      arr[index] = i;
      index++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
int main() {
  int n = 4, k = 7;
  int arr[] = { 5, 6, 5, 2 };
  countSortNaive(arr, k, n);
  return 0;
}
