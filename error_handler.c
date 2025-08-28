/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:32:08 by someyer           #+#    #+#             */
/*   Updated: 2025/08/17 23:32:38 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	display_error(void);

int	ft_strlen(char *input)
{
	int	len;

	len = 0;
	while (*input != '\0')
	{
		len++;
		input++;
	}
	return (len);
}

int	error_handler(char *input)
{
	int	len;

	len = ft_strlen(input);
	if (len != 31)
	{
		display_error();
		return (0);
	}
	while (*input != '\0')
	{
		if (!(*input == ' ' || (*input >= '1' && *input <= '4')))
		{
			display_error();
			return (0);
		}
		input++;
	}
	return (1);
}
