/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:37:52 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/05 20:41:25 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Array.hpp"

int main() {
    std::cout << "🔧 Testing Array<T> template class\n\n";

    // Test 1: Default constructor
    Array<int> emptyArray;
    std::cout << "✅ Default constructor: size = " << emptyArray.size() << "\n\n";

    // Test 2: Constructor with n elements
    Array<int> intArray(5);
    std::cout << "✅ Constructor with size 5: size = " << intArray.size() << "\n";

    std::cout << "📦 Contents (default-initialized ints): ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " "; // Should be 0
    }
    std::cout << "\n\n";

    // Test 3: Modify elements
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = (i + 1) * 10;
    }

    std::cout << "✏️ Modified array: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n\n";

    // Test 4: Copy constructor (deep copy)
    Array<int> copiedArray(intArray);
    copiedArray[0] = 999;

    std::cout << "📄 Copied array (after modifying [0] to 999): ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << "🧾 Original array (should be unchanged): ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n\n";

    // Test 5: Assignment operator (deep copy)
    Array<int> assignedArray;
    assignedArray = intArray;
    assignedArray[1] = 777;

    std::cout << "📄 Assigned array (after modifying [1] to 777): ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << "🧾 Original array (should still be unchanged): ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n\n";

    // Test 6: Exception on out-of-bounds access
    try {
        std::cout << "🚫 Accessing out-of-bounds index 10...\n";
        std::cout << intArray[10] << "\n";
    } catch (const std::exception& e) {
        std::cout << "✅ Caught exception: " << e.what() << "\n";
    }

    // Test 7: Using Array with std::string
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "from";
    strArray[2] = "Array<T>";

    std::cout << "\n📦 String array: ";
    for (unsigned int i = 0; i < strArray.size(); ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << "\n✅ All tests passed.\n";
    return 0;
}
