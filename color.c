/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:08 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/07 18:32:11 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_blue(int trgb)
{
	return ((trgb & 0xFF));
}

int blend_with_white(int color, float blend_factor)
{
    int red = get_red(color);
    int green = get_green(color);
    // int blue = get_blue(color);
	int blue = color % 256;
	 int white_blend = (color / 2) % 256;
	blue = (blue + white_blend) / 2;


    red = (int)(red + blend_factor * (255 - red));
    // green = green + blend_factor * (255 - green);
    blue = (int)(blue + blend_factor * (255 - blue));

    return create_trgb(0, red, green, blue);
}

int get_color(int iter, int max_iter)
{
    int color;
    float blend_factor; // Change this value to increase/decrease the amount of white
	float distance_factor;

    color = iter * 25;
	// color = iter * 255 / max_iter;
    color = create_trgb(0, get_red(color), get_green(color), get_blue(color));
	distance_factor = (float)iter / max_iter;
	blend_factor = pow(1.0 - distance_factor, 3.0);
    return blend_with_white(color, blend_factor);
}