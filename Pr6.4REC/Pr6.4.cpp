#include <iostream>
#include <cstdlib>

using namespace std;

// Знаходження мінімального елемента в масиві рекурсивно
double findMinRecursive(double arr[], int n, int index = 0) {
    if (index == n - 1) {
        return arr[index];
    }

    double minInRest = findMinRecursive(arr, n, index + 1);
    return (arr[index] < minInRest) ? arr[index] : minInRest;
}

// Знаходження суми елементів між першим і останнім позитивними елементами рекурсивно
double findSumBetweenPositivesRecursive(double arr[], int n, int firstPositiveIndex = -1, int currentIndex = 0) {
    if (currentIndex == n) {
        return 0;
    }

    if (arr[currentIndex] > 0) {
        if (firstPositiveIndex == -1) {
            return findSumBetweenPositivesRecursive(arr, n, currentIndex, currentIndex + 1);
        }
        else {
            return arr[currentIndex - 1] + findSumBetweenPositivesRecursive(arr, n, firstPositiveIndex, currentIndex + 1);
        }
    }

    return findSumBetweenPositivesRecursive(arr, n, firstPositiveIndex, currentIndex + 1);
}

// Переміщення нулів в початок масиву рекурсивно
void moveZerosToFrontRecursive(double arr[], int n, int currentIndex = 0, int zeroCount = 0) {
    if (currentIndex == n) {
        return;
    }

    if (arr[currentIndex] == 0) {
        for (int i = currentIndex; i > zeroCount; i--) {
            swap(arr[i], arr[i - 1]);
        }
        zeroCount++;
    }

    moveZerosToFrontRecursive(arr, n, currentIndex + 1, zeroCount);
}

// Створення масиву рекурсивно та отримання від користувача
double* createArrayRecursive(int n, int currentIndex = 0) {
    if (currentIndex == n) {
        return new double[n];
    }

    double* arr = createArrayRecursive(n, currentIndex + 1);

    cout << "Enter element at index " << currentIndex << ": ";
    cin >> arr[currentIndex];

    return arr;
}

int main() {
    int n;

    // Запит користувача на введення розміру масиву
    do {
        cout << "Enter the size of the array: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid size. Please enter a positive integer." << endl;
        }
    } while (n <= 0);

    // Створення та заповнення масиву користувачем
    double* arr = createArrayRecursive(n);

    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
   

    moveZerosToFrontRecursive(arr, n);

    // Виведення трансформованого масиву
    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }

    // Виведення мінімального елемента
    cout << "\nMinimum element in the array: " << findMinRecursive(arr, n);

    // Виведення суми елементів між першим і останнім позитивними елементами
    cout << "\nSum of elements between first and last positive elements: " << findSumBetweenPositivesRecursive(arr, n);

    // Звільнення пам'яті
    delete[] arr;

    return 0;
}
