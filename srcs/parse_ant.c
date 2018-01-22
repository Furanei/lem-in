/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:25:39 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/20 13:54:34 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_ant(t_lem *l)
{
// 	// if (l->f & 0xFFFFFFFE || !(ft_isnumber(l->s, ft_strlen(l->s))))
// 	// 	ft_error_info(INFO, "ants");
	l->ant = ft_atoi(l->s);
	return(gne(l));
}
