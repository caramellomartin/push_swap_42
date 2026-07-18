/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:48:48 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/26 17:47:07 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	addstr(char	*ptr, char *str, int start)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ptr[start + i] = str[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	str1 = "";
	str2 = "";
	if (s1)
		str1 = (char *)s1;
	if (s2)
		str2 = (char *)s2;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	ptr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ptr)
		return (0);
	addstr(ptr, str1, 0);
	addstr(ptr, str2, len1);
	ptr[len1 + len2] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*source;
	size_t	i;
	size_t	srclen;

	source = (char *)src;
	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srclen);
	while (i < (size - 1) && source[i])
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	actualsize;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strjoin("", ""));
	actualsize = ft_strlen(s + start);
	if (len > actualsize)
		len = actualsize;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
