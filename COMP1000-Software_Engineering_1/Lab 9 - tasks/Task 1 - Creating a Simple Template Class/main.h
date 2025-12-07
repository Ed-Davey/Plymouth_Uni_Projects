#ifndef main_h
#define main_h

template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T getValue() {
        return value;
    }
};


#endif main_h