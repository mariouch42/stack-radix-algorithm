#include "push_swap.h"

static	int	fill_array(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
		{
			arr[k] = ft_substr(s, i, j);
			if (!arr[k])
				return (free_all(arr, k), 0);
			k++;
		}
		i += j;
	}
	arr[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!fill_array(arr, s, c))
		return (NULL);
	return (arr);
}
