/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:33:18 by dimendon          #+#    #+#             */
/*   Updated: 2024/11/19 14:51:22 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_unsigned_fd(unsigned int n, int fd, int *count)
{
	if (n >= 10)
		putnbr_unsigned_fd(n / 10, fd, count);
	ft_putchar_fd((n % 10) + '0', fd, count);
}

static void	puthex(uintptr_t n, int fd, short int upper, int *count)
{
	if (n / 16 != 0)
		puthex(n / 16, fd, upper, count);
	n %= 16;
	if (n == 10)
		ft_putchar_fd('a' - upper, fd, count);
	else if (n == 11)
		ft_putchar_fd('b' - upper, fd, count);
	else if (n == 12)
		ft_putchar_fd('c' - upper, fd, count);
	else if (n == 13)
		ft_putchar_fd('d' - upper, fd, count);
	else if (n == 14)
		ft_putchar_fd('e' - upper, fd, count);
	else if (n == 15)
		ft_putchar_fd('f' - upper, fd, count);
	else
		putnbr_unsigned_fd(n, fd, count);
}

static void	putptr(void *p, int fd, int *count)
{
	uintptr_t	address;

	address = (uintptr_t)p;
	if (!p)
	{
		(*count) += 5;
		if (write(fd, "(nil)", 5) < 0)
			(*count) = -1;
	}
	else
	{
		ft_putstr_fd("0x", 1, count);
		puthex(address, fd, 0, count);
	}
}

static void	checknprintinput(const char *input, va_list args, int *count)
{
	if (*input == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	else if (*input == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (*input == 'd' || *input == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (*input == 'u')
		putnbr_unsigned_fd(va_arg(args, unsigned int), 1, count);
	else if (*input == 'x')
		puthex(va_arg(args, unsigned int), 1, 0, count);
	else if (*input == 'X')
		puthex(va_arg(args, unsigned int), 1, 32, count);
	else if (*input == 'p')
		putptr(va_arg(args, void *), 1, count);
	else if (*input == '%')
		ft_putchar_fd('%', 1, count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s != '\0' && count >= 0)
	{
		if (*s == '%' && (*(s + 1) == 'c' || *(s + 1) == 's' || *(s + 1) == 'd'
				|| *(s + 1) == 'i' || *(s + 1) == 'u' || *(s + 1) == 'x' || *(s
					+ 1) == 'X' || *(s + 1) == 'p' || *(s + 1) == '%'))
		{
			s++;
			checknprintinput(s, args, &count);
		}
		else
		{
			if (write(1, s, 1) < 0)
				count = -1;
			else
				count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
