/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:24:51 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 19:12:02 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/checker.h"

void	checker_sa_sb(int stack[], int size)
{
	int	temp;

	if (size < 2)
		return ;
	size--;
	temp = stack[size];
	stack[size] = stack[size - 1];
	stack[size - 1] = temp;
}

void	checker_ra_rb(int stack[], int size)
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
}

void	checker_rra_rrb(int stack[], int size)
{
	int	temp;
	int	x;

	x = 0;
	temp = stack[0];
	if (size < 2)
		return ;
	size--;
	while (x < size)
	{
		stack[x] = stack[x + 1];
		x++;
	}
	stack[x] = temp;
}

int	checker_pa_pb(int stacka[], int stackb[], int size1, int size2)
{
	size2--;
	stacka[size1] = stackb[size2];
	stackb[size2] = 0;
	return (size2);
}
