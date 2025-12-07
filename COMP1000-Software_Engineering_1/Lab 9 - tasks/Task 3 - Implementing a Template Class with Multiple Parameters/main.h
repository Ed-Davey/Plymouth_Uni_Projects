#ifndef main_h
#define main_h

template <typename T1, typename T2>
class pair {
    private:
    T1 first; //create variable first of any type
    T2 second; //create variable second of any type
    public:
    pair(T1 first, T2 second) : first(first), second(second) {} //method to get the values from main.cpp

    T1 displayFirst() { //create method to return first
        return first;
    }

    T2 displaySecond() { //create method to return second
        return second;
    }
};

#endif main_h
