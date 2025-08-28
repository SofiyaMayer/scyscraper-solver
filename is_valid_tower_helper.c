/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_tower_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dale <dale@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:45:49 by dale              #+#    #+#             */
/*   Updated: 2025/08/17 14:47:53 by dale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*row_to_arr(int row, int **matrix, int size)
{
	int	*arr;
	int	i;

	arr = (int *) malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[i] = matrix[row][i + 1];
		i++;
	}
	return (arr);
}

// Makes column in matrix a 1D array, may reverse
int	*col_to_arr(int col, int rev_col, int **matrix, int size)
{
	int	*arr;
	int	i;

	arr = (int *) malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		if (rev_col)
			arr[i] = matrix[size - i][col];
		else
			arr[i] = matrix[i + 1][col];
		i++;
	}
	return (arr);
}

int	*rev_row(int row, int **matrix, int size)
{
	int	*arr;
	int	i;

	arr = (int *) malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[i] = matrix[row][size - i];
		i++;
	}
	return (arr);
}

int	search_row(int n, int row, int **matrix, int bound)
{
	int	i;

	i = 1;
	while (i < bound)
	{
		if (n == matrix[row][i])
			return (1);
		i++;
	}
	return (0);
}

int	search_col(int n, int col, int **matrix, int bound)
{
	int	i;

	i = 1;
	while (i < bound)
	{
		if (n == matrix[i][col])
			return (1);
		i++;
	}
	return (0);
}
