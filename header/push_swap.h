/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:23:12 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:05:07 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

struct	s_stacks
{
	int	*stack_a;
	int	*stack_b;
}		t_stacks;

int		is_number(const char *nbr);
int		is_duplicated(int stack[], int index, int x);
int		make_stack(char *argv[], int stack[], int argc);
void	swap_sa_sb(int stack[], int size, char c);
void	rotate_ra_rb(int stack[], int size, char c);
void	reverce_rotate(int stack[], int size, char c);
int		push_pa_pb(int stack1[], int stack2[], int size1, int size2);
void	sort_2_3(int stack_a[], int sizea);
void	sort_5(int a[], int b[], int sizea, int sizeb);
void	sort_6_to_ends(int stack_a[], int stack_b[], int sizea, int sizeb);
int		is_sorted(int stack_a[], int sizea);
int		smallest_nbr(int stack[], int size);
void	push_to_top(int stack[], int size, int index, char character);
int		smallest_int(int stack[], int size);
int		biggest_int(int stack[], int size);
int		calculate_actions(int index_a, int index_b, int sizea, int sizeb);

#endif
