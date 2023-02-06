/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:18:26 by cherrero          #+#    #+#             */
/*   Updated: 2023/02/04 22:26:17 by cherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				pos;
	int				end_pos;
	int				len;
	int				target_a;
	int				moves_a;
	int				moves_b;
	int				moves_total;
	int				flag_reverse;
	int				flag_rotate;
	struct s_stack	*next;
}	t_stack;

typedef struct s_node
{
	int				data;
	int				pos;
	int				end_pos;
	int				len;
}	t_node;

int		ft_read_args(t_stack **stack, int argc, char **argv);
int		ft_args_numbers(t_stack **stack, int argc, char **argv);
int		ft_args_string(t_stack **stack, int argc, char **argv);
int		ft_is_integer(long nb);
int		ft_is_sorted(t_stack *lst);
int		ft_stack_is_empty(t_stack *stack);
void	ft_sort_stack_bubble(t_stack *stack);
void	ft_addnode(t_stack **stack, int data, int end_pos);
void	ft_swap_both(t_stack **stack_1, t_stack **stack_2, int print);
void	ft_push(t_stack **stack_1, t_stack **stack_2, char name_stack,
			int print);
void	ft_swap(t_stack **stack, char name_stack, int print);
void	ft_swap_both(t_stack **stack_1, t_stack **stack_2, int print);
int		ft_rotate(t_stack **lst, char name_stack, int print);
void	ft_rotate_both(t_stack **stack_1, t_stack **stack_2, int print);
void	ft_reverse_rotate(t_stack **lst, char number_stack, int print);
void	ft_reverse_rotate_both(t_stack **stack_1, t_stack **stack_2, int print);
void	ft_free_stack(t_stack **lst);
void	ft_free_array(char **array);
t_stack	*ft_last_node(t_stack **lst);
void	ft_del_last_node(t_stack **lst);
void	ft_del_last_node2(t_stack **lst);
void	ft_lst_del_node(t_stack *lst);
t_stack	*ft_before_last_node(t_stack *lst);
t_stack	*ft_copy_stack(t_stack *stack1);
int		ft_find_data_in_stack(int find, t_stack *stack);
void	ft_read_node(t_stack *stack, t_node *node);
void	ft_minus(t_stack *tmp);
void	ft_update_index(t_stack *stack, t_stack *stack_sorted);
void	ft_sort_full(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_calc_target(t_stack *stack_b, t_stack *stack_a);
void	ft_calc_near(t_stack *stack_b, int len);
void	ft_calc_moves(t_stack *stack_b, t_stack	*temp, int len);
void	ft_calc_choose(t_stack	*temp);
int		ft_find_endpos_in_stack(int ind, t_stack *stack);
void	ft_move(t_stack **stack_a, t_stack **stack_b);
void	ft_move2(t_stack *temp, t_stack **stack_a, t_stack **stack_b);
int		ft_min_endpos(t_stack *stack_a);
int		ft_max_endpos(t_stack *stack_a);
void	ft_rotate_iter(t_stack **lst, char name_stack, int print, int iter);
void	ft_reverse_rotate_iter(t_stack **lst, char name_stack, int print,
			int iter);
void	ft_reverse_rotate_both_iter(t_stack **stack_1, t_stack **stack_2,
			int print, int iter);
void	ft_reverse_rotate_and_swap(t_stack **stack_a, char c, int print);
void	ft_rotate_and_swap(t_stack **stack_a, char c, int print);
int		ft_first_end_pos(t_stack *stack_a);
int		ft_second_end_pos(t_stack *stack_a);
int		ft_third_end_pos(t_stack *stack_a);
int		ft_small_second_end_pos(t_stack *stack_a);
void	ft_leaks(void);
void	ft_initnode(t_stack **new, int data, int end_pos, int len);
int		ft_read_lines(t_stack **stack_a, t_stack **stack_b);
int		ft_read_lines_2(t_stack **stack_a, t_stack **stack_b, char *line);
long	ft_atol(const char *str);
int		ft_check_input(char *str);
void	ft_exec_move(t_stack **stack_a, t_stack **stack_b);

#endif
