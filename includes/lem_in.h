/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:47:45 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/03 19:13:33 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../lib/includes/ft_printf.h"
# define INFO		__FILE__, (char *)__FUNCTION__, __LINE__
# define ANT		(1 << 0)
# define START 		(1 << 1)
# define END 		(1 << 2)
# define NEXTSTART	(1 << 3)
# define NEXTEND	(1 << 4)
# define PIPE		(1 << 5)
# define DATA		(1 << 6)
# define FIRST_LINE	(1 << 7)
# define ROOM		(1 << 8)

typedef struct		s_room
{
	char			*name;
	int				file;
	int				ant;

	int				spe;
	int				npipe;
	struct s_room	*next;
	struct s_room	*thread;
	struct s_room	**pipe;
}					t_room;

typedef struct		s_lem
{
	char			*s;
	char			*map;
	char			**lmap;
	int				ant;
	int				nb_room;
	int				f;
	int				i;
	int				index;
	int				size;
	t_room			*room_list;
}					t_lem;

/*
**input_analysis
*/
int					isvalid_comment(char *s);
int					isvalid_command(char *s);
int					isvalid_room(char *s);
int					isvalid_pipe(char *s);

/*
**parse_error.c
*/
unsigned long long	atoi_lem(char const *str);
void				check_ant(t_lem *l, char *s);
int					isvalid_ant_number(char *s);

/*
**parse_command.c
*/
int					parse_comment(t_lem *l);
void				parse_order(t_lem *l, char *s);

/*
**parse_room.c
*/
int					parse_room(t_lem *l, char *s, int option);

/*
**void	parse_pipe.c
*/
void				malloc_ptr_pipe(t_lem *l);
void				parse_pipe(t_lem *l, char *s);

/*
**solve
*/
void				algo(t_lem *l);

/*
**mark_the_map
*/
t_room				*mark_the_map(t_room *home);

/*
**print_ant.c
*/
void				print_ant(t_lem *l);

#endif
