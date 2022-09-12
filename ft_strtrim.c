/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:00:10 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/12 19:39:41 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//    s1: The string to be trimmed.
//    set: The reference set of characters to trim.

// DESCRIPTION
//    Allocates (with malloc(3)) and returns a copy of
//    ’s1’ with the characters specified in ’set’ removed
//    from the beginning and the end of the string.

// RETURN VALUE
//    The trimmed string.
//    NULL if the allocation fails.

#include	"libft.h"

int	check_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(unsigned char *)(set + i))
		if (*(unsigned char *)(set + i) == c)
			return (1);
	return (0);
}

size_t	check_front(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (check_charset(*(unsigned char *)(s1 + i), set) \
		&& *(unsigned char *)(s1 + i))
			i++;
	return (i);
}

size_t	check_back(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (check_charset(*(s1 + i), set) && i > 0)
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	i = 0;
	if (s1 == "" || set == "")
		return (malloc(0));
	start = check_front(s1, set);
	end = check_back(s1, set);
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	while (i < (end - start))
		*(unsigned char *)(str + i) = *(unsigned char *)(s1 + start + i++);
	*(unsigned char *)(str + i) = '\0';
	return (str);
}
