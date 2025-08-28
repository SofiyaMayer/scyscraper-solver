/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:39:56 by someyer           #+#    #+#             */
/*   Updated: 2025/08/17 23:34:20 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**create_array(int size);
void	ft_putnbr(int nb);
void	ft_putchar(char character);
int		**populate_array(char *input, int **array, int size);
void	display_error(void);
int		solve(int row, int col, int **matrix, int size);
void	print_arr(int **matrix, int size);
void	print_full_arr(int **matrix, int size);
int		check_solution(int **matrix, int size);
int		error_handler(char *input);

int	main(int argc, char **argv)
{
	int		**matrix;
	char	*input;
	int		check_error;

	if (argc == 2)
	{
		input = argv[1];
		if (error_handler(input) == 0)
			return (-1);
		matrix = populate_array(input, create_array(6), 6);
		solve(1, 1, matrix, 4);
		if (!check_solution(matrix, 4))
		{
			display_error();
			return (-1);
		}
		print_full_arr(matrix, 6);
	}
	else
	{
		display_error();
		return (-1);
	}
}

void	print_arr(int **matrix, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			ft_putnbr(matrix[i][j]);
			if (j != size - 2)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_full_arr(int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putnbr(matrix[i][j]);
			if (j != size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
