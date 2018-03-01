/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:43:13 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/01 20:03:28 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_test_room_pipe(t_room *rlst);

void	get_data(t_lem *l)
{
	int		len;
	size_t	i;
	char	*s;
	int		parse_data;
	int pipe = 0;
	int name_size;

	parse_data = 1;
	i = 0;
	if (!(l->map = ft_strndup("\0", 1)))
		exit(1);
	while (get_next_line(0, &s) > 0)
	{
		if (parse_data && *s == 0)// empty line = Break SAVED
		{
			// ft_printf("{blue}END of SAVED{eoc}");
			parse_data = 0;
			// saved_map continue && no data
		}
		if (parse_data == 1)
		{
				 if (!(l->f & 0xFFFFFFFF) && isvalid_ant_number(s) == 1)
				{
					check_ant(&*l, s);
					// ft_printf("{green}Ant OK ✓{eoc}");
				}
				else if (((l->f & 0x6) != 0x6) && isvalid_command(s) && (!(l->f & 24)))
				{
					parse_order(&*l, s);
					// ft_printf("{green}Order OK ✓{eoc}");
				}
				else if (isvalid_comment(s))
					;// ft_printf("{green}Comment OK ✓{eoc}");
				else if ((pipe == 0) && (name_size = isvalid_room(s)))
				{//recup le return de isvalid room qui est egal a len du room name
					parse_room(&*l, s, name_size);/////////////
					// ft_printf("{green}Room OK ✓{eoc}");
				}
				else if (isvalid_pipe(s) && (!(l->f & 24)))
				{
					if (pipe == 0)
						malloc_ptr_pipe(&*l);
					pipe = 1;
					// // if is =valid pipe, cant valid room
					parse_pipe(&*l, s);///////////////////////
					// ft_printf("{green}Pipe OK ✓{eoc}");
				}
				else
				{
					// ft_printf("{red}KO{eoc}", s);
					ft_error("ERROR");
				}
		}
		len = ft_strlen(s);
		if (i++)
		{
			if (!(l->map = ft_strnjoinfree(l->map, "\n", 1, 'L')))
				exit(1);
		}
		if (!(l->map = ft_strnjoinfree(l->map, s, len, 'B')))
			exit(1);
		// ft_printf("\n");
	}
	l->lmap = ft_strsplit(l->map, '\n');
}

int		main(void)
{
	t_lem	l;

	ft_bzero(&l, sizeof(t_lem));
	l.room_list = NULL;
	get_data(&l);	// check_error(&l);
	algo(&l);
	ft_printf("%s\n\n", l.map);
	print_ant(&l);
	return (0);
}
