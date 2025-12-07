#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>

int main()
{
    //Vector
    std::vector <int> vec = {10,20,30};
    std::cout << "Vector: ";
    for (int v: vec) std::cout << v << " ";
    std::cout << std::endl;

    //Map
    std::map<std::string,int> fruitMap;
    fruitMap["Apple"] = 5;
    fruitMap["Banana"] = 7;
    std::cout << "Map: ";
    for (const auto& pair: fruitMap) {
        std::cout << pair.first << " -> " << pair.second << ", ";
    }
    std::cout << std::endl;

    //Stack
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << "Stack pop: ";
    while (!stk.empty()) {
        std::cout << stk.top() << "";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}
