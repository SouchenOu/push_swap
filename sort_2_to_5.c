/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:35:44 by souchen           #+#    #+#             */
/*   Updated: 2022/03/13 09:20:47 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	check_order(int stack_a[])
{
	if (stack_a[2] > stack_a[1] && stack_a[2] < stack_a[0])
		return (1);
	if (stack_a[1] > stack_a[0] && stack_a[1] < stack_a[2])
		return (2);
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		return (3);
	if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		return (4);
	if (stack_a[2] > stack_a[0] && stack_a[2] < stack_a[1])
		return (5);
	else
		return (-1);
}

void	sort_2(int stack_a[])
{
	if (stack_a[1] > stack_a[0])
		swap_sa_sb(stack_a, 2, 'a');
}

void	sort_2_3(int stack_a[], int sizea)
{
	int	x;

	if (sizea == 2)
	{
		sort_2(stack_a);
		return ;
	}
	x = check_order(stack_a);
	if (x == 1)
		swap_sa_sb(stack_a, 3, 'a');
	else if (x == 2)
	{
		swap_sa_sb(stack_a, sizea, 'a');
		reverce_rotate(stack_a, sizea, 'a');
	}
	else if (x == 3)
		rotate_ra_rb(stack_a, sizea, 'a');
	else if (x == 4)
	{
		swap_sa_sb(stack_a, sizea, 'a');
		rotate_ra_rb(stack_a, sizea, 'a');
	}
	else if (x == 5)
		reverce_rotate(stack_a, sizea, 'a');
}

void	sort_5(int stack_a[], int stack_b[], int sizea, int sizeb)
{
	int	x;

	x = sizea;
	push_to_top(stack_a, sizea, smallest_nbr(stack_a, sizea), 'a');
	sizea = push_pa_pb(stack_b, stack_a, sizeb, sizea);
	ft_printf("pb\n");
	sizeb++;
	if (sizea == 4)
	{
		push_to_top(stack_a, sizea, smallest_nbr(stack_a, sizea), 'a');
		sizea = push_pa_pb(stack_b, stack_a, sizeb, sizea);
		ft_printf("pb\n");
		sizeb++;
	}
	sort_2_3(stack_a, sizea);
	sizeb = push_pa_pb(stack_a, stack_b, sizea, sizeb);
	ft_printf("pa\n");
	sizea++;
	if (x == 5)
	{
		sizeb = push_pa_pb(stack_a, stack_b, sizea, sizeb);
		ft_printf("pa\n");
		sizea++;
	}
}
