/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/28 10:15:59 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

// Test helper utilities
void print_test_header(const char* test_name) {
    std::cout << "\n\033[1;34m=== Testing: " << test_name << " ===\033[0m\n";
}

template<typename T>
void print_array(const Array<T>& arr) {
    std::cout << "Array contents: ";
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// -------------------------------------------------------------------
// Test 1: Basic Functionality
// -------------------------------------------------------------------
void test_basic_functionality() {
    print_test_header("Basic Array Operations");
    
    Array<int> nums(5);
    
    // Test initial values (should be zero-initialized)
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0)
            throw std::runtime_error("Element not initialized to zero");
    }
    
    // Test assignment
    nums[2] = 42;
    if (nums[2] != 42)
        throw std::runtime_error("Assignment failed");

    print_array(nums);
}

// -------------------------------------------------------------------
// Test 2: Bounds Checking
// -------------------------------------------------------------------
void test_bounds_checking() {
    print_test_header("Bounds Checking");
    
    Array<double> temps(3);
    bool caught_exception = false;

    // Test valid access first
    temps[0] = 98.6;
    
    // Test lower bound (should be safe since index is unsigned)
    temps[0] = -10.0;

    // Test upper bounds
    try {
        temps[3] = 100.0;
    }
    catch (const std::exception&) {
        caught_exception = true;
    }

    if (!caught_exception)
        throw std::runtime_error("Failed to catch out-of-bounds access");
}

// -------------------------------------------------------------------
// Test 3: Zero-size Array
// -------------------------------------------------------------------
void test_zero_size_array() {
    print_test_header("Zero-size Array");
    
    Array<char> empty(0);
    bool caught_exception = false;

    if (empty.size() != 0)
        throw std::runtime_error("Zero-size array reports incorrect size");

    try {
        empty[0] = 'a';
    }
    catch (const std::exception&) {
        caught_exception = true;
    }

    if (!caught_exception)
        throw std::runtime_error("Zero-size array allowed invalid access");
}

// -------------------------------------------------------------------
// Test 4: Custom Objects
// -------------------------------------------------------------------
struct TestObject {
    int value;
    TestObject() : value(-1) {}
};

void test_custom_objects() {
    print_test_header("Custom Objects");
    
    Array<TestObject> objects(3);
    
    if (objects[0].value != -1 || objects[2].value != -1)
        throw std::runtime_error("Custom object not properly initialized");

    // Test modification
    objects[1].value = 999;
    if (objects[1].value != 999)
        throw std::runtime_error("Custom object modification failed");
}

// -------------------------------------------------------------------
// Test 5: Memory Management
// -------------------------------------------------------------------
class MemoryTracker {
public:
    static int count;
    
    MemoryTracker() { ++count; }
    ~MemoryTracker() { --count; }
};

int MemoryTracker::count = 0;

void test_memory_management() {
    print_test_header("Memory Management");
    
    const int initial_count = MemoryTracker::count;
    
    {
        Array<MemoryTracker> trackers(5);
        if (MemoryTracker::count != initial_count + 5)
            throw std::runtime_error("Incorrect object count after creation");
    }
    
    if (MemoryTracker::count != initial_count)
        throw std::runtime_error("Memory leak detected");
}

// -------------------------------------------------------------------
// Main Test Harness
// -------------------------------------------------------------------
int main() {
    try {
        test_basic_functionality();
        test_bounds_checking();
        test_zero_size_array();
        test_custom_objects();
        test_memory_management();
        
        std::cout << "\n\033[1;32mAll tests passed successfully!\033[0m\n";
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << "\n\033[1;31mTest failed: " << e.what() << "\033[0m\n";
        return EXIT_FAILURE;
    }
}
