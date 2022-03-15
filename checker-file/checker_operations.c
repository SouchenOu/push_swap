/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:32:42 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 19:11:47 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/checker.h"

void	do_swap_sa_sb(char *buffer, int sizea, int sizeb)
{
	if (ft_strncmp(buffer, "sa", 2) == 0)
		checker_sa_sb(s_check.stack_a, sizea);
	else if (ft_strncmp(buffer, "sb", 2) == 0)
		checker_sa_sb(s_check.stack_b, sizeb);
}

int	do_push_pa_pb(char *buffer, int sizea, int sizeb)
{
	if (ft_strncmp(buffer, "pa", 2) == 0)
	{
		sizeb = checker_pa_pb(s_check.stack_a, s_check.stack_b, sizea, sizeb);
		sizea++;
	}
	else if (ft_strncmp(buffer, "pb", 2) == 0)
	{
		sizea = checker_pa_pb(s_check.stack_b, s_check.stack_a, sizeb, sizea);
		sizeb++;
	}
	return (sizea);
}

void	do_rotate_ra_rb(char *buffer, int sizea, int sizeb)
{
	if (ft_strncmp(buffer, "rra", 3) == 0)
		checker_rra_rrb(s_check.stack_a, sizea);
	else if (ft_strncmp(buffer, "rrb", 3) == 0)
		checker_rra_rrb(s_check.stack_b, sizeb);
	if (ft_strncmp(buffer, "ra", 2) == 0)
		checker_ra_rb(s_check.stack_a, sizea);
	else if (ft_strncmp(buffer, "rb", 2) == 0)
		checker_ra_rb(s_check.stack_b, sizeb);
}
