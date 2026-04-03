#include "push_swap.h"

static long ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int is_valid_number(char *str)
{
	int		i;
	long	num;

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
	if(num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
static int has_duplicates(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i > size)
	{
		j = i + 1;
		while (j < size)
		{
			if(arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int *parse_input(int argc, char **argv, int *size)
{
	int	*arr;
	int	i;

	*size = argc - 1;
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);

	i = 0;
	while (i < *size)
	{
		if (!is_valid_number (argv[i + 1]))
		{
			free(arr);
			return (NULL);
		}
		arr[i] = (int)ft_atol(argv[i + 1]);
		i++;
	}

	if (has_duplicates(arr, *size))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

void print_error(void)
{
    write(2, "Error\n", 6);
}