/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:26:50 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/05 21:16:51 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
Array<T>::Array()
{
	arr = NULL;
	len = 0;
	//std::cout << "Array void constructor called\n";
}

template<typename T>
Array<T>::Array(unsigned int size)
{
	arr = new T[len];
	len = size;
	//std::cout << "Array void constructor called\n";
}

template<typename T>
Array<T>::~Array()
{
	delete[] arr;
	//std::cout << "Destructor for Array called\n";
}

template<typename T>
Array<T>::Array(const Array<T> &cpy)
    : arr(NULL), len(cpy.len)
{
    if (len > 0) {
        arr = new T[len];
        for (unsigned int i = 0; i < len; i++) {
            arr[i] = cpy.arr[i];
        }
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &cpy)
{
    if (this != &cpy) {
        delete[] arr;

        len = cpy.len;
        if (len > 0) {
            arr = new T[len];
            for (unsigned int i = 0; i < len; i++) {
                arr[i] = cpy.arr[i];
            }
        }
        else {
            arr = NULL;
        }
    }
    return *this;
}


template <typename T>
unsigned int Array<T>::size() const
{
	return (len);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw OutOfSizeException();
	return (arr[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= len)
		throw OutOfSizeException();
	return (arr[index]);
}

template <typename T>
const char *Array<T>::OutOfSizeException::what() const throw()
{
	return ("Error! Index out of array size!\n");
}
