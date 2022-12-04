/*Използвайки дадения в презентацията Lab 1 - 2020 примерен код,
реализирайте измерване на времето на изпълнение на алгоритмите за сортиране
пряка селекция, пряко вмъкване и мехурче.
Измерете времената на всеки от тях за 10 000, 20 000, ... 100 000 случайно
наредени елементи и ги въведете в електронна таблица,
за да изчертаете графиката за тях.*/
#include<iostream>
#include<time.h>
#include<random>
using namespace std;
void fillArray(int*& arr, int size);
void insertionSort(int*& arr, int size);
void selectedSort(int*& arr, int size);
void bubbleSort(int*& arr, int size);
void printArray(int*& arr, int size);
int main() {
	int size = 0;
	for (int i = 0; i < 10; i++) {
		size += 10000;
		int* arr = new int[size];
		fillArray(arr, size);
		bubbleSort(arr, size);
	}
	//printArray(arr, size);
	return 0;
}
void selectedSort(int*& arr, int size) {
	clock_t c1 = clock();
	int max = 0;
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i] + 1;
		}
	}
	int min = max;
	int index = 0;
	int flag;
	bool swap = false;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
				swap = true;
			}
		}
		if (swap) {
			flag = arr[i];
			arr[i] = arr[index];
			arr[index] = flag;
			min = max;
			swap = false;
		}
	}
	clock_t c2 = clock();
	cout << "time = " << (float)(c2 - c1) / CLOCKS_PER_SEC << endl;
	//cout << "Ordered array:" << endl;
	//for (int i = 0; i < 10; i++) {
	// cout << arr[i] << "\t";
	//}
}
void insertionSort(int*& arr, int size) {
	clock_t c1 = clock();
	int flag;
	int number;
	for (int i = 1; i < size; i++) {
		number = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (number < arr[j]) {
				arr[i] = arr[j];
				arr[j] = number;
			}
		}
	}
	clock_t c2 = clock();
	cout << "Time = " << (float)(c2 - c1) / CLOCKS_PER_SEC << endl;
}
void fillArray(int*& arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
}
void printArray(int*& arr, int size) {
	cout << "Ordered Array:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}
void bubbleSort(int*& arr, int size) {
	clock_t c1 = clock();
	bool inversions = true;
	int flag;
	while (inversions) {
		inversions = false;
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				flag = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = flag;
				inversions = true;
			}
		}
	}
	clock_t c2 = clock();
	std::cout << "Time = " << (float)(c2 - c1) / CLOCKS_PER_SEC << endl;
}