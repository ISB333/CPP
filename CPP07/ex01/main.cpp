/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/06/30 14:26:51 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void doubleIntFunc(int& x) { 
    x *= 2; 
}

void nullifyIntPointer(int*& ptr) {
    delete ptr;
    ptr = NULL;
}

void print_divider(const char* message) {
    std::cout << "\n\033[1;35m== " << message << " ==\033[0m\n";
}

template <typename T>
void print_element(T& element) {
    std::cout << element << " ";
}

// -------------------------------------------------------------------
// Test 1: Primitive Type (int)
// -------------------------------------------------------------------
void test_int_array() {
    print_divider("Testing int array");
    int nums[] = {1, 2, 3, 4, 5};
    const size_t len = sizeof(nums)/sizeof(int);
    
    ::iter(nums, len, doubleIntFunc);
    
    std::cout << "Results: ";
    ::iter(nums, len, print_element<int>);
    std::cout << "Expected: 2 4 6 8 10" << std::endl;
}


// -------------------------------------------------------------------
// Test 2: Floating Point Type (float)
// -------------------------------------------------------------------
struct FloatModifier {
    void operator()(float& f) const { f += 0.5f; }
};

void test_float_array() {
    print_divider("Testing float array");
    float values[] = {1.1f, 2.2f, 3.3f};
    size_t len = sizeof(values)/sizeof(float);
    
    FloatModifier modifier;
    ::iter(values, len, modifier);
    
    std::cout << "Results: ";
    ::iter(values, len, print_element<float>);
    std::cout << "Expected: 1.6 2.7 3.8" << std::endl;
}

// -------------------------------------------------------------------
// Test 3: Const Array
// -------------------------------------------------------------------
void print_const(const int& x) {
    std::cout << x << " ";
}

void test_const_array() {
    print_divider("Testing const array");
    const int const_nums[] = {10, 20, 30};
    size_t len = sizeof(const_nums)/sizeof(int);
    
    ::iter(const_nums, len, print_const);
    std::cout << "Expected: 10 20 30" << std::endl;
}

// -------------------------------------------------------------------
// Test 4: Pointer Array
// -------------------------------------------------------------------
void nullify(void*& ptr) {
    ptr = NULL;
}

void test_pointer_array() {
    print_divider("Testing pointer array");
    int* ptrs[3] = {new int(1), new int(2), new int(3)};
    const size_t len = 3;
    
    ::iter(ptrs, len, nullifyIntPointer);
    
    std::cout << "Pointer values: ";
    for (size_t i = 0; i < len; ++i)
        std::cout << (ptrs[i] ? "VALID" : "NULL") << " ";
    std::cout << "\nExpected: NULL NULL NULL" << std::endl;
}

// -------------------------------------------------------------------
// Test 5: Struct Array
// -------------------------------------------------------------------
struct TestStruct {
    int x;
    int y;
    TestStruct(int a = 0, int b = 0) : x(a), y(b) {}
};

std::ostream& operator<<(std::ostream& os, const TestStruct& s) {
    return os << "{" << s.x << "," << s.y << "}";
}

void modify_struct(TestStruct& s) {
    s.x += 1;
    s.y -= 1;
}

void test_struct_array() {
    print_divider("Testing struct array");
    TestStruct structs[3];
    size_t len = 3;
    
    ::iter(structs, len, modify_struct);
    
    std::cout << "Results: ";
    ::iter(structs, len, print_element<TestStruct>);
    std::cout << "Expected: {1,-1} {1,-1} {1,-1}" << std::endl;
}

// -------------------------------------------------------------------
// Test 6: Edge Cases (Empty Array)
// -------------------------------------------------------------------
void test_empty_array() {
    print_divider("Testing empty array");
    int* empty = NULL;
    ::iter(empty, 0, print_element<int>);
    std::cout << "(No output expected)" << std::endl;
}

int main() {
    test_int_array();
    test_float_array();
    test_const_array();
    test_pointer_array();
    test_struct_array();
    test_empty_array();

    return (0);
}
