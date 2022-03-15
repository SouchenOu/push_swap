/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:31:19 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:25:13 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

void	swap_sa_sb(int stack[], int size, char character)
{
	int	temp;

	if (size < 2)
		return ;
	size--;
	temp = stack[size];
	stack[size] = stack[(size - 1)];
	stack[(size - 1)] = temp;
	if (character)
		ft_printf("s%c\n", character);
}

void	rotate_ra_rb(int stack[], int size, char character)
{
	int	temp;

	if (size < 2)
		return ;
	size--;
	temp = stack[size];
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = temp;
	if (character)
		ft_printf("r%c\n", character);
}

void	reverce_rotate(int stack[], int size, char character)
{
	int	temp;
	int	x;

	if (size < 2)
		return ;
	size--;
	temp = stack[0];
	x = 0;
	while (x < size)
	{
		stack[x] = stack[x + 1];
		x++;
	}
	stack[x] = temp;
	if (character)
		ft_printf("rr%c\n", character);
}

int	push_pa_pb(int stack1[], int stack2[], int size1, int size2)
{
	size2--;
	stack1[size1] = stack2[size2];
	stack2[size2] = 0;
	return (size2);
}
