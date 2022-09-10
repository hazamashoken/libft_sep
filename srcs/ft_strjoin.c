/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:46:55 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/10 11:54:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//     s1: The prefix string.
//     s2: The suffix string.

// DESCRIPTION
//    Allocates (with malloc(3)) and returns a new
//    string, which is the result of the concatenation
//    of ’s1’ and ’s2’.

// RETURN VALUE
//    The new string.
//    NULL if the allocation fails.

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*str;

	k = 0;
	if (s1 == "" || s2 == "")
		return (malloc(0));
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	i = 0;
	while (*(unsigned char *)(s1 + i))
		*(unsigned char *)(str + k++) = *(unsigned char *)(s1 + i++);
	i = 0;
	while (*(unsigned char *)(s2 + i))
		*(unsigned char *)(str + k++) = *(unsigned char *)(s2 + i++);
	*(unsigned char *)(str + k) = '\0';
	return (str);
}
