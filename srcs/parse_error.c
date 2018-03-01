/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:58:44 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/01 20:08:35 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

unsigned long long	atoi_lem(char const *str)
{
	unsigned long long	i;
	unsigned long long	j;
	int					neg;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	j = i;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && j == i)
	{
		neg = -1;
		i++;
	}
	j = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		j = j * 10 + (str[i] - 48);
		i++;
	}
	j *= neg;
	(j > 2147483647) ? ft_error("ERROR") : 0;
	return (j);
}

void				check_ant(t_lem *l, char *s)
{
	if (l->f & 0xFFFFFFFE || !(ft_isnumber(s,
	ft_strlen(s))))
		ft_error("ERROR (ant_error)");
	if ((l->ant = atoi_lem(s)) <= 0)
		ft_error("ERROR (no_ant)");
	l->f += ANT;
}
