/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:13:40 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/13 10:05:35 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//    n: the integer to convert.

// DESCRIPTION
//    Allocates (with malloc(3)) and returns a string
//    representing the integer received as an argument.
//    Negative numbers must be handled.

// RETURN VALUE
//    The string representing the integer.
//    NULL if the allocation fails.

#include	"libft.h"

size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (++len);
}


char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = numlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n = -n;
		*res = '-';
	}
	while (i < len)
	{
		*(res + (len - i)) = (n % 10) + '0';
		n /= 10;
		i++;
	}
	*(res + len) = '\0';
	return (res);
}
