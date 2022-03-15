/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:56:07 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 16:57:22 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include "../../header/push_swap.h"

struct	s_check
{
	int	*stack_a;
	int	*stack_b;
}		s_check;

int		make_stack(char *argv[], int stack[], int argc);
void	checker_sa_sb(int stack[], int size);
void	checker_ra_rb(int stack[], int size);
void	checker_rra_rrb(int stack[], int size);
int		checker_pa_pb(int stack1[], int stack2[], int size1, int size2);
int		is_sorted(int a[], int sizea);
void	do_swap_sa_sb(char *buffer, int sizea, int sizeb);
int		do_push_pa_pb(char *buffer, int sizea, int sizeb);
void	do_reverce_rotate(char *buffer, int sizea, int sizeb);
void	do_rotate_ra_rb(char *buffer, int sizea, int sizeb);
int		validation_action(char *str);

#endif
