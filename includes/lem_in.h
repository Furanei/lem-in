/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:47:45 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/05 02:22:38 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libftpf/includes/ft_printf.h"
# define INFO		__FILE__, (char *)__FUNCTION__, __LINE__
# define ANT		(1 << 0)
# define START 		(1 << 1)
# define END 		(1 << 2)
# define STARTEND	(1 << 3)
# define S_SIZE		64
# define BUFF_S		2048

typedef struct	s_room
{
	char			*name;
	int				file;
	int				ant;

	int				spe;
	int				npipe;
	struct s_room	*next;
	struct s_room	*thread;
	struct s_room	**pipe;
}				t_room;

typedef struct	s_lem
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
}				t_lem;

/*
**parse.c
*/
void			check_ant(t_lem *l);
int				check_room(t_lem *l);
void			check_error(t_lem *l);
void			malloc_ptr_pipe(t_lem *l);
/*
**parse_command.c
*/
int				search_sharp(t_lem *l);
int				parse_comment(t_lem *l);
void			parse_order(t_lem *l);
/*
**parse_room.c
*/
t_room			*ft_lstroomnew(void const *name, size_t size, size_t option);
int				room_count_word(const char *s, char c);
int				parse_room(t_lem *l, int o);
int				next_word(t_lem *l, int i, char c);
void			room_start_end(t_lem *l, int *option);
void			add_room(t_lem *l, t_room *tmp, int size, int option);
/*
**void	parse_pipe.c
*/
int				check_pipe(t_lem *l);
void			parse_pipe(t_lem *l);
/*
**solve
*/
void			algo(t_lem *l);
/*
**print_ant.c
*/
void			print_ant(t_lem *l);

#endif
