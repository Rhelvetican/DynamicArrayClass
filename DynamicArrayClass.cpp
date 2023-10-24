#include <iostream>

using namespace std;

class DynamicArray {
private:

    //Initial data declaration.

    int* array; 
    unsigned int size; 
    int capacity;

public:

    // Constructor

    DynamicArray() {
        size = 0;
        capacity = 10; 
        array = new int[capacity]; 
    }

    // Destructor

    ~DynamicArray() {
        deleteAll();
    }

    // Insert an interger into the front of the array

    void insertHead(int i) {

        size++;
        if (size >= capacity) {
            resize();
        }

        for (int i = size - 1; i > 0; --i) {
            array[i] = array[i - 1];
        }
        array[0] = i;
    }

    // Insert an interger into the back of the array

    void insertTail(int i) {

        size++;
        if (size >= capacity) {
            resize();
        }

        array[size - 1] = i;
    }

    // Delete an interger from the front of the array

    void deleteHead() {
        if (size > 0) {
            for (int i = 0; i < size - 1; ++i) {
                array[i] = array[i + 1];
            }
            size--;
        }
    }

    // Delete an interger from the back of the array

    void deleteTail() {
        if (size > 0) {
            int* newArray = new int[size];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            size--;
        }
    }

    // Insert an interger after a certain index of the array

    void insertAfter(int i, int index) {

        if (index < 0 || index >= size) {
            return;
        }

        int* newArray = new int[size + 1];
        for (int i = 0; i <= index; i++) {
            newArray[i] = array[i];
        }
        newArray[index + 1] = i;
        for (int i = index + 2; i < size + 1; i++) {
            newArray[i] = array[i - 1];
        }

        delete[] array;
        array = newArray;
        size++;
    }

    void deleteAll() {
        delete[] array;
        array = nullptr;
        size = 0;

        cout << "Array deinitialized." << endl;
    }

    int count() const {
        return size;
    }

    int* at(int i) {
        if (i >= 0 && i < size) {
            return &array[i];
        }
        else {
            return nullptr;
        }
    }

    // Resize the array

    void resize() {
        capacity *= 2; 
        int* newArray = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    //Prints the contents of the array

    void print() const {
        cout << "[ ";

        for (int i = 0; i < size; i++) {
            cout << array[i];
        }

        cout << "]" << endl;
    }
};

int main() {
    DynamicArray dynamicArray;

    dynamicArray.insertTail(10);
    dynamicArray.insertTail(20);
    dynamicArray.insertTail(30);
    dynamicArray.insertTail(100);

    dynamicArray.print();

    cout << dynamicArray.count() << "\n";

    return 0;
}