/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:50:01 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/17 17:41:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isnumber(char const *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
