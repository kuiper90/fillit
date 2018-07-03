/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 00:01:22 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:53:44 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int num_test;
	int rest;

	num_test = 1;
	rest = n % 10;
	n = n / 10;
	if (rest < 0 || (rest == 0 && n < 0))
	{
		ft_putchar_fd('-', fd);
		n = -n;
		rest = -rest;
	}
	while (num_test * 10 <= n)
		num_test = num_test * 10;
	while (num_test != 0 && n != 0)
	{
		ft_putchar_fd((n / num_test) % 10 + '0', fd);
		num_test = num_test / 10;
	}
	ft_putchar_fd(rest + '0', fd);
}
