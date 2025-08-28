/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:20 by someyer           #+#    #+#             */
/*   Updated: 2025/08/17 16:16:04 by dale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**create_array(int size);
char	*populate_position(int **array, char *input, int row, int col);
char	*populate_columns(int **array, char *input, int size);
char	*populate_rows(int **array, char *input, int size);
int		**populate_array(char *input, int **array, int size);
void	display_error(void);
int		ft_atoi(char *str);

int	**create_array(int size)
{
	int	i;
	int	**array;
	int	*data;

	array = malloc(sizeof(int *) * size);
	data = malloc(sizeof(int) * size * size);
	if (array == NULL || data == NULL)
	{
		if (array)
			free(array);
		if (data)
			free(data);
		display_error();
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		array[i] = data + (i * size);
		i++;
	}
	if (array == NULL)
		return (NULL);
	return (array);
}

char	*populate_position(int **array, char *input, int row, int col)
{
	int	number;

	number = ft_atoi(input);
	array[row][col] = number;
	if (number < 0)
	{
		display_error();
		return (NULL);
	}
	while (*input != ' ' && *input != '\0')
		input++;
	if (*input == ' ')
		input++;
	return (input);
}

char	*populate_columns(int **array, char *input, int size)
{
	int	j;

	j = 1;
	while (j < size - 1)
	{
		input = populate_position(array, input, 0, j);
		j++;
	}
	j = 1;
	while (j < size - 1)
	{
		input = populate_position(array, input, size - 1, j);
		j++;
	}
	return (input);
}

char	*populate_rows(int **array, char *input, int size)
{
	int	i;

	i = 1;
	while (i < size - 1)
	{
		input = populate_position(array, input, i, 0);
		i++;
	}
	i = 1;
	while (i < size - 1)
	{
		input = populate_position(array, input, i, size - 1);
		i++;
	}
	return (input);
}

int	**populate_array(char *input, int **array, int size)
{
	input = populate_columns(array, input, size);
	input = populate_rows(array, input, size);
	return (array);
}
