/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:47:45 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/23 13:23:49 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"
#include <stdio.h>

# define INFO __FILE__, (char *)__FUNCTION__, __LINE__

#define	ANT 		(1 << 0)
#define	START 		(1 << 1)
#define	END 		(1 << 2)
#define STARTEND	(1 << 3)
// #define			(1 << 4)
// #define			(1 << 5)
// #define			(1 << 6)
// #define			(1 << 7)
// #define			(1 << 8)
// #define			(1 << 9)
// #define			(1 << 10)
// #define			(1 << 11)
// #define			(1 << 12)
// #define			(1 << 13)
// #define			(1 << 14)
// #define			(1 << 15)
// #define			(1 << 16)
// #define			(1 << 17)
// #define			(1 << 18)
// #define			(1 << 19)

typedef struct	s_room
{
	char 	*name;
	int		file;

	int		spe;
	struct s_room	*next;
	struct s_room	**child;
}				t_room;

typedef struct 	s_lem
{
	char	*s;
	char	*map;
	char	*order;

	int		f;
	int		ant;
	int		start;
	int		end;
	int		gnl_count;

	int		nline;// number of line (n gnl call)
	
	int 	index;// index for parsing.
	int 	n;// index for parsing.

	char	*start_name;
	char	*end_name;
	t_room	**room_list;

}				t_lem;

//parse.c
void	parse(t_lem *l);
void	check_error(t_lem *l);
void	*saved_line(t_lem *l, char *s);

//parse_error.c
int		next_line(t_lem *l);
int		check_ant(t_lem *l);
int		check_room(t_lem *l);
int		check_pipe(t_lem *l);
void	check_error(t_lem *l);

//parse_command.c
int		search_sharp(t_lem *l);
int		iscomment(t_lem *l);
void	is_command(char *s, t_lem *l);

//tools.c
t_lem	*init_struct(t_lem *l);
int 	gne(t_lem *l);
void	saved_map(t_lem *l);
int		get_next_word(char *str, int c);
int		next_line(t_lem *l);

//parse_room.c
t_room	*ft_lstroomnew(void const *name, size_t size, size_t option);
int		room_count_word(const char *s, char c);
int		parse_room(t_lem *l, int o);
// int 	parse_room(t_lem *l);

//void	parse_pipe.c
void 	search_pipe(t_lem *l, char *s);
void	parse_pipe(char *s, t_lem *l);

void	ft_test_room_list(t_room **rlst);

#endif