/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:13:19 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/12 21:44:54 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//    s: The string to be split.
//    c: The delimiter character.

// DESCRIPTION
//    Allocates (with malloc(3)) and returns an array
//    of strings obtained by splitting ’s’ using the
//    character ’c’ as a delimiter. The array must end
//    with a NULL pointer.

// RETURN VALUE
//    The array of new strings resulting from the split.
//    NULL if the allocation fails.

#include	"libft.h"

int	check_separator(char s, char c)
{
	return (s == c);
}

int	count_string(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (*(unsigned char *)(str + i) != '\0')
	{
		while (*(unsigned char *)(str + i) != '\0' \
			&& *(unsigned char *)(str + i) == c)
			i++;
		if (*(unsigned char *)(str + i) != '\0')
			count++;
		while (*(unsigned char *)(str + i) != '\0' \
			&& *(unsigned char *)(str + i) != c)
			i++;
	}
	return (count);
}

int	strlen_sep(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(unsigned char *)(str + i) != '\0' \
	&& check_separator(*(unsigned char *)(str + i), c) == 0)
		i++;
	return (i);
}

char	*word(const char *str, char c)
{
	size_t			word_len;
	size_t			i;
	char			*word;

	i = 0;
	word_len = strlen_sep(str, c);
	word = (char *)malloc(sizeof(char) * word_len + 1);
	if (word == NULL)
		return (NULL);
	while (i < word_len)
	{
		*(unsigned char *)(word + i) = *(unsigned char *)(str + i);
		i++;
	}
	*(unsigned char *)(word + i) = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	size_t			i;
	size_t			k;

	i = 0;
	k = 0;
	if (s == (void *)0)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) \
		* (count_string(s, c) + 1));
	if (strings == NULL)
		return (NULL);
	while (*(char *)(s + k) != '\0')
	{
		while (*(char *)(s + k) != '\0' \
			&& check_separator(*(s + k), c))
			k++;
		if (*(char *)(s + k) != '\0')
			*(strings + i++) = word((s + k), c);
		while (*(char *)(s + k) != '\0' \
			&& check_separator(*(s + k), c))
			k++;
	}
	*(strings + i) = 0;
	return (strings);
}
