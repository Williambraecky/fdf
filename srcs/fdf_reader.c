/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:14:19 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/04 11:12:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_convert_list(t_fdf *fdf, t_list *list)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	if (!(fdf->map->data = malloc(sizeof(t_point *) * fdf->map->height)))
		ft_exit("Could not allocate enough memory");
	i = 0;
	while (i < fdf->map->height)
	{
		if (!(fdf->map->data[i] = malloc(sizeof(t_point) * fdf->map->width)))
			ft_exit("Could not allocate enough memory");
		ft_memcpy(fdf->map->data[i], list->content, list->content_size);
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
		i++;
	}
}

void	ft_read_split(char **split, t_fdf *fdf, t_list **list)
{
	t_point	*line;
	int		width;
	int		i;

	width = ft_splitlen(split);
	if (fdf->map->width == -1)
		fdf->map->width = width;
	if (width == 0 || width != fdf->map->width)
		ft_exit("Invalid file");
	if (!(line = malloc(sizeof(t_point) * width)))
		ft_exit("Could not allocate enough memory");
	i = 0;
	while (i < width)
	{
		if (!ft_point_is_valid(split[i]))
			ft_exit("Invalid file");
		line[i] = ft_read_point(split[i]);
		fdf->map->maxheight = ft_max(fdf->map->maxheight, line[i].height);
		fdf->map->minheight = ft_min(fdf->map->minheight, line[i].height);
		free(split[i]);
		i++;
	}
	ft_lstpushback(list, line, width * sizeof(t_point));
	free(line);
}

void	ft_read_map(int fd, t_fdf *fdf)
{
	char	*line;
	char	**split;
	int		ret;
	t_list	*list;

	list = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_exit("Could not read file");
		split = ft_strsplit(line, ' ');
		ft_read_split(split, fdf, &list);
		free(split);
		free(line);
	}
	fdf->map->height = ft_lstlen(list);
	if (fdf->map->height == 0)
		ft_exit("Invalid file 1");
	fdf->map->offsetx = (float)(fdf->map->width - 1) / 2.0;
	fdf->map->offsety = (float)(fdf->map->height - 1) / 2.0;
	ft_convert_list(fdf, list);
}

t_fdf	*ft_read_file(char *file)
{
	t_fdf	*fdf;
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_exit("Invalid file");
	if (!(fdf = ft_new_fdf()))
		ft_exit("Could not allocate enough memory");
	if (!(fdf->map = ft_new_map()))
		ft_exit("Could not allocate enough memory");
	ft_read_map(fd, fdf);
	return (fdf);
}
