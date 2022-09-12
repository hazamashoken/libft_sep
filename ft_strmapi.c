/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:32:39 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/12 21:29:15 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
// s: The string on which to iterate.
// f: The function to apply to each character.

// DESCRIPTION
// Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

// RETURN VALUE
// The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == (void *)0)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (*(str + i) != '\0')
	{
		*(str + i) = (*f)(i, *(char *)(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
