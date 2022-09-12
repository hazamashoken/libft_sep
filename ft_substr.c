/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:21:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/12 21:02:51 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//    s: The string from which to create the substring.
//    start: The start index of the substring in the
//    string ’s’.
//    len: The maximum length of the substring.

// DESCRIPTION
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

	i = 0;
	if (s == NULL || start >= ft_strlen(s))
		return (malloc(0));
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len && i < ft_strlen(s))
	{
		*(unsigned char *)(str + i) = *(unsigned char *)(s + start + i);
		i++;
	}
	*(unsigned char *)(str + i) = '\0';
	return (str);
}
