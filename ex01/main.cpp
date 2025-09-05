/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:58:39 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/05 20:09:57 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"

// Function that takes a const reference
template<typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

// Function that modifies elements (e.g., increments for numeric types)
template<typename T>
void incrementElement(T& elem) {
    ++elem;
}

// Function that uppercases a char (non-template example)
void toUpper(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

// Function for strings that appends something
void appendExclamation(std::string& s) {
    s += "!";
}

int main() {
    // Test 1: int array
    int intArr[] = {1, 2, 3, 4, 5};
    std::size_t intSize = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array: ";
    iter(intArr, intSize, printElement<int>);
    std::cout << "\n";

    iter(intArr, intSize, incrementElement<int>);

    std::cout << "After incrementing: ";
    iter(intArr, intSize, printElement<int>);
    std::cout << "\n\n";

    // Test 2: double array
    double dblArr[] = {1.1, 2.2, 3.3};
    std::size_t dblSize = sizeof(dblArr) / sizeof(dblArr[0]);

    std::cout << "Original double array: ";
    iter(dblArr, dblSize, printElement<double>);
    std::cout << "\n\n";

    // Test 3: char array
    char charArr[] = {'h', 'e', 'l', 'l', 'o'};
    std::size_t charSize = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << "Original char array: ";
    iter(charArr, charSize, printElement<char>);
    std::cout << "\n";

    iter(charArr, charSize, toUpper);

    std::cout << "After toUpper: ";
    iter(charArr, charSize, printElement<char>);
    std::cout << "\n\n";

    // Test 4: std::string array
    std::string strArr[] = {"hello", "world", "chatgpt"};
    std::size_t strSize = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "Original string array: ";
    iter(strArr, strSize, printElement<std::string>);
    std::cout << "\n";

    iter(strArr, strSize, appendExclamation);

    std::cout << "After appendExclamation: ";
    iter(strArr, strSize, printElement<std::string>);
    std::cout << "\n\n";

    return 0;
}
