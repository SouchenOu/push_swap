/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_to_ends.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:41:50 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:25:51 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	find_position(int stack_a[], int size, int nbr)
{
	int	position;

	size--;
	position = size;
	if (stack_a[size] > nbr && stack_a[0] < nbr)
		return (size);
	while (stack_a[position] > nbr || stack_a[position - 1] < nbr)
		position--;
	return (position - 1);
}

void	actions(int stack_a[], int stack_b[], int sizea, int sizeb)
{
	int		position;
	int		a_position;
	int		b_position;
	int		temp;
	int		actions;

	actions = sizeb + sizea;
	temp = sizeb - 1;
	while (temp >= 0)
	{
		position = find_position(stack_a, sizea, stack_b[temp]);
		if (calculate_actions(position, temp, sizea, sizeb) < actions)
		{
			actions = calculate_actions(position, temp, sizea, sizeb);
			b_position = temp;
			a_position = position;
		}
		temp--;
	}
	push_to_top(stack_a, sizea, a_position, 'a');
	push_to_top(stack_b, sizeb, b_position, 'b');
}

int	next_to_sort6_to_ends(int stack_a[], int stack_b[], int sizea, int *sizeb)
{
	sizea = push_pa_pb(stack_b, stack_a, *sizeb, sizea);
	write (1, "pb\n", 3);
	*sizeb = *sizeb + 1;
	return (sizea);
}

void	sort_6_to_ends(int stack_a[], int stack_b[], int sizea, int sizeb)
{
	int	cmp;

	cmp = sizea + 10;
	while (cmp > 0 && !is_sorted(stack_a, sizea))
	{
		if ((stack_a[sizea - 1] < stack_a[sizea - 2]
				&& stack_a[sizea - 1] > stack_a[0])
			|| stack_a[sizea - 1] == smallest_int(stack_a, sizea)
			|| stack_a[sizea - 1] == biggest_int(stack_a, sizea))
			rotate_ra_rb(stack_a, sizea, 'a');
		else
			sizea = next_to_sort6_to_ends(stack_a, stack_b, sizea, &sizeb);
		cmp--;
	}
	while (sizeb > 0)
	{
		actions(stack_a, stack_b, sizea, sizeb);
		sizeb = push_pa_pb(stack_a, stack_b, sizea, sizeb);
		sizea++;
		write(1, "pa\n", 3);
	}
	push_to_top(stack_a, sizea, smallest_nbr(stack_a, sizea), 'a');
}
