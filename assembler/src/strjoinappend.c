/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoinappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:08:42 by esouza            #+#    #+#             */
/*   Updated: 2018/11/22 10:51:20 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char	*ft_getresult(char *s1, char *s2, char *array)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	//while (s1[i] != '\0')
	while (s1[i] != '\0' && s1[i] != COMMENT_CHAR)
	{
		array[i] = s1[i];
		i++;
	}
	//while (s2[k] != '\0')
	while (s2[k] != '\0' && s2[k] != COMMENT_CHAR)
	{
		array[i] = s2[k];
		i++;
		k++;
	}
	array[i++] = '$';
	array[i] = '\0';
	free(s1);
	return (array);
}

char		*strjoinappend(char *s1, char *s2)
{
	int		len;
	char	*array;

	if (s1 && s2)
	{
		len = ((ft_strlen((char *)s1)) + (ft_strlen((char *)s2)) + 2);
		if (!(array = (char *)malloc(sizeof(*array) * len)))
			return (NULL);
		return (ft_getresult(s1, s2, array));
	}
	return (NULL);
}
