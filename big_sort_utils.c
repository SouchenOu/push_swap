/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:25:17 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:24:59 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	smallest_int(int stack[], int size)
{
	int	nbr;

	size--;
	nbr = stack[size];
	while (size >= 0)
	{
		if (stack[size] < nbr)
		{
			nbr = stack[size];
		}
		size--;
	}
	return (nbr);
}

int	biggest_int(int stack[], int size)
{
	int	nbr;

	size--;
	nbr = stack[size];
	while (size >= 0)
	{
		if (stack[size] > nbr)
		{
			nbr = stack[size];
		}
		size--;
	}
	return (nbr);
}
