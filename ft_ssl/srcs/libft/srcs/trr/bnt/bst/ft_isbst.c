/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:06:31 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 12:50:30 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	check_int_node(t_btree *bt)
{
	if (!bt)
		return (true);
	if ((bt->left && *((int *)bt->data) < *((int *)bt->left->data)) ||
		(bt->right && *((int *)bt->data) > *((int *)bt->right->data)))
		return (false);
	return (check_int_node(bt->left) && check_int_node(bt->right));
}

static t_bool	check_long_node(t_btree *bt)
{
	if (!bt)
		return (true);
	if ((bt->left && *((long *)bt->data) < *((long *)bt->left->data)) ||
		(bt->right && *((long *)bt->data) > *((long *)bt->right->data)))
		return (false);
	return (check_long_node(bt->left) && check_long_node(bt->right));
}

static t_bool	check_str_node(t_btree *bt)
{
	if (!bt)
		return (true);
	if ((bt->left && ft_strcmp((char *)bt->left->data, (char *)bt->data) > 0) ||
		(bt->right && ft_strcmp((char *)bt->right->data, (char *)bt->data) < 0))
		return (false);
	return (check_str_node(bt->left) && check_str_node(bt->right));
}

t_bool			ft_isbst(t_btree *bt, char *data_type)
{
	if (ft_strcmp(data_type, "int") == 0)
		return (check_int_node(bt));
	else if (ft_strcmp(data_type, "long") == 0)
		return (check_long_node(bt));
	else if (ft_strcmp(data_type, "str") == 0)
		return (check_str_node(bt));
	else
	{
		ft_printf("error: unknown data type %s\n", data_type);
		return (false);
	}
}
