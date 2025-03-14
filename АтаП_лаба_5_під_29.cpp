#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void FillMatrix(int** matrix, int n, int minVal, int maxVal) {
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}	
    }
}

void PrintMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Task1(int n) {
	int** A = new int*[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[n];

	FillMatrix(A, n, 10, 99);

	cout << "Matrix:\n";
	PrintMatrix(A, n);

	int sum = 0, count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += A[i][j], count++;

	double avg = (double)sum / count;
	int* B = new int[n] {};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (A[i][j] < avg)
				B[i]++;

	ofstream fout("task1_output.txt");
	for (int i = 0; i < n; i++)
		fout << B[i] << " ";
	fout.close();

	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;
	delete[] B;
}

bool IsColumnSortedDescending(int** Arr, int n, int column) {
	for (int i = 1; i < n; i++)
		if (Arr[i][column] > Arr[i - 1][column])
			return false;
	return true;
}

void Task2(int n) {
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int[n];

	FillMatrix(A, n, 10, 99);

	cout << "Matrix:\n";
	PrintMatrix(A, n);

	int count = 0;
	for (int j = 0; j < n; j++)
		if (IsColumnSortedDescending(A, n, j))
			count++;

	cout << "Sorted descending columns: " << count << endl;

	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;
}

void SortDescending(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void Task3(int n) {
	int** A = new int*[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[n];

	FillMatrix(A, n, 100, 999);

	cout << "Matrix:\n";
	PrintMatrix(A, n);

	for (int i = 0; i < n; i++) 
		SortDescending(A[i], n);

	ofstream fout("task3_output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << A[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();

	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;
}

bool HasSameDigits(int num) {
	int firstDigit = num / 10;
	int secondDigit = num % 10;
	return firstDigit == secondDigit;
}

int SumValidColumns(int** A, int n) {
	int totalSum = 0;

	for (int j = 0; j < n; j++) {
		bool validColumn = true;
		int columnSum = 0;

		for (int i = 0; i < n; i++) {
			if (HasSameDigits(A[i][j])) {
				validColumn = false;
				break;
			}
			columnSum += A[i][j];
		}

		if (validColumn) totalSum += columnSum;
	}

	return totalSum;
}


void Task4(int n) {
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int[n];

	FillMatrix(A, n, 10, 99);

	cout << "Matrix:\n";
	PrintMatrix(A, n);

	int sum = SumValidColumns(A, n);

	cout << "Sum of items in columns without identical digits: " << sum << endl;

	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;
}

int main()
{
	srand(time(nullptr));
	int choice, n;
	cout << "Enter matrix size (n x n): ";
	cin >> n;

	do {
		cout << "\nMenu\n";
		cout << "1. Task 1\n";
		cout << "2. Task 2\n";
		cout << "3. Task 3\n";
		cout << "4. Task 4\n";
		cout << "0. Exit\n";
		cout << "Choose an option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Task1(n);
			break;
		case 2:
			Task2(n);
			break;
		case 3:
			Task3(n);
			break;
		case 4:
			Task4(n);
			break;
		case 0:
			cout << "Exiting the program...\n";
			break;
		default:
			cout << "Invalid choice! Try again.\n";
			break;
		}
	} while (choice != 0);
	return 0;
}


