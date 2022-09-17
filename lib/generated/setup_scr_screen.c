/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
	static lv_style_t style_screen_main_main_default;
	if (style_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_main_main_default);
	else
		lv_style_init(&style_screen_main_main_default);
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main_main_default, 0);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_11
	ui->screen_img_11 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img_11, 391, 229);
	lv_obj_set_size(ui->screen_img_11, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_11, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_11_main_main_default
	static lv_style_t style_screen_img_11_main_main_default;
	if (style_screen_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_11_main_main_default);
	else
		lv_style_init(&style_screen_img_11_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_11_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_11, &style_screen_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_11,&_icn_slider_25x25);
	lv_img_set_pivot(ui->screen_img_11, 0,0);
	lv_img_set_angle(ui->screen_img_11, 0);

	//Write codes screen_cont_1
	ui->screen_cont_1 = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_1, 0, 19);
	lv_obj_set_size(ui->screen_cont_1, 800, 460);
	lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_cont_1_main_main_default
	static lv_style_t style_screen_cont_1_main_main_default;
	if (style_screen_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_cont_1_main_main_default);
	else
		lv_style_init(&style_screen_cont_1_main_main_default);
	lv_style_set_radius(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_cont_1_main_main_default, lv_color_make(0x34, 0x32, 0x47));
	lv_style_set_bg_grad_color(&style_screen_cont_1_main_main_default, lv_color_make(0x34, 0x32, 0x47));
	lv_style_set_bg_grad_dir(&style_screen_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_cont_1_main_main_default, lv_color_make(0x4a, 0x52, 0x59));
	lv_style_set_border_width(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_cont_1, &style_screen_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_8
	ui->screen_label_time_8 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_8, 733, 481);
	lv_obj_set_size(ui->screen_label_time_8, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_8, "1:56");
	lv_label_set_long_mode(ui->screen_label_time_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_8_main_main_default
	static lv_style_t style_screen_label_time_8_main_main_default;
	if (style_screen_label_time_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_8_main_main_default);
	else
		lv_style_init(&style_screen_label_time_8_main_main_default);
	lv_style_set_radius(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_8_main_main_default, lv_color_make(0xec, 0xdf, 0xdf));
	lv_style_set_text_font(&style_screen_label_time_8_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_8_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_8, &style_screen_label_time_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_7
	ui->screen_label_time_7 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_7, 733, 418);
	lv_obj_set_size(ui->screen_label_time_7, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_7, "3:33");
	lv_label_set_long_mode(ui->screen_label_time_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_7_main_main_default
	static lv_style_t style_screen_label_time_7_main_main_default;
	if (style_screen_label_time_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_7_main_main_default);
	else
		lv_style_init(&style_screen_label_time_7_main_main_default);
	lv_style_set_radius(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_7_main_main_default, lv_color_make(0xe7, 0xdf, 0xdf));
	lv_style_set_text_font(&style_screen_label_time_7_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_7_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_7, &style_screen_label_time_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_6
	ui->screen_label_time_6 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_6, 733, 356);
	lv_obj_set_size(ui->screen_label_time_6, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_6, "2:33");
	lv_label_set_long_mode(ui->screen_label_time_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_6_main_main_default
	static lv_style_t style_screen_label_time_6_main_main_default;
	if (style_screen_label_time_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_6_main_main_default);
	else
		lv_style_init(&style_screen_label_time_6_main_main_default);
	lv_style_set_radius(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_6_main_main_default, lv_color_make(0xef, 0xe6, 0xe6));
	lv_style_set_text_font(&style_screen_label_time_6_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_6_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_6, &style_screen_label_time_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_5
	ui->screen_label_time_5 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_5, 733, 292);
	lv_obj_set_size(ui->screen_label_time_5, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_5, "2:57");
	lv_label_set_long_mode(ui->screen_label_time_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_5_main_main_default
	static lv_style_t style_screen_label_time_5_main_main_default;
	if (style_screen_label_time_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_5_main_main_default);
	else
		lv_style_init(&style_screen_label_time_5_main_main_default);
	lv_style_set_radius(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_5_main_main_default, lv_color_make(0xf0, 0xe6, 0xe6));
	lv_style_set_text_font(&style_screen_label_time_5_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_5, &style_screen_label_time_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_4
	ui->screen_label_time_4 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_4, 733, 231);
	lv_obj_set_size(ui->screen_label_time_4, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_4, "2:24");
	lv_label_set_long_mode(ui->screen_label_time_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_4_main_main_default
	static lv_style_t style_screen_label_time_4_main_main_default;
	if (style_screen_label_time_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_4_main_main_default);
	else
		lv_style_init(&style_screen_label_time_4_main_main_default);
	lv_style_set_radius(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_4_main_main_default, lv_color_make(0xec, 0xdf, 0xdf));
	lv_style_set_text_font(&style_screen_label_time_4_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_4, &style_screen_label_time_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_3
	ui->screen_label_time_3 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_3, 733, 167);
	lv_obj_set_size(ui->screen_label_time_3, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_3, "1:54");
	lv_label_set_long_mode(ui->screen_label_time_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_3_main_main_default
	static lv_style_t style_screen_label_time_3_main_main_default;
	if (style_screen_label_time_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_3_main_main_default);
	else
		lv_style_init(&style_screen_label_time_3_main_main_default);
	lv_style_set_radius(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_3_main_main_default, lv_color_make(0xee, 0xe7, 0xe7));
	lv_style_set_text_font(&style_screen_label_time_3_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_3, &style_screen_label_time_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_2
	ui->screen_label_time_2 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_2, 733, 105);
	lv_obj_set_size(ui->screen_label_time_2, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_2, "2:26");
	lv_label_set_long_mode(ui->screen_label_time_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_2_main_main_default
	static lv_style_t style_screen_label_time_2_main_main_default;
	if (style_screen_label_time_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_2_main_main_default);
	else
		lv_style_init(&style_screen_label_time_2_main_main_default);
	lv_style_set_radius(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_2_main_main_default, lv_color_make(0xfa, 0xf9, 0xf9));
	lv_style_set_text_font(&style_screen_label_time_2_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_2, &style_screen_label_time_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_time_1
	ui->screen_label_time_1 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_time_1, 733, 42);
	lv_obj_set_size(ui->screen_label_time_1, 58, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_time_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_time_1, "1:14");
	lv_label_set_long_mode(ui->screen_label_time_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_time_1_main_main_default
	static lv_style_t style_screen_label_time_1_main_main_default;
	if (style_screen_label_time_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_time_1_main_main_default);
	else
		lv_style_init(&style_screen_label_time_1_main_main_default);
	lv_style_set_radius(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_time_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_time_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_time_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_time_1_main_main_default, lv_color_make(0xef, 0xeb, 0xeb));
	lv_style_set_text_font(&style_screen_label_time_1_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_time_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_time_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_time_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_time_1, &style_screen_label_time_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_8
	ui->screen_label_author_8 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_8, 90, 497);
	lv_obj_set_size(ui->screen_label_author_8, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_8, "Unknown artist");
	lv_label_set_long_mode(ui->screen_label_author_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_8_main_main_default
	static lv_style_t style_screen_label_author_8_main_main_default;
	if (style_screen_label_author_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_8_main_main_default);
	else
		lv_style_init(&style_screen_label_author_8_main_main_default);
	lv_style_set_radius(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_8_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_author_8_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_8_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_8, &style_screen_label_author_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_7
	ui->screen_label_author_7 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_7, 90, 435);
	lv_obj_set_size(ui->screen_label_author_7, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_7, "Robotics");
	lv_label_set_long_mode(ui->screen_label_author_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_7_main_main_default
	static lv_style_t style_screen_label_author_7_main_main_default;
	if (style_screen_label_author_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_7_main_main_default);
	else
		lv_style_init(&style_screen_label_author_7_main_main_default);
	lv_style_set_radius(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_7_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_author_7_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_7_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_7, &style_screen_label_author_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_6
	ui->screen_label_author_6 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_6, 90, 372);
	lv_obj_set_size(ui->screen_label_author_6, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_6, "Robotics");
	lv_label_set_long_mode(ui->screen_label_author_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_6_main_main_default
	static lv_style_t style_screen_label_author_6_main_main_default;
	if (style_screen_label_author_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_6_main_main_default);
	else
		lv_style_init(&style_screen_label_author_6_main_main_default);
	lv_style_set_radius(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_6_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_author_6_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_6_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_6, &style_screen_label_author_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_5
	ui->screen_label_author_5 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_5, 90, 310);
	lv_obj_set_size(ui->screen_label_author_5, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_5, "My true Name");
	lv_label_set_long_mode(ui->screen_label_author_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_5_main_main_default
	static lv_style_t style_screen_label_author_5_main_main_default;
	if (style_screen_label_author_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_5_main_main_default);
	else
		lv_style_init(&style_screen_label_author_5_main_main_default);
	lv_style_set_radius(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_5_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_author_5_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_5, &style_screen_label_author_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_4
	ui->screen_label_author_4 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_4, 90, 247);
	lv_obj_set_size(ui->screen_label_author_4, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_4, "John Smith");
	lv_label_set_long_mode(ui->screen_label_author_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_4_main_main_default
	static lv_style_t style_screen_label_author_4_main_main_default;
	if (style_screen_label_author_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_4_main_main_default);
	else
		lv_style_init(&style_screen_label_author_4_main_main_default);
	lv_style_set_radius(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_4_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_author_4_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_4, &style_screen_label_author_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_3
	ui->screen_label_author_3 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_3, 90, 185);
	lv_obj_set_size(ui->screen_label_author_3, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_3, "Robortics");
	lv_label_set_long_mode(ui->screen_label_author_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_3_main_main_default
	static lv_style_t style_screen_label_author_3_main_main_default;
	if (style_screen_label_author_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_3_main_main_default);
	else
		lv_style_init(&style_screen_label_author_3_main_main_default);
	lv_style_set_radius(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_3_main_main_default, lv_color_make(0xb3, 0xa8, 0xa8));
	lv_style_set_text_font(&style_screen_label_author_3_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_3, &style_screen_label_author_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_author_2
	ui->screen_label_author_2 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_2, 90, 121);
	lv_obj_set_size(ui->screen_label_author_2, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_2, "My true Name");
	lv_label_set_long_mode(ui->screen_label_author_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_2_main_main_default
	static lv_style_t style_screen_label_author_2_main_main_default;
	if (style_screen_label_author_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_2_main_main_default);
	else
		lv_style_init(&style_screen_label_author_2_main_main_default);
	lv_style_set_radius(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_2_main_main_default, lv_color_make(0xb3, 0xa8, 0xa8));
	lv_style_set_text_font(&style_screen_label_author_2_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_2, &style_screen_label_author_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_8
	ui->screen_label_music_8 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_8, 90, 471);
	lv_obj_set_size(ui->screen_label_music_8, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_8, "Go Deeper");
	lv_label_set_long_mode(ui->screen_label_music_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_8_main_main_default
	static lv_style_t style_screen_label_music_8_main_main_default;
	if (style_screen_label_music_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_8_main_main_default);
	else
		lv_style_init(&style_screen_label_music_8_main_main_default);
	lv_style_set_radius(&style_screen_label_music_8_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_8_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_8_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_music_8_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_music_8_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_8_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_8_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_8_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_8, &style_screen_label_music_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_7
	ui->screen_label_music_7 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_7, 90, 407);
	lv_obj_set_size(ui->screen_label_music_7, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_7, "Feeling so High");
	lv_label_set_long_mode(ui->screen_label_music_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_7_main_main_default
	static lv_style_t style_screen_label_music_7_main_main_default;
	if (style_screen_label_music_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_7_main_main_default);
	else
		lv_style_init(&style_screen_label_music_7_main_main_default);
	lv_style_set_radius(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_7_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_music_7_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_7_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_7, &style_screen_label_music_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_6
	ui->screen_label_music_6 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_6, 90, 345);
	lv_obj_set_size(ui->screen_label_music_6, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_6, "It happened Yesterday");
	lv_label_set_long_mode(ui->screen_label_music_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_6_main_main_default
	static lv_style_t style_screen_label_music_6_main_main_default;
	if (style_screen_label_music_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_6_main_main_default);
	else
		lv_style_init(&style_screen_label_music_6_main_main_default);
	lv_style_set_radius(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_6_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_music_6_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_6_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_6, &style_screen_label_music_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_5
	ui->screen_label_music_5 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_5, 90, 282);
	lv_obj_set_size(ui->screen_label_music_5, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_5, "Never Look Back");
	lv_label_set_long_mode(ui->screen_label_music_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_5_main_main_default
	static lv_style_t style_screen_label_music_5_main_main_default;
	if (style_screen_label_music_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_5_main_main_default);
	else
		lv_style_init(&style_screen_label_music_5_main_main_default);
	lv_style_set_radius(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_5_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_music_5_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_5, &style_screen_label_music_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_4
	ui->screen_label_music_4 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_4, 90, 220);
	lv_obj_set_size(ui->screen_label_music_4, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_4, "Why now");
	lv_label_set_long_mode(ui->screen_label_music_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_4_main_main_default
	static lv_style_t style_screen_label_music_4_main_main_default;
	if (style_screen_label_music_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_4_main_main_default);
	else
		lv_style_init(&style_screen_label_music_4_main_main_default);
	lv_style_set_radius(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_4_main_main_default, lv_color_make(0xa2, 0x90, 0x90));
	lv_style_set_text_font(&style_screen_label_music_4_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_4, &style_screen_label_music_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_3
	ui->screen_label_music_3 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_3, 90, 157);
	lv_obj_set_size(ui->screen_label_music_3, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_3, "Vibrations");
	lv_label_set_long_mode(ui->screen_label_music_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_3_main_main_default
	static lv_style_t style_screen_label_music_3_main_main_default;
	if (style_screen_label_music_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_3_main_main_default);
	else
		lv_style_init(&style_screen_label_music_3_main_main_default);
	lv_style_set_radius(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_3_main_main_default, lv_color_make(0xf3, 0xdd, 0xdd));
	lv_style_set_text_font(&style_screen_label_music_3_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_3, &style_screen_label_music_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_2
	ui->screen_label_music_2 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_2, 90, 95);
	lv_obj_set_size(ui->screen_label_music_2, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_2, "Need a Better Future");
	lv_label_set_long_mode(ui->screen_label_music_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_2_main_main_default
	static lv_style_t style_screen_label_music_2_main_main_default;
	if (style_screen_label_music_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_2_main_main_default);
	else
		lv_style_init(&style_screen_label_music_2_main_main_default);
	lv_style_set_radius(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_2_main_main_default, lv_color_make(0xf3, 0xdd, 0xdd));
	lv_style_set_text_font(&style_screen_label_music_2_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_2, &style_screen_label_music_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_8
	ui->screen_img_8 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_8, 0, 453);
	lv_obj_set_size(ui->screen_img_8, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_8_main_main_default
	static lv_style_t style_screen_img_8_main_main_default;
	if (style_screen_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_8_main_main_default);
	else
		lv_style_init(&style_screen_img_8_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_8_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_8, &style_screen_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_8,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_8, 0,0);
	lv_img_set_angle(ui->screen_img_8, 0);

	//Write codes screen_img_7
	ui->screen_img_7 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_7, 0, 390);
	lv_obj_set_size(ui->screen_img_7, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_7_main_main_default
	static lv_style_t style_screen_img_7_main_main_default;
	if (style_screen_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_7_main_main_default);
	else
		lv_style_init(&style_screen_img_7_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_7_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_7, &style_screen_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_7,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_7, 0,0);
	lv_img_set_angle(ui->screen_img_7, 0);

	//Write codes screen_img_6
	ui->screen_img_6 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_6, 0, 328);
	lv_obj_set_size(ui->screen_img_6, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_6_main_main_default
	static lv_style_t style_screen_img_6_main_main_default;
	if (style_screen_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_6_main_main_default);
	else
		lv_style_init(&style_screen_img_6_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_6_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_6, &style_screen_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_6,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_6, 0,0);
	lv_img_set_angle(ui->screen_img_6, 0);

	//Write codes screen_img_5
	ui->screen_img_5 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_5, 0, 264);
	lv_obj_set_size(ui->screen_img_5, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_5_main_main_default
	static lv_style_t style_screen_img_5_main_main_default;
	if (style_screen_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_5_main_main_default);
	else
		lv_style_init(&style_screen_img_5_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_5_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_5, &style_screen_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_5,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_5, 0,0);
	lv_img_set_angle(ui->screen_img_5, 0);

	//Write codes screen_img_4
	ui->screen_img_4 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_4, 0, 202);
	lv_obj_set_size(ui->screen_img_4, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_4_main_main_default
	static lv_style_t style_screen_img_4_main_main_default;
	if (style_screen_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_4_main_main_default);
	else
		lv_style_init(&style_screen_img_4_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_4_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_4, &style_screen_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_4,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_4, 0,0);
	lv_img_set_angle(ui->screen_img_4, 0);

	//Write codes screen_img_3
	ui->screen_img_3 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_3, 0, 139);
	lv_obj_set_size(ui->screen_img_3, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_3_main_main_default
	static lv_style_t style_screen_img_3_main_main_default;
	if (style_screen_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_3_main_main_default);
	else
		lv_style_init(&style_screen_img_3_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_3_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_3, &style_screen_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_3,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_3, 0,0);
	lv_img_set_angle(ui->screen_img_3, 0);

	//Write codes screen_img_2
	ui->screen_img_2 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_2, 0, 77);
	lv_obj_set_size(ui->screen_img_2, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_2_main_main_default
	static lv_style_t style_screen_img_2_main_main_default;
	if (style_screen_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_2_main_main_default);
	else
		lv_style_init(&style_screen_img_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_2_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_2, &style_screen_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_2,&_btn_list_play_70x70);
	lv_img_set_pivot(ui->screen_img_2, 0,0);
	lv_img_set_angle(ui->screen_img_2, 0);

	//Write codes screen_label_author_1
	ui->screen_label_author_1 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_author_1, 90, 60);
	lv_obj_set_size(ui->screen_label_author_1, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_author_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_author_1, "The John Smith Band");
	lv_label_set_long_mode(ui->screen_label_author_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_author_1_main_main_default
	static lv_style_t style_screen_label_author_1_main_main_default;
	if (style_screen_label_author_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_author_1_main_main_default);
	else
		lv_style_init(&style_screen_label_author_1_main_main_default);
	lv_style_set_radius(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_author_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_author_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_author_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_author_1_main_main_default, lv_color_make(0xb3, 0xa8, 0xa8));
	lv_style_set_text_font(&style_screen_label_author_1_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_author_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_author_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_author_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_author_1, &style_screen_label_author_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_music_1
	ui->screen_label_music_1 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_music_1, 90, 31);
	lv_obj_set_size(ui->screen_label_music_1, 200, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_music_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_music_1, "Waiting for true love");
	lv_label_set_long_mode(ui->screen_label_music_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_music_1_main_main_default
	static lv_style_t style_screen_label_music_1_main_main_default;
	if (style_screen_label_music_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_music_1_main_main_default);
	else
		lv_style_init(&style_screen_label_music_1_main_main_default);
	lv_style_set_radius(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_music_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_music_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_music_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_music_1_main_main_default, lv_color_make(0xf3, 0xdd, 0xdd));
	lv_style_set_text_font(&style_screen_label_music_1_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_music_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_music_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_music_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_music_1, &style_screen_label_music_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_8
	ui->screen_btn_8 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_8, 0, 458);
	lv_obj_set_size(ui->screen_btn_8, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_8_main_main_default
	static lv_style_t style_screen_btn_8_main_main_default;
	if (style_screen_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_8_main_main_default);
	else
		lv_style_init(&style_screen_btn_8_main_main_default);
	lv_style_set_radius(&style_screen_btn_8_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_8_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_8, &style_screen_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_8_label = lv_label_create(ui->screen_btn_8);
	lv_label_set_text(ui->screen_btn_8_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_7
	ui->screen_btn_7 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_7, 0, 395);
	lv_obj_set_size(ui->screen_btn_7, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_7_main_main_default
	static lv_style_t style_screen_btn_7_main_main_default;
	if (style_screen_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_7_main_main_default);
	else
		lv_style_init(&style_screen_btn_7_main_main_default);
	lv_style_set_radius(&style_screen_btn_7_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_7_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_7, &style_screen_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_7_label = lv_label_create(ui->screen_btn_7);
	lv_label_set_text(ui->screen_btn_7_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_6
	ui->screen_btn_6 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_6, 0, 333);
	lv_obj_set_size(ui->screen_btn_6, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_6_main_main_default
	static lv_style_t style_screen_btn_6_main_main_default;
	if (style_screen_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_6_main_main_default);
	else
		lv_style_init(&style_screen_btn_6_main_main_default);
	lv_style_set_radius(&style_screen_btn_6_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_6_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_6, &style_screen_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_6_label = lv_label_create(ui->screen_btn_6);
	lv_label_set_text(ui->screen_btn_6_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_5
	ui->screen_btn_5 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_5, 0, 270);
	lv_obj_set_size(ui->screen_btn_5, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_5_main_main_default
	static lv_style_t style_screen_btn_5_main_main_default;
	if (style_screen_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_5_main_main_default);
	else
		lv_style_init(&style_screen_btn_5_main_main_default);
	lv_style_set_radius(&style_screen_btn_5_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_5_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_5, &style_screen_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_5_label = lv_label_create(ui->screen_btn_5);
	lv_label_set_text(ui->screen_btn_5_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_4
	ui->screen_btn_4 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_4, 0, 208);
	lv_obj_set_size(ui->screen_btn_4, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_4_main_main_default
	static lv_style_t style_screen_btn_4_main_main_default;
	if (style_screen_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_4_main_main_default);
	else
		lv_style_init(&style_screen_btn_4_main_main_default);
	lv_style_set_radius(&style_screen_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_btn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_4, &style_screen_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_4_label = lv_label_create(ui->screen_btn_4);
	lv_label_set_text(ui->screen_btn_4_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_3
	ui->screen_btn_3 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_3, 0, 144);
	lv_obj_set_size(ui->screen_btn_3, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_3_main_main_default
	static lv_style_t style_screen_btn_3_main_main_default;
	if (style_screen_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_3_main_main_default);
	else
		lv_style_init(&style_screen_btn_3_main_main_default);
	lv_style_set_radius(&style_screen_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_btn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_3, &style_screen_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_3_label = lv_label_create(ui->screen_btn_3);
	lv_label_set_text(ui->screen_btn_3_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_2
	ui->screen_btn_2 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_2, 0, 82);
	lv_obj_set_size(ui->screen_btn_2, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_2_main_main_default
	static lv_style_t style_screen_btn_2_main_main_default;
	if (style_screen_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_2_main_main_default);
	else
		lv_style_init(&style_screen_btn_2_main_main_default);
	lv_style_set_radius(&style_screen_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_btn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_2, &style_screen_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_2_label = lv_label_create(ui->screen_btn_2);
	lv_label_set_text(ui->screen_btn_2_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_btn_1
	ui->screen_btn_1 = lv_btn_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_btn_1, 0, 19);
	lv_obj_set_size(ui->screen_btn_1, 790, 61);
	lv_obj_set_scrollbar_mode(ui->screen_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_1_main_main_default
	static lv_style_t style_screen_btn_1_main_main_default;
	if (style_screen_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_1_main_main_default);
	else
		lv_style_init(&style_screen_btn_1_main_main_default);
	lv_style_set_radius(&style_screen_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_1_main_main_default, lv_color_make(0x67, 0x70, 0x79));
	lv_style_set_border_width(&style_screen_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_screen_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_1, &style_screen_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
	lv_label_set_text(ui->screen_btn_1_label, "");
	lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_img_1, 0, 14);
	lv_obj_set_size(ui->screen_img_1, 70, 70);
	lv_obj_set_scrollbar_mode(ui->screen_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_1_main_main_default
	static lv_style_t style_screen_img_1_main_main_default;
	if (style_screen_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_1_main_main_default);
	else
		lv_style_init(&style_screen_img_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_1, &style_screen_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1,&_btn_list_pause_70x70);
	lv_img_set_pivot(ui->screen_img_1, 0,0);
	lv_img_set_angle(ui->screen_img_1, 0);

	//Write codes screen_player
	ui->screen_player = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_player, 0, 0);
	lv_obj_set_size(ui->screen_player, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen_player, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_player_main_main_default
	static lv_style_t style_screen_player_main_main_default;
	if (style_screen_player_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_player_main_main_default);
	else
		lv_style_init(&style_screen_player_main_main_default);
	lv_style_set_radius(&style_screen_player_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_player_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_player_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_player_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_player_main_main_default, 255);
	lv_style_set_border_color(&style_screen_player_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_player_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_player_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_player_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_player_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_player_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_player_main_main_default, 0);
	lv_obj_add_style(ui->screen_player, &style_screen_player_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_album
	ui->screen_img_album = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_album, 311, 148);
	lv_obj_set_size(ui->screen_img_album, 175, 175);
	lv_obj_set_scrollbar_mode(ui->screen_img_album, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_album_main_main_default
	static lv_style_t style_screen_img_album_main_main_default;
	if (style_screen_img_album_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_album_main_main_default);
	else
		lv_style_init(&style_screen_img_album_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_album_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_album_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_album_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_album, &style_screen_img_album_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_album, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_album,&_cover_1_175x175);
	lv_img_set_pivot(ui->screen_img_album, 0,0);
	lv_img_set_angle(ui->screen_img_album, 0);

	//Write codes screen_imgbtn_play
	ui->screen_imgbtn_play = lv_imgbtn_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_imgbtn_play, 360, 351);
	lv_obj_set_size(ui->screen_imgbtn_play, 80, 84);
	lv_obj_set_scrollbar_mode(ui->screen_imgbtn_play, LV_SCROLLBAR_MODE_OFF);
	lv_imgbtn_set_src(ui->screen_imgbtn_play, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_play_alpha_80x84, NULL);
	lv_imgbtn_set_src(ui->screen_imgbtn_play, LV_IMGBTN_STATE_PRESSED, NULL, &_btn_play_alpha_80x84, NULL);
	lv_imgbtn_set_src(ui->screen_imgbtn_play, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn_pause_alpha_80x84, NULL);
	lv_imgbtn_set_src(ui->screen_imgbtn_play, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn_pause_alpha_80x84, NULL);
	lv_obj_add_flag(ui->screen_imgbtn_play, LV_OBJ_FLAG_CHECKABLE);

	//Write codes screen_img_9
	ui->screen_img_9 = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_9, 311, 148);
	lv_obj_set_size(ui->screen_img_9, 175, 175);
	lv_obj_set_scrollbar_mode(ui->screen_img_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_9_main_main_default
	static lv_style_t style_screen_img_9_main_main_default;
	if (style_screen_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_9_main_main_default);
	else
		lv_style_init(&style_screen_img_9_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_9_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_9, &style_screen_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_9,&_cover_2_175x175);
	lv_img_set_pivot(ui->screen_img_9, 0,0);
	lv_img_set_angle(ui->screen_img_9, 0);

	//Write codes screen_img_10
	ui->screen_img_10 = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_10, 311, 148);
	lv_obj_set_size(ui->screen_img_10, 175, 175);
	lv_obj_set_scrollbar_mode(ui->screen_img_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_10_main_main_default
	static lv_style_t style_screen_img_10_main_main_default;
	if (style_screen_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_10_main_main_default);
	else
		lv_style_init(&style_screen_img_10_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_10_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_10, &style_screen_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_10,&_cover_3_175x175);
	lv_img_set_pivot(ui->screen_img_10, 0,0);
	lv_img_set_angle(ui->screen_img_10, 0);

	//Write codes screen_img_wave_bottom
	ui->screen_img_wave_bottom = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_wave_bottom, 0, 428);
	lv_obj_set_size(ui->screen_img_wave_bottom, 800, 51);
	lv_obj_set_scrollbar_mode(ui->screen_img_wave_bottom, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_wave_bottom_main_main_default
	static lv_style_t style_screen_img_wave_bottom_main_main_default;
	if (style_screen_img_wave_bottom_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_wave_bottom_main_main_default);
	else
		lv_style_init(&style_screen_img_wave_bottom_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_wave_bottom_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_wave_bottom_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_wave_bottom_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_wave_bottom, &style_screen_img_wave_bottom_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_wave_bottom, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_wave_bottom,&_wave_bottom_800x51);
	lv_img_set_pivot(ui->screen_img_wave_bottom, 0,0);
	lv_img_set_angle(ui->screen_img_wave_bottom, 0);

	//Write codes screen_img_wave_top
	ui->screen_img_wave_top = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_wave_top, 0, 0);
	lv_obj_set_size(ui->screen_img_wave_top, 800, 51);
	lv_obj_set_scrollbar_mode(ui->screen_img_wave_top, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_wave_top_main_main_default
	static lv_style_t style_screen_img_wave_top_main_main_default;
	if (style_screen_img_wave_top_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_wave_top_main_main_default);
	else
		lv_style_init(&style_screen_img_wave_top_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_wave_top_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_wave_top_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_wave_top_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_wave_top, &style_screen_img_wave_top_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_wave_top, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_wave_top,&_wave_top_800x51);
	lv_img_set_pivot(ui->screen_img_wave_top, 0,0);
	lv_img_set_angle(ui->screen_img_wave_top, 0);

	//Write codes screen_img_icn_rnd
	ui->screen_img_icn_rnd = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_rnd, 70, 384);
	lv_obj_set_size(ui->screen_img_icn_rnd, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_rnd, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_img_icn_rnd, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_rnd,&_btn_rnd_25x25);
	lv_img_set_pivot(ui->screen_img_icn_rnd, 0,0);
	lv_img_set_angle(ui->screen_img_icn_rnd, 0);

	//Write codes screen_img_icn_loop
	ui->screen_img_icn_loop = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_loop, 701, 384);
	lv_obj_set_size(ui->screen_img_icn_loop, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_loop, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_img_icn_loop, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_loop,&_btn_loop_25x25);
	lv_img_set_pivot(ui->screen_img_icn_loop, 0,0);
	lv_img_set_angle(ui->screen_img_icn_loop, 0);

	//Write codes screen_img_icn_left
	ui->screen_img_icn_left = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_left, 203, 360);
	lv_obj_set_size(ui->screen_img_icn_left, 61, 61);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_left, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_img_icn_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_left,&_btn_prev_61x61);
	lv_img_set_pivot(ui->screen_img_icn_left, 0,0);
	lv_img_set_angle(ui->screen_img_icn_left, 0);

	//Write codes screen_img_icn_right
	ui->screen_img_icn_right = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_right, 530, 360);
	lv_obj_set_size(ui->screen_img_icn_right, 61, 61);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_right, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_img_icn_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_right,&_btn_next_61x61);
	lv_img_set_pivot(ui->screen_img_icn_right, 0,0);
	lv_img_set_angle(ui->screen_img_icn_right, 0);

	//Write codes screen_slider_1
	ui->screen_slider_1 = lv_slider_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_slider_1, 70, 441);
	lv_obj_set_size(ui->screen_slider_1, 570, 1);
	lv_obj_set_scrollbar_mode(ui->screen_slider_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_slider_1_main_main_default
	static lv_style_t style_screen_slider_1_main_main_default;
	if (style_screen_slider_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_slider_1_main_main_default);
	else
		lv_style_init(&style_screen_slider_1_main_main_default);
	lv_style_set_radius(&style_screen_slider_1_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_slider_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_slider_1_main_main_default, 100);
	lv_style_set_outline_color(&style_screen_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_screen_slider_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_screen_slider_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_slider_1, &style_screen_slider_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_slider_1_main_indicator_default
	static lv_style_t style_screen_slider_1_main_indicator_default;
	if (style_screen_slider_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_screen_slider_1_main_indicator_default);
	else
		lv_style_init(&style_screen_slider_1_main_indicator_default);
	lv_style_set_radius(&style_screen_slider_1_main_indicator_default, 50);
	lv_style_set_bg_color(&style_screen_slider_1_main_indicator_default, lv_color_make(0x56, 0x91, 0xf8));
	lv_style_set_bg_grad_color(&style_screen_slider_1_main_indicator_default, lv_color_make(0xa6, 0x66, 0xf1));
	lv_style_set_bg_grad_dir(&style_screen_slider_1_main_indicator_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_screen_slider_1_main_indicator_default, 255);
	lv_obj_add_style(ui->screen_slider_1, &style_screen_slider_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_slider_1_main_knob_default
	static lv_style_t style_screen_slider_1_main_knob_default;
	if (style_screen_slider_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_slider_1_main_knob_default);
	else
		lv_style_init(&style_screen_slider_1_main_knob_default);
	lv_style_set_radius(&style_screen_slider_1_main_knob_default, 50);
	lv_style_set_bg_color(&style_screen_slider_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_slider_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_slider_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_slider_1_main_knob_default, 0);
	lv_obj_add_style(ui->screen_slider_1, &style_screen_slider_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->screen_slider_1,0, 100);
	lv_slider_set_value(ui->screen_slider_1,0,false);

	//Write codes screen_img_icn_msg
	ui->screen_img_icn_msg = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_msg, 635, 72);
	lv_obj_set_size(ui->screen_img_icn_msg, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_msg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_icn_msg_main_main_default
	static lv_style_t style_screen_img_icn_msg_main_main_default;
	if (style_screen_img_icn_msg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_icn_msg_main_main_default);
	else
		lv_style_init(&style_screen_img_icn_msg_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_icn_msg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_icn_msg_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_icn_msg_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_icn_msg, &style_screen_img_icn_msg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_icn_msg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_msg,&_icn_chat_25x25);
	lv_img_set_pivot(ui->screen_img_icn_msg, 0,0);
	lv_img_set_angle(ui->screen_img_icn_msg, 0);

	//Write codes screen_img_icn_heart
	ui->screen_img_icn_heart = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_heart, 140, 72);
	lv_obj_set_size(ui->screen_img_icn_heart, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_heart, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_icn_heart_main_main_default
	static lv_style_t style_screen_img_icn_heart_main_main_default;
	if (style_screen_img_icn_heart_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_icn_heart_main_main_default);
	else
		lv_style_init(&style_screen_img_icn_heart_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_icn_heart_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_icn_heart_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_icn_heart_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_icn_heart, &style_screen_img_icn_heart_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_icn_heart, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_heart,&_icn_heart_25x25);
	lv_img_set_pivot(ui->screen_img_icn_heart, 0,0);
	lv_img_set_angle(ui->screen_img_icn_heart, 0);

	//Write codes screen_img_icn_donwload
	ui->screen_img_icn_donwload = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_donwload, 470, 72);
	lv_obj_set_size(ui->screen_img_icn_donwload, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_donwload, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_icn_donwload_main_main_default
	static lv_style_t style_screen_img_icn_donwload_main_main_default;
	if (style_screen_img_icn_donwload_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_icn_donwload_main_main_default);
	else
		lv_style_init(&style_screen_img_icn_donwload_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_icn_donwload_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_icn_donwload_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_icn_donwload_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_icn_donwload, &style_screen_img_icn_donwload_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_icn_donwload, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_donwload,&_icn_download_25x25);
	lv_img_set_pivot(ui->screen_img_icn_donwload, 0,0);
	lv_img_set_angle(ui->screen_img_icn_donwload, 0);

	//Write codes screen_img_icn_chart
	ui->screen_img_icn_chart = lv_img_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_img_icn_chart, 305, 72);
	lv_obj_set_size(ui->screen_img_icn_chart, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_img_icn_chart, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_icn_chart_main_main_default
	static lv_style_t style_screen_img_icn_chart_main_main_default;
	if (style_screen_img_icn_chart_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_icn_chart_main_main_default);
	else
		lv_style_init(&style_screen_img_icn_chart_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_icn_chart_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_icn_chart_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_icn_chart_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_icn_chart, &style_screen_img_icn_chart_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_icn_chart, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_icn_chart,&_icn_chart_25x25);
	lv_img_set_pivot(ui->screen_img_icn_chart, 0,0);
	lv_img_set_angle(ui->screen_img_icn_chart, 0);

	//Write codes screen_label_slider_time
	ui->screen_label_slider_time = lv_label_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_label_slider_time, 700, 432);
	lv_obj_set_size(ui->screen_label_slider_time, 60, 19);
	lv_obj_set_scrollbar_mode(ui->screen_label_slider_time, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_slider_time, "0:00");
	lv_label_set_long_mode(ui->screen_label_slider_time, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_slider_time_main_main_default
	static lv_style_t style_screen_label_slider_time_main_main_default;
	if (style_screen_label_slider_time_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_slider_time_main_main_default);
	else
		lv_style_init(&style_screen_label_slider_time_main_main_default);
	lv_style_set_radius(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_slider_time_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_slider_time_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_slider_time_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_slider_time_main_main_default, lv_color_make(0x8a, 0x86, 0xb8));
	lv_style_set_text_font(&style_screen_label_slider_time_main_main_default, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_slider_time_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_slider_time_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_slider_time_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_slider_time, &style_screen_label_slider_time_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_tracks
	ui->screen_label_tracks = lv_label_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_label_tracks, 390, 476);
	lv_obj_set_size(ui->screen_label_tracks, 20, 1);
	lv_obj_set_scrollbar_mode(ui->screen_label_tracks, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_tracks, "");
	lv_label_set_long_mode(ui->screen_label_tracks, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_tracks_main_main_default
	static lv_style_t style_screen_label_tracks_main_main_default;
	if (style_screen_label_tracks_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_tracks_main_main_default);
	else
		lv_style_init(&style_screen_label_tracks_main_main_default);
	lv_style_set_radius(&style_screen_label_tracks_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_tracks_main_main_default, lv_color_make(0x8a, 0x86, 0xb8));
	lv_style_set_bg_grad_color(&style_screen_label_tracks_main_main_default, lv_color_make(0x8a, 0x86, 0xb8));
	lv_style_set_bg_grad_dir(&style_screen_label_tracks_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_tracks_main_main_default, 229);
	lv_style_set_text_color(&style_screen_label_tracks_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_screen_label_tracks_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_tracks_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_tracks_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_tracks_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_tracks_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_tracks_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_tracks_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_tracks, &style_screen_label_tracks_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_tracks
	ui->screen_btn_tracks = lv_btn_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_btn_tracks, 350, 451);
	lv_obj_set_size(ui->screen_btn_tracks, 100, 28);
	lv_obj_set_scrollbar_mode(ui->screen_btn_tracks, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_tracks_main_main_default
	static lv_style_t style_screen_btn_tracks_main_main_default;
	if (style_screen_btn_tracks_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_tracks_main_main_default);
	else
		lv_style_init(&style_screen_btn_tracks_main_main_default);
	lv_style_set_radius(&style_screen_btn_tracks_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_tracks_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_tracks_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_tracks_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_tracks_main_main_default, 0);
	lv_style_set_border_color(&style_screen_btn_tracks_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_tracks_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_tracks_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_tracks_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_btn_tracks_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_screen_btn_tracks_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_tracks, &style_screen_btn_tracks_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_btn_tracks_label = lv_label_create(ui->screen_btn_tracks);
	lv_label_set_text(ui->screen_btn_tracks_label, "ALL TRACK");
	lv_obj_set_style_pad_all(ui->screen_btn_tracks, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_tracks_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_label_title_music
	ui->screen_label_title_music = lv_label_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_label_title_music, 250, 8);
	lv_obj_set_size(ui->screen_label_title_music, 300, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_title_music, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_title_music, "Waiting for true love");
	lv_label_set_long_mode(ui->screen_label_title_music, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_title_music_main_main_default
	static lv_style_t style_screen_label_title_music_main_main_default;
	if (style_screen_label_title_music_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_title_music_main_main_default);
	else
		lv_style_init(&style_screen_label_title_music_main_main_default);
	lv_style_set_radius(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_title_music_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_title_music_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_title_music_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_title_music_main_main_default, lv_color_make(0x50, 0x4d, 0x6d));
	lv_style_set_text_font(&style_screen_label_title_music_main_main_default, &lv_font_arial_23);
	lv_style_set_text_letter_space(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_title_music_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_title_music_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_title_music_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_title_music, &style_screen_label_title_music_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_title_author
	ui->screen_label_title_author = lv_label_create(ui->screen_player);
	lv_obj_set_pos(ui->screen_label_title_author, 250, 38);
	lv_obj_set_size(ui->screen_label_title_author, 300, 31);
	lv_obj_set_scrollbar_mode(ui->screen_label_title_author, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_title_author, "The John Smith Band");
	lv_label_set_long_mode(ui->screen_label_title_author, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_title_author_main_main_default
	static lv_style_t style_screen_label_title_author_main_main_default;
	if (style_screen_label_title_author_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_title_author_main_main_default);
	else
		lv_style_init(&style_screen_label_title_author_main_main_default);
	lv_style_set_radius(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_title_author_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_title_author_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_title_author_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_title_author_main_main_default, lv_color_make(0x50, 0x4d, 0x6d));
	lv_style_set_text_font(&style_screen_label_title_author_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_text_line_space(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_title_author_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_title_author_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label_title_author_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_title_author, &style_screen_label_title_author_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_screen(ui);
}