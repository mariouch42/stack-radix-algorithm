#include "push_swap.h"

int	is_valid_number(char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static int	fill_arr(int *arr, char *str, int size)
{
	char	**words;
	int		i;

	words = ft_split(str, ' ');
	if (!words)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!is_valid_number(words[i]))
		{
			free_all(words, size);
			return (0);
		}
		arr[i] = (int)ft_atol(words[i]);
		i++;
	}
	free_all(words, size);
	return (1);
}

static int	*parse_single(char *str, int *size)
{
	int	*arr;

	*size = (int)count_words(str, ' ');
	if (*size == 0)
		return (NULL);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);
	if (!fill_arr(arr, str, *size))
	{
		free(arr);
		return (NULL);
	}
	if (has_duplicates(arr, *size))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

int	*parse_input(int argc, char **argv, int *size)
{
	if (argc == 2)
		return (parse_single(argv[1], size));
	*size = argc - 1;
	return (parse_multi(argv, *size));
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}
