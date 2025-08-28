/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_tower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:45:42 by dale              #+#    #+#             */
/*   Updated: 2025/08/17 23:34:07 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_visible(int *arr, int size);
int		*row_to_arr(int row, int **matrix, int size);
int		*col_to_arr(int col, int rev_col, int **matrix, int size);
int		*rev_row(int row, int **matrix, int size);
int		search_row(int n, int row, int **matrix, int bound);
int		search_col(int n, int col, int **matrix, int bound);
void	print_full_arr(int **matrix, int size);

int	is_valid_tower(int row, int col, int **matrix, int size)
{
	int	tower;
	int	up_col;
	int	down_col;
	int	right;
	int	left;

	tower = matrix[row][col];
	if (search_row(tower, row, matrix, col)
		|| search_col(tower, col, matrix, row))
		return (0);
	if (col == size || row == size)
	{
		up_col = count_visible(col_to_arr(col, 0, matrix, size), size);
		down_col = count_visible(col_to_arr(col, 1, matrix, size), size);
		right = count_visible(rev_row(row, matrix, size), size);
		left = count_visible(row_to_arr(row, matrix, size), size);
		if ((up_col <= matrix[0][col]
			&& down_col <= matrix[size + 1][col])
			&& (right <= matrix[row][size + 1]
			&& left <= matrix[row][0]))
			return (1);
		else
			return (0);
	}
	return (1);
}
