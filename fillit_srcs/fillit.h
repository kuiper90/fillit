/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:02:09 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:25:25 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int l;
	int c;
}				t_point;

typedef struct	s_tetri
{
	t_list		*one_piece;
	char		letter;
}				t_tetri;

typedef struct	s_grid
{
	char		**grid;
	int			size;
}				t_grid;

int				check_links(t_list **point);
int				check_string(char *str);
int				count_hash(char *str);
int				ft_lstcompare(t_list *first_node, t_list *second_node);
char			**conv_mat(char *str);
void			tetri_list(char **mat, t_list **list);
void			del(void *content, size_t size);
t_list			*mat_checker(char *str);
t_list			*file_checker(char *filename);
int				last_line_checker(char *buffer, int bytes_read);
t_list			**tetri_letter(t_list **list);
t_tetri			*list_tetrimino(t_list *tetri_list);
t_list			*read_checker(int fd);
void			link_tetrimino(t_list *tetri_list, t_list **tetrimino_list);
t_list			*tetrimino_builder(int bytes_read, char *buffer);
void			tetrimino_assembly(t_list *tetrimino_list);
void			normalize_tetrimino(t_list **tetrimino_list);
void			move_tetrimino(t_list *tetrimino, int min_line, int min_col);
int				get_min_col(t_list *tetrimino_list);
int				get_min_line(t_list *tetrimino_list);
t_grid			*create_grid(int size);
void			del_grid(t_grid **grid, int i);
t_grid			*copy_grid(t_grid *original_grid);
int				grid_size(t_list *tetrimino_list);
int				put_piece(t_grid **grid, t_list *piece_list, int i, int j);
int				fill_tetri(t_list *tetrimino, t_grid **grid);
t_grid			*get_solution(t_list *tetrimino);
int				try_place(t_grid **grid, t_list *piece_list, int i, int j);
void			exit_error(void);
void			print_man(void);
void			del_piece(t_grid **input_grid, t_list *piece_list,
		int i, int j);
void			print_solution(t_grid *original_grid);

#endif
