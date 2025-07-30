/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:46:03 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 16:46:05 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rgb_to_hex(int *rgb_color)
{
	int hex;
	int	red;
	int	green;
	int	blue;

	red = rgb_color[0];
	green = rgb_color[1];
	blue = rgb_color[2];
	hex = (red << 16) | (green << 8) | blue;
	return (hex);
}
