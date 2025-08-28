/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:32:57 by someyer           #+#    #+#             */
/*   Updated: 2025/08/17 23:03:09 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_error(void)
{
	char	*error_message;

	error_message = "Error\n";
	write(1, error_message, 6);
}

int	ft_atoi(char *str)
{
	int		i;
	int		number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	if (!(str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
		return (0);
	else if (str[i] == '-')
	{
		if (sign == -1 || str[i] == '+')
			return (0);
		sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == ' ')
		return (sign * number);
	return (sign * number);
}
