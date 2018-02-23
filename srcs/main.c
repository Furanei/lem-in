/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:43:13 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/23 23:25:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_data(t_lem *l)
{
	int		len;
	size_t	i;
	char	*s;
	int		parse_data;
	int pipe = 0;

	parse_data = 1;
	i = 0;
	if (!(l->map = ft_strndup("\0", 1)))
		exit(1);
	while (get_next_line(0, &s) > 0)
	{
		ft_printf("%ld- \t\t{bold}%s{eoc} ", i, s);
		if (parse_data && *s == 0)// empty line = Break SAVED
		{
			ft_printf("{blue}END of SAVED{eoc}");
			parse_data = 0;
			// saved_map continue && no data
		}
		if (parse_data == 1)
		{
				 if (!(l->f & 0xFFFFFFFF) && isvalid_ant_number(s) == 1)
				{
					check_ant(&*l, s);
					ft_printf("{blue}ant number is OK!{eoc}");
				}
				else if (((l->f & 0x6) != 0x6) && isvalid_command(s))
						ft_printf("{blue}Order found!{eoc}");
				else if (isvalid_comment(s))
					ft_printf("{blue}Comment here!{eoc}");
				else if ((pipe == 0) && isvalid_room(s))//create spacial entry for ##s ##end
				{
					//saved room
					parse_room(&*l, s, 0);/////////////
					ft_printf("{blue}Room valid{eoc}");
				}
				else if (isvalid_pipe(s))
				{
					if (pipe == 0)
						malloc_ptr_pipe(&*l);
					// pipe = 1;
					// // if is =valid pipe, cant valid room
					// //saved pipe
					parse_pipe(&*l, s);///////////////////////
					ft_printf("{blue}Pipe valid{eoc}");
				}
				else
					ft_printf("{red}invalid line{eoc}", s);
		}
		len = ft_strlen(s);
		if (i++)
		{
			if (!(l->map = ft_strnjoinfree(l->map, "\n", 1, 'L')))
				exit(1);
		}
		if (!(l->map = ft_strnjoinfree(l->map, s, len, 'B')))
			exit(1);
		ft_printf("\n");
	}
	l->lmap = ft_strsplit(l->map, '\n');
}

// void	check_error(t_lem *l)
// {
// 	check_ant(&*l);
// 	check_room(&*l);
// 	malloc_ptr_pipe(&*l);
// 	check_pipe(&*l);
// }

int		main(void)
{
	t_lem	l;

	ft_bzero(&l, sizeof(t_lem));
	l.room_list = NULL;
	get_data(&l);
	// check_error(&l);
	// algo(&l);
	// ft_printf("%s\n\n", l.map);
	// print_ant(&l);
	return (0);
}
