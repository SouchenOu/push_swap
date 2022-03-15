/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:34:44 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:25:35 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	is_number(const char *nbr)
{
	while (*nbr)
	{
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if (!ft_isdigit(*nbr))
			return (0);
		nbr++;
	}
	return (1);
}

int	is_duplicated(int stack[], int index, int x)
{
	while (index >= 0)
	{
		if (stack[index] == x)
			return (0);
		index--;
	}
	return (1);
}

int	smallest_nbr(int stack[], int size)
{
	int	nbr;
	int	index;

	size--;
	index = size;
	nbr = stack[size];
	while (size >= 0)
	{
		if (stack[size] < nbr)
		{
			nbr = stack[size];
			index = size;
		}
		size--;
	}
	return (index);
}

void	push_to_top(int stack[], int size, int position, char character)
{
	if (position >= size / 2)
	{
		while (size - position > 0)
		{
			if (position == size - 1)
				return ;
			rotate_ra_rb(stack, size, character);
			position++;
		}
	}
	else
	{
		while (position >= 0)
		{
			reverce_rotate(stack, size, character);
			position--;
		}
	}
}

int	is_sorted(int a[], int sizea)
{
	sizea--;
	while ((sizea - 1) >= 0)
	{
		if (a[sizea] < a[sizea - 1])
			sizea--;
		else
			return (0);
	}
	return (1);
}
