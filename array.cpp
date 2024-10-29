#include <iostream>
#include <vector>
#include <algorithm> 

template <typename T, unsigned N>
class Array {
public:

    explicit Array(const T& value = T()) : data_(N) {
        std::fill(data_.begin(), data_.end(), value);
    }

    Array(const Array& other) : data_(other.data_) {}

    ~Array() = default;

    Array& operator=(const Array& other) {
        if (this != &other) {
            data_ = other.data_;
        }
        return *this;
    }

    size_t size() const {
        return data_.size();
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

   T& front() {
        return data_.front();
    }
    
    const T& front() const {
        return data_.front();
    }

    T& back() {
        return data_.back();
    }

    const T& back() const {
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }

    void fill(const T& value) {
        std::fill(data_.begin(), data_.end(), value);
    }

private:
    std::vector<T> data_;
};
