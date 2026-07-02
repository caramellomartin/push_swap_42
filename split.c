#include "push_swap.h"

static int	ft_countwords(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*get_word(const char *s, int *i, char c)
{
	char	*word;
	int		start;
	int		j;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = malloc(sizeof(char) * (*i - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < *i)
	{
		word[j] = s[start];
		j++;
		start++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		w_i;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	w_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			res[w_i++] = get_word(s, &i, c);
	}
	res[w_i] = NULL;
	return (res);
}
