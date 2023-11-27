/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:13:28 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/16 16:14:03 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret < 0)
		return (-1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;
	int	ret;

	ret = 0;
	if (!s)
	{
		ret = write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	ret = write(1, s, i);
	if (ret < 0)
		return (-1);
	return (i);
}

int	ft_display_base_s(long long n, char *base)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n *= -1;
	}
	ret += ft_display_base_u(n, base);
	return (ret);
}

int	ft_display_base_u(unsigned long long n, char *base)
{
	int					ret;
	unsigned long long	len;
	int					p;

	len = ft_strlen(base);
	ret = 0;
	if (n >= len)
		ret += ft_display_base_u(n / len, base);
	p = write(1, &base[n % len], 1);
	if (p < 0)
		return (-1);
	ret++;
	return (ret);
}
