/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:34:11 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/18 03:27:14 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*saved line and free*/

void	parse(void)
{
	t_lem		l;

	init_struct(&l);
	get_next_line(0, &l.s);

	parse_ant(&l);//return gnl
	
	search_room(&l);
	// while(get_next_line(0, &s) == 1)
	// {
	// 	if (parse_loop(&l, s))
	// 		map_copy(l.map, s, ft_strlen(s));
	// 	else
	// 		ft_error("ERROR");
	// 	ft_putstr(s);
	// 	ft_putstr("\n");
	// 	l.gnl_count++;
	// }
	ft_putstr("\n----ECHO----\n");
	ft_putstr(l.map);
}
