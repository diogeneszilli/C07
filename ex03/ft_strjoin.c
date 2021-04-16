/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dludtke- <dludtke-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:18:08 by dludtke-          #+#    #+#             */
/*   Updated: 2021/04/16 14:37:50 by dludtke-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strslen(char **strs, int size)
{
	int i;
	int total_chars;

	i = 0;
	total_chars = 0;
	while (i < size)
	{
		total_chars += ft_strlen(strs[i]);
		i++;
	}
	return (total_chars);
}

void	ft_getstrjoin(int size, char **strs, char *sep, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			str[k++] = strs[i][j++];
		j = 0;
		if ((i + 1) < size)
		{
			while (j < ft_strlen(sep))
				str[k++] = sep[j++];
		}
		i++;
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		total_chars;
	int		sep_size;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		return (str);
	}
	total_chars = ft_strslen(strs, size);
	sep_size = ft_strlen(sep);
	str = malloc(total_chars + (size * sep_size) * sizeof(char));
	ft_getstrjoin(size, strs, sep, str);
	return (str);
}
