/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:21:13 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/05 21:09:34 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	len;
	public:
		Array();
		Array(unsigned int _len);
		~Array();
		Array(const Array &cpy);
		Array &operator = (Array const &org);
		unsigned int size() const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		class OutOfSizeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"