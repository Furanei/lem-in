/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:47:45 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/02 05:06:22 by mbriffau         ###   ########.fr       */
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
#define S_SIZE		64
#define BUFF_S		2048

typedef struct	s_room
{
	char			*name;
	int				file;
	int				ant;

	int				spe;
	int 			npipe;
	struct s_room	*next;
	struct s_room	*thread;
	struct s_room	**pipe;
}				t_room;

typedef struct 	s_lem
{
	char	*s;
	char	*map;
	char	**lmap;

	int		nb_room;
	int		f;
	int		ant;
	int		start;
	int		end;
	int		i;

	int		nline;// number of line (n gnl call)

	int		index;// index for parsing.
	int		size;// index for parsing.

	char	*start_name;
	char	*end_name;
	t_room	*room_list;
}				t_lem;

//main.c
void	free_lem(t_lem	*l);
void	check_error(t_lem *l);
void	*saved_line(t_lem *l, char *s);

//parse_error.c
void	check_ant(t_lem *l);
int		check_room(t_lem *l);
void	check_error(t_lem *l);

//parse_command.c
int		search_sharp(t_lem *l);
int		parse_comment(t_lem *l);
void	parse_order(t_lem *l);

//tools.c
int		next_line(t_lem *l);
int 	gne(t_lem *l);
void	saved_map(t_lem *l);

//parse_room.c
t_room	*ft_lstroomnew(void const *name, size_t size, size_t option);
int		room_count_word(const char *s, char c);
int		parse_room(t_lem *l, int o);
int		next_word(t_lem *l, int i, char c);

//void	parse_pipe.c
int		check_pipe(t_lem *l);
void	parse_pipe(t_lem *l);

//solve
void	start_algo(t_lem *l);

//print_ant.c
void	print_ant(t_lem *l);

// lem_test.c
void	ft_test_room_list(t_room *rlst);
void	ft_test_room_pipe(t_room *rlst);

#endif