/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:13:40 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/11 10:56:29 by tliangso         ###   ########.fr       */
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

size_t	check_size(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (--len);
}

char	*ft_itoa(int n)
{
	unsigned char	*str;
	long			nb;
	size_t			len;

	nb = n;
	len = check_size(nb);
	str = (unsigned char *)malloc(len * sizeof(unsigned char) * (len + 1));
	if (str == NULL)
		return (str);
	*(unsigned char *)(str + len--) = '\0';
	if (n == 0)
		*(unsigned char *)(str) = '0';
	if (n < 0)
	{
		*(unsigned char *)(str) = '-';
		n *= -1;
	}
	while (n > 0)
	{
		*(unsigned char *)(str + len--) = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
