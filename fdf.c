/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:20:22 by gsferopo          #+#    #+#             */
/*   Updated: 2017/06/30 16:47:57 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_hook(int keycode, t_proc *a)
{
	if (keycode == 2)
		a->rot = ft_clamp(0, 360, a->rot + 1);
	if (keycode == 1)
		a->rot = 45;
	if (keycode == 0)
		a->rot = ft_clamp(0, 360, a->rot - 1);
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		a->indx -= 20;
	if (keycode == 124)
		a->indx += 20;
	if (keycode == 126)
		a->indy -= 20;
	if (keycode == 125)
		a->indy += 20;
	if (keycode == 69)
		a->zoom += 3;
	if (keycode == 78)
		a->zoom = ft_clamp(0, a->zoom, a->zoom - 3);
	mlx_clear_window(a->mlx, a->win);
	printchar(a);
	return (1);
}

int				rv(int x, int y, int s, t_proc *a)
{
	int			v;

	if (s == 1)
		if (a->rot != 45)
			v = x * cos(a->rot) + y * sin(a->rot);
		else
			v = (x - y);
	else
	{
		if (a->rot != 45)
			v = (x * -1) * sin(a->rot) + y * cos(a->rot);
		else
			v = round((x + y) / 2);
	}
	return (v);
}

int				printchar(t_proc *a)
{
	AX = 0;
	AY = -1;
	while (AM[AX][++AY] != -100)
	{
		while (AM[++AX][AY] != -100)
		{
			a->i = rv((AX * AZ * 2), (AY * AZ * 2), -1, a);
			a->i += a->indy - (AMX * a->zoom / 5);
			ASX = (rv((AX * AZ), (AY * AZ * 2), 1, a) + a->indx) * 1000 + a->i;
		}
		AX = 0;
	}
	printchar_p2(a);
	return (1);
}

int				fillarry(t_proc *a)
{
	char	**strsplt;

	AX = 0;
	AY = 0;
	while (get_next_line(a->fd, &a->line) == 1)
	{
		strsplt = ft_strsplit(a->line, ' ');
		while (*strsplt)
		{
			AMX = ft_atoi(*strsplt);
			AX++;
			strsplt++;
		}
		AMX = -100;
		AY++;
		AX = 0;
	}
	AMX = -100;
	return (1);
}

int				main(int ac, char **av)
{
	t_proc a;

	if (ac != 2)
	{
		puts("No file specified!");
		return (0);
	}
	a.x = 0;
	a.y = 0;
	a.rot = 45;
	a.fd = open(av[1], O_RDONLY);
	a.indx = 500;
	a.indy = 500;
	a.zoom = 8;
	a.zoom = 14;
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 1920, 1080, av[1]);
	fillarry(&a);
	printchar(&a);
	mlx_key_hook(a.win, key_hook, &a);
	mlx_string_put(a.mlx, a.win, a.x / 3, a.y / 2, WHITE, "George is Awesome");
	mlx_loop(a.mlx);
}
