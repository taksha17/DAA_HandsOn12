#include <iostream>
#include <stdexcept>

class DynamicArray {
public:
    DynamicArray() : capacity_(1), size_(0), data_(new int[capacity_]) {}

    ~DynamicArray() {
        delete[] data_;
    }

    void push_back(int value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        data_[size_++] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    int size() const {
        return size_;
    }

private:
    int* data_;
    int capacity_;
    int size_;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(1);
    arr.push_back(2);

    std::cout << "Array elements:\n";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr.get(i) << std::endl;
    }

    return 0;
}
