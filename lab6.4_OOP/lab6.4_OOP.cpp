#include <iostream>
#include <windows.h>

using namespace std;

template <typename T>
class TemplateArray {
private:
    T* data;
    int size;

public:
    TemplateArray(int s) {
        size = s;
        data = new T[size];
    }

    ~TemplateArray() {
        delete[] data;
    }

    T& operator[](int index) {
        return data[index];
    }

    int getSize() const {
        return size;
    }
};

template <typename T>
double calculateAverage(TemplateArray<T>& arr) {
    if (arr.getSize() <= 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < arr.getSize(); i++) {
        sum += arr[i];
    }
    return sum / arr.getSize();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    TemplateArray<int> myIntArr(4);
    myIntArr[0] = 10; myIntArr[1] = 20; myIntArr[2] = 30; myIntArr[3] = 40;
    cout << "Середнє значення масиву (int): " << calculateAverage(myIntArr) << endl;

    TemplateArray<double> myDoubleArr(3);
    myDoubleArr[0] = 5.5; myDoubleArr[1] = 10.5; myDoubleArr[2] = 15.0;
    cout << "Середнє значення масиву (double): " << calculateAverage(myDoubleArr) << endl;

    return 0;
}