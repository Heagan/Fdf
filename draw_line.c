/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:53:44 by gsferopo          #+#    #+#             */
/*   Updated: 2017/06/30 16:52:20 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			draw_line(t_proc *a, t_draw *d)
{
	d->dx = d->x2 - d->x1;
	d->dy = d->y2 - d->y1;
	d->steps = abs(d->dx) > abs(d->dy) ? abs(d->dx) : abs(d->dy);
	d->xinc = d->dx / (float)d->steps;
	d->yinc = d->dy / (float)d->steps;
	d->x = d->x1;
	d->y = d->y1;
	d->i = -1;
	while (++d->i <= d->steps)
	{
		a->i = sqrt(pow(d->x2 - d->x1, 2) + pow(d->y2 - d->y1, 2));
		if (!(a->i > (a->zoom * 3) * 5))
		{
			put_pixel(a, d->x, d->y);
			d->x += d->xinc;
			d->y += d->yinc;
		}
	}
	return (1);
}

int			printchar_p2(t_proc *a)
{
	t_draw	d;

	AY = -1;
	AX = -1;
	while (AM[AX][++AY] != -100)
	{
		while (AM[++AX][AY] != -100)
		{
			d.x1 = round(ASX / 1000);
			d.y1 = round(ASX % 1000);
			d.x2 = round(AS[AX + 1][AY] / 1000);
			d.y2 = round(AS[AX + 1][AY] % 1000);
			draw_line(a, &d);
			d.x2 = round(AS[AX][AY + 1] / 1000);
			d.y2 = round(AS[AX][AY + 1] % 1000);
			draw_line(a, &d);
		}
		AX = 0;
	}
	return (1);
}

int			put_pixel(t_proc *a, int x, int y)
{
	if (AMX < 6)
		mlx_pixel_put(a->mlx, a->win, x, y, BLUE);
	else if (AMX > 5)
		mlx_pixel_put(a->mlx, a->win, x, y, RED);
	return (1);
}
