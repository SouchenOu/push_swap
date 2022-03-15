/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:05:31 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:26:53 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_format(const char *type, va_list args)
{
	int	ret;

	if (*type == '%' || *type == 'c')
		ret = chr_type(*type, args);
	else if (*type == 's')
		ret = str_type(args);
	else if (*type == 'i' || *type == 'd')
		ret = int_type(args);
	else if (*type == 'x' || *type == 'X')
		ret = hexa_type(args, *type);
	else if (*type == 'u')
		ret = unsigned_type(args);
	else if (*type == 'p')
		ret = ptr_type(args);
	else
	{
		write (1, &*type, 1);
		ret = 1;
	}
	return (ret);
}

const char	*get_flags(const char *type)
{
	if (*type == '-')
		t_flags.is_minus = true;
	else if (*type == '0')
		t_flags.is_zero = true;
	else if (*type == '.')
	{
		t_flags.is_dot = true;
		t_flags.precision = ft_atoi(type);
		while (*(type + 1) >= '0' && *(type + 1) <= '9')
			type++;
	}
	else if (*type == '#')
		t_flags.is_hash = true;
	else if (*type == ' ')
		t_flags.is_space = true;
	else if (*type == '+')
		t_flags.is_signal = true;
	else if (*type >= '1' && *type <= '9')
	{
		t_flags.width = ft_atoi(type);
		while (*(type + 1) >= '0' && *(type + 1) <= '9')
			type++;
	}
	return (type);
}

void	init_struct(void)
{
	t_flags.is_dot = false;
	t_flags.is_hash = false;
	t_flags.is_minus = false;
	t_flags.is_signal = false;
	t_flags.is_space = false;
	t_flags.is_zero = false;
	t_flags.precision = 0;
	t_flags.width = 0;
}

const char	*get_spec(const char *type)
{
	init_struct();
	while (*type && (*type == '-' || *type == '#'
			|| *type == '.' || *type == ' ' || *type == '+'
			|| (*type >= '0' && *type <= '9')))
	{
		type = get_flags(type);
		type++;
	}
	return (type);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = get_spec(str);
			if (!*str)
				break ;
			count += get_format(str++, args);
		}
		else
		{
			write(1, &*str, 1);
			count++;
			str++;
		}
	}
	va_end(args);
	return (count);
}
