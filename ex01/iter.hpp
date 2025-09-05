/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:58:00 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/05 20:08:18 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T_array, typename T_function>
void iter(T_array arr, size_t len, T_function func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}
