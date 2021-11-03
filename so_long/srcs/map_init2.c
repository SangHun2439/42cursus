/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:00:02 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 11:04:12 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init_rst(t_mlx *mlx, t_imgset *p_imgset)
{
	p_imgset->rst_turtle[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st1.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st2.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st3.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st4.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[4] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st5.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[5] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st6.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[6] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st7.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[7] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st8.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rst_turtle[8] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/right_st9.xpm", &(p_imgset->size), &(p_imgset->size));
}

void	img_init_lst(t_mlx *mlx, t_imgset *p_imgset)
{
	p_imgset->lst_turtle[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st1.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st2.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st3.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st4.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[4] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st5.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[5] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st6.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[6] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st7.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[7] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st8.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lst_turtle[8] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./stand/left_st9.xpm", &(p_imgset->size), &(p_imgset->size));
}

void	img_init_rmv(t_mlx *mlx, t_imgset *p_imgset)
{
	p_imgset->rmv_turtle[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv1.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv2.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv3.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv4.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[4] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv5.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[5] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv6.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[6] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv7.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[7] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv8.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[8] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv9.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[9] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv10.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[10] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv11.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->rmv_turtle[11] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/right_mv12.xpm", &(p_imgset->size), &(p_imgset->size));
}

void	img_init_lmv(t_mlx *mlx, t_imgset *p_imgset)
{
	p_imgset->lmv_turtle[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv1.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv2.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv3.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv4.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[4] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv5.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[5] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv6.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[6] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv7.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[7] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv8.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[8] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv9.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[9] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv10.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[10] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv11.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->lmv_turtle[11] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./move/left_mv12.xpm", &(p_imgset->size), &(p_imgset->size));
}
