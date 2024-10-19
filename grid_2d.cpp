#include <iostream>
#include <new>

template<typename T>
class Grid final {
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* data;
    size_type y_size, x_size;

    void allocate(size_type y_size, size_type x_size) {
        this->y_size = y_size;
        this->x_size = x_size;
        data = new T[y_size * x_size];
    }

public:
    Grid(T const& t) {
        allocate(1, 1);
        data[0] = t; 
    }

    Grid(size_type y_size, size_type x_size) {
        allocate(y_size, x_size);
    }

    Grid(size_type y_size, size_type x_size, T const& t) {
        allocate(y_size, x_size);
        std::fill(data, data + y_size * x_size, t);
    }

    Grid(const Grid<T>& other) {
        allocate(other.y_size, other.x_size);
        std::copy(other.data, other.data + other.y_size * other.x_size, data);
    }

    Grid(Grid<T>&& other)
        : data(other.data), y_size(other.y_size), x_size(other.x_size) {
        other.data = nullptr;
    }

    Grid<T>& operator=(const Grid<T>& other) {
        if (this != &other) {
            delete[] data; 
            allocate(other.y_size, other.x_size);
            std::copy(other.data, other.data + other.y_size * other.x_size, data);
        }
        return *this;
    }

    Grid<T>& operator=(Grid<T>&& other) {
        if (this != &other) {
            delete[] data;
            data = other.data;
            y_size = other.y_size;
            x_size = other.x_size;
            other.data = nullptr;
        }
        return *this;
    }

    ~Grid() {
        delete[] data;
    }

    T operator()(size_type y_idx, size_type x_idx) const {
        return data[y_idx * x_size + x_idx];
    }

    T& operator()(size_type y_idx, size_type x_idx) {
        return data[y_idx * x_size + x_idx];
    }

    Grid<T>& operator=(T const& t) {
        std::fill(data, data + y_size * x_size, t); 
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }

    class row_proxy {
    private:
        Grid<T>* grid;
        size_type y_idx;

    public:
        row_proxy(Grid<T>* grid, size_type y_idx) : grid(grid), y_idx(y_idx) {}

        T& operator[](size_type x_idx) {
            return (*grid)(y_idx, x_idx);
        }

        const T& operator[](size_type x_idx) const {
            return (*grid)(y_idx, x_idx);
        }
    };

    row_proxy operator[](size_type y_idx) {
        return row_proxy(this, y_idx); 
    }

    const row_proxy operator[](size_type y_idx) const {
        return row_proxy(const_cast<Grid<T>*>(this), y_idx);
    }
};

#include<cassert>

int main()
{
    Grid<float> g(3, 2, 0.0f);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    using gsize_t = Grid<float>::size_type;

    for(gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    for(gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
        assert(0.0f == g[y_idx][x_idx]);

    for(gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    for(gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
        g[y_idx][x_idx] = 1.0f;

    for(gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    for(gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
        assert(1.0f == g(y_idx , x_idx));
    return 0;
}
