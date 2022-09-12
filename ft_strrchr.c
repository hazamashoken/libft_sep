/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:46:54 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/10 11:07:26 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//        The  strchr()  function  returns a pointer to the first occur‐
//        rence of the character c in the string s.
//
//        The strrchr() function returns a pointer to  the  last  occur‐
//        rence of the character c in the string s.
//
//        The  strchrnul() function is like strchr() except that if c is
//        not found in s, then it returns a pointer to the null byte  at
//        the end of s, rather than NULL.
//
//        Here  "character"  means  "byte";  these functions do not work
//        with wide or multibyte characters.
//
// RETURN VALUE
//        The strchr() and strrchr() functions return a pointer  to  the
//        matched  character or NULL if the character is not found.  The
//        terminating null byte is considered part  of  the  string,  so
//        that  if  c  is  specified  as  '\0', these functions return a
//        pointer to the terminator.
//
//        The strchrnul() function returns  a  pointer  to  the  matched
//        character,  or  a  pointer  to  the  null byte at the end of s
//        (i.e., s+strlen(s)) if the character is not found.
#include	"libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;
	int		k;

	i = 0;
	k = -1;
	while (i < ft_strlen(s))
		if (*(unsigned char *)(s + i++) == (unsigned char)c)
			k = --i;
	if (k != -1)
		return (s + k);
	return (0);
}