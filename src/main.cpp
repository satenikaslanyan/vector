#include "stack.hpp"

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

    Stack<int> st;
    try {
        std::cout << st.top() << std::endl;
    } catch (const char* c) {
            std::cout << c << std::endl;
        }
    for (int i = 0; i < 10; ++i) {
        st.push(i);
    }
    while (!st.s_is_empty()) {
        try {
            std::cout << st.top() << "  ";
        } catch (const char* c) { 
            std::cout << c << std::endl;
        }
        st.pop();
    }
    std::cout << std::endl;
}
