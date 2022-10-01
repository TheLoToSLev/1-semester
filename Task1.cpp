#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::shared_ptr;

int sum_digits(int value) {
    int sum = 0;
    while (value) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

void max_sum_digits(const int* array, size_t size) {
    if (size == 0) {
        return;
    }
    size_t size_arr_ind = 0;
    shared_ptr<int[]> array_ind(new int[size]);
    int max = sum_digits(array[0]);
    array_ind[0] = array[0];
    size_arr_ind++;

    for (size_t i = 1; i < size; i++) {
        int temp_sum_digits = sum_digits(array[i]);
        if (temp_sum_digits > max) {
            max = temp_sum_digits;
            size_arr_ind = 1;
            array_ind[0] = array[i];
        } else if (temp_sum_digits == max) {
            array_ind[size_arr_ind] = array[i];
            size_arr_ind++;
        }
    }

    cout << "Numbers with max sum digits: ";
    for (size_t i = 0; i < size_arr_ind; i++) {
        cout << array_ind[i] << " ";
    } cout << endl;
}

void output_array(const int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    } cout << endl;
}

void filling_random_numbers(int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 50 + 1;
    }
}

int main() {
    size_t size_array;
    cout << "Enter size array: ";
    cin >> size_array;
    shared_ptr<int[]> array(new int[size_array]);

    filling_random_numbers(array.get(), size_array);
    cout << "Source array: ";
    output_array(array.get(), size_array);

    max_sum_digits(array.get(), size_array);
    return 0;
}
