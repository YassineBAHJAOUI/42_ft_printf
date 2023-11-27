/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:12:14 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/16 16:12:36 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (*(s + (++i)))
		if (*(s + i) == (unsigned char) c)
			return ((char *)s + i);
	if (*(s + i) == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

static int	check_numeric(va_list *ptr, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*ptr, int));
	if (c == 'd' || c == 'i')
		len += ft_display_base_s(va_arg(*ptr, int), B10);
	if (c == 'x')
		len += ft_display_base_u(va_arg(*ptr, unsigned int), B16L);
	if (c == 'X')
		len += ft_display_base_u(va_arg(*ptr, unsigned int), B16U);
	if (c == '%')
		len += ft_putchar(c);
	if (c == 'u')
		len += ft_display_base_u(va_arg(*ptr, unsigned int), B10);
	return (len);
}

static int	check_string_pointer(va_list *ptr, char c)
{
	int		len;
	void	*ptr_value;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(*ptr, char *));
	if (c == 'p')
	{
		ptr_value = va_arg(*ptr, void *);
		if (ptr_value == NULL)
			len += ft_putstr("(nil)");
		else
		{
			len += write(1, "0x", 2);
			len += ft_display_base_u((unsigned long long)ptr_value, B16L);
		}
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ptr;
	int		len;
	int		i;

	i = -1;
	len = 0;
	va_start(ptr, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			len += write(1, &fmt[i], 1);
			if (len < 0)
				return (-1);
		}
		if (fmt[i] == '%' && fmt[i + 1])
		{
			if (ft_strchr("icduxX%", fmt[i + 1]))
			len += check_numeric(&ptr, fmt[i + 1]);
			else if (ft_strchr("sp", fmt[i + 1]))
			len += check_string_pointer(&ptr, fmt[i + 1]);
			i++;
		}
	}
	return (va_end(ptr), len);
}
