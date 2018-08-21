/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:35:57 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/25 15:35:58 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <fcntl.h>
# include "../includes/libft.h"

int					g_print_flag;
int					g_fd;

typedef struct		s_lemin
{
	int				print;
	int				label;
	int				step;
	int				start;
	int				end;
	char			*room;
	int				ant;
	struct s_lemin	**link;
	int				link_count;
	struct s_lemin	*next;
}					t_lemin;

typedef struct		s_data
{
	char			**data;
	int				ant_count;
}					t_data;

char				*set_room_name(char *line);
void				realloc_link(t_lemin *r1, t_lemin *r2);
void				free_t_lemin(t_lemin *l);
int					check_room(char *line);
int					check_link(char *line);
int					check_line(char *line, t_data *d);
int					check_line2(char *line, t_data *d);
t_lemin				*get_new_lemin(char *line);
t_lemin				*get_new_lemin_start_end(int f, t_lemin *l, t_data *d);
t_lemin				*add_new_room(t_lemin *l, char *line, int f, t_data *d);
void				set_link(t_lemin *r1, t_lemin *r2);
void				add_new_link(t_lemin *l, char *line);
t_lemin				*handler_of_line(t_data *d, t_lemin *l, char *line, int f);
void				mark_roads(t_lemin *l);
t_lemin				*find_start_room(t_lemin *l);
t_lemin				*find_end_room(t_lemin *l);
void				move_ants(int ants, t_lemin *l);
void				print_progress(t_lemin **la, int ants);
void				add_to_print(t_lemin *l, int i);
void				error(int ant_c, t_lemin *l, t_data *d, char *line);
int					check_room_data(char *line, t_data *d, int n);
int					check_link_data(char *line, t_data *d, int f1, int f2);
void				free_t_data(t_data *d);
t_data				*get_t_data(void);
void				print_d_data(t_data *d);
void				realloc_d_data(t_data *d, char *line);
void				free_all(t_lemin *l, t_data *d, char *line);
void				free_line(char *line);

#endif
