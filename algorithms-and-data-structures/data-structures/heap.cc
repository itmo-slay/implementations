#include <ios>
#include <iostream>
void Swap(int& i, int& j) {
  int temp = i;
  i = j;
  j = temp;
}

void SiftUp(int* heap, const int size, int index) {
  int parent = (index - 1) / 2;
  while (index > 0 && heap[index] > heap[parent]) {
    Swap(heap[parent], heap[index]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

void SiftDown(int* heap, const int size, int index) {
  int left = 2 * index + 1;
  while (left < size) {
    int right = left + 1;
    int smallest = left;
    if (right < size && heap[right] > heap[left]) {
      smallest = right;
    }
    if (heap[index] > heap[smallest]) {
      break;
    }
    Swap(heap[index], heap[smallest]);
    index = smallest;
    left = 2 * index + 1;
  }
}

void MoveMin(int* heap, const int size) {
  Swap(heap[0], heap[size - 1]);
  SiftDown(heap, size - 1, 0);
}