/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:12:20 by someyer           #+#    #+#             */
/*   Updated: 2025/08/17 16:13:38 by dale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char character);
void	ft_putnbr(int nb);
int		find_length(int nb);

int	find_length(int nb)
{
	int	len;

	len = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar('0' + nb % 10);
}

void	ft_putchar(char character)
{
	write(1, &character, 1);
}
