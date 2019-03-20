#include "vector.hpp"

int main()
{
    Vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    v.push_back(170);
    std::cout << v;
    v.insert(5, 10);
    std::cout << v;
    v.remove(3);
    v[8] = 111;
    std::cout << v;
    v.pop_back();
    std::cout << v;
}
