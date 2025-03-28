/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:53:32 by cahaik            #+#    #+#             */
/*   Updated: 2023/12/27 16:22:45 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	size = 0;
	while (s1[i] != '\0')
	{
		size++;
		i++;
	}
	ptr = (char *)malloc(1 * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
