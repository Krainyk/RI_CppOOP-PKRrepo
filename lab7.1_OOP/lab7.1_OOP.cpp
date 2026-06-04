#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

vector<int> generateCollection(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 50 + 1;
    }
    return vec;
}

void printCollection(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}


int sumOfOddIndices(const vector<int>& vec) {
    int sum = 0;
    int currentIndex = 0;

    for_each(vec.begin(), vec.end(), [&sum, &currentIndex](int value) {
        if (value % 2 != 0) {
            sum += currentIndex;
        }
        currentIndex++;
        });

    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int n;
    cout << "Введіть кількість елементів вектора: ";
    cin >> n;

    if (n <= 0) {
        cout << "Кількість елементів має бути більшою за 0." << endl;
        return 1;
    }

    vector<int> myVector = generateCollection(n);

    cout << "Сформована колекція-масив:" << endl;
    printCollection(myVector);

    int indexSum = sumOfOddIndices(myVector);

    cout << "\nСума ІНДЕКСІВ непарних елементів: " << indexSum << endl;

    return 0;
}