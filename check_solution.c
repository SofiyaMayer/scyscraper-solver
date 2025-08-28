/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:59:11 by dale              #+#    #+#             */
/*   Updated: 2025/08/17 23:34:38 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_visible(int *arr, int size);
int	*row_to_arr(int row, int **matrix, int size);
int	*col_to_arr(int col, int rev_col, int **matrix, int size);
int	*rev_row(int row, int **matrix, int size);

int	check_solution(int **matrix, int size)
{
	int	up_col;
	int	down_col;
	int	right;
	int	left;
	int	i;

	i = 0;
	while (i < size)
	{
		up_col = count_visible(col_to_arr(i + 1, 0, matrix, size), size);
		down_col = count_visible(col_to_arr(i + 1, 1, matrix, size), size);
		right = count_visible(rev_row(i + 1, matrix, size), size);
		left = count_visible(row_to_arr(i + 1, matrix, size), size);
		if (up_col != matrix[0][i + 1]
			|| down_col != matrix[size + 1][i + 1]
			|| right != matrix[i + 1][size + 1]
			|| left != matrix[i + 1][0])
			return (0);
		i++;
	}
	return (1);
}
