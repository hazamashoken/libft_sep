/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:21:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/13 09:47:46 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//    s: The string from which to create the substring.
//    start: The start index of the substring in the
//    string ’s’.
//    len: The maximum length of the substring.

// DESCRIPTION
//    Allocates (with malloc(3)) and returns a substring
//    from the string ’s’.
//    The substring begins at index ’start’ and is of
//    maximum size ’len’.

// RETURN VALUE
//    The substring.
//    NULL if the allocation fails.

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*(s + start) && i < len)
		*(str + i++) = *(s + start++);
	*(str + i) = '\0';
	return (str);
}
