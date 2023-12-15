#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <memory>

template<class T>
class array
{
private:
    std::shared_ptr<T[]> _figures;
    size_t _size;
public:
    array() {
        _size =0;
        _figures = nullptr;
    }
    array(size_t sz) {
        _size = sz;
        _figures = std::shared_ptr<T[]>(new T[_size]);
    }

    ~array() {
        _size =0;
        _figures = nullptr;
    }
    size_t get_size() {
        return _size;
    }
    T& operator[](size_t index) {
        return _figures[index];
    }

    void add_figure(size_t index, T& figure) {
        if(_figures[index] != nullptr)
            _figures[index] = nullptr;
        _figures[index] = figure;
    }

    void del_figure(size_t index) {
       _figures[index] = nullptr;

    }


};


