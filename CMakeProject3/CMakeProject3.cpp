#include <iostream>

class MyArray {
private:
    int* data;
    int size;
    int capacity;

public:
    MyArray() : data(nullptr), size(0), capacity(0) {}

    ~MyArray() {
        delete[] data;
    }

    void push_back(int value) {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    void insert(int position, int value) {
        if (position >= 0 && position <= size) {
            if (size >= capacity) {
                capacity = (capacity == 0) ? 1 : capacity * 2;
                int* newData = new int[capacity];
                for (int i = 0; i < position; ++i) {
                    newData[i] = data[i];
                }
                newData[position] = value;
                for (int i = position; i < size; ++i) {
                    newData[i + 1] = data[i];
                }
                delete[] data;
                data = newData;
                ++size;
            }
            else {
                for (int i = size; i > position; --i) {
                    data[i] = data[i - 1];
                }
                data[position] = value;
                ++size;
            }
        }
    }

    void erase(int position) {
        if (position >= 0 && position < size) {
            for (int i = position; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
        }
    }

    int getSize() const {
        return size;
    }

    int operator[](int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return 0; 
    }
};

int main() {
    MyArray myArray;
    for (int i = 0; i < 10; ++i) {
        int value;
        std::cin >> value;
        myArray.push_back(value);
    }

    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << " " << myArray[i];
    }
    std::cout << std::endl;

    std::cout << "Size: " << myArray.getSize() << std::endl;

    myArray.erase(2);
    myArray.erase(3);
    myArray.erase(4);

    std::cout << "Erase: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << " " << myArray[i];
    }
    std::cout << std::endl;

    myArray.insert(0, 10);

    std::cout << "Push 10: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << " " << myArray[i];
    }
    std::cout << std::endl;

    myArray.insert(3, 20);

    std::cout << "Push 20: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << " " << myArray[i];
    }
    std::cout << std::endl;

    myArray.push_back(30);

    std::cout << "Push 30: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << " " << myArray[i];
    }
    std::cout << std::endl;

    return 0;
}