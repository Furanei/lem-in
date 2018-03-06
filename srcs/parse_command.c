/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:38:12 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/04 21:12:58 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	parse_order(t_lem *l, char *s)
{
	if (ft_strequ(&s[2], "start") && !(l->f & START))
		l->f += START + NEXTSTART;
	else if (ft_strequ(&s[2], "end") && !(l->f & END))
		l->f += END + NEXTEND;
}
