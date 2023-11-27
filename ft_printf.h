/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:39 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/16 16:14:43 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define B16L "0123456789abcdef"
# define B16U "0123456789ABCDEF"
# define B10 "0123456789"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strlen(const char *s);
int		ft_display_base_s(long long n, char *base);
int		ft_display_base_u(unsigned long long n, char *base);

#endif
