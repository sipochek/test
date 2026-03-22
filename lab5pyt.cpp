#include <iostream>
#include<cstdlib>
using namespace std;
const int SIZE = 10;
void bubble_sort(int* arr){
	setlocale(LC_ALL, "");
	int a, b, t;
	cout << "Исходный массив:";
	for (t = 0; t < SIZE; t++) cout << arr[t] << " ";
	cout << "\n";
	for (a = 1; a < SIZE; a++) {
		for (b = SIZE - 1; b >= a; b--) {
			if (arr[b - 1] > arr[b]) {
				t = arr[b - 1];
				arr[b - 1] = arr[b];
				arr[b] = t;
			}
		}
	}
	cout << "Отсортированный массив: ";
	for (t = 0; t < SIZE; t++) cout << arr[t] << " ";
}

int binary(const int* arr,int target) {
	int left = 0;
	int right = SIZE-1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand()%100;
	}
	bubble_sort(arr);
	int target;
	cout << "\nВведите элемент для поиска:";
	cin >> target;
	int index = binary(arr, target);

	if (index != -1) {
		cout << "Элемент " << target << " найден в позиции " << index << endl;

	}
}
