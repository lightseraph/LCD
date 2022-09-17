# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=800,h=480)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(800*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 800
disp_drv.ver_res = 480
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


screen = lv.obj()
screen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_main_main_default
style_screen_main_main_default = lv.style_t()
style_screen_main_main_default.init()
style_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_main_main_default.set_bg_opa(0)

# add style for screen
screen.add_style(style_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_11 = lv.img(screen)
screen_img_11.set_pos(int(391),int(229))
screen_img_11.set_size(25,25)
screen_img_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1559258741.png','rb') as f:
        screen_img_11_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1559258741.png')
    sys.exit()

screen_img_11_img = lv.img_dsc_t({
  'data_size': len(screen_img_11_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR},
  'data': screen_img_11_img_data
})

screen_img_11.set_src(screen_img_11_img)
screen_img_11.set_pivot(0,0)
screen_img_11.set_angle(0)
# create style style_screen_img_11_main_main_default
style_screen_img_11_main_main_default = lv.style_t()
style_screen_img_11_main_main_default.init()
style_screen_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_11_main_main_default.set_img_recolor_opa(0)
style_screen_img_11_main_main_default.set_img_opa(255)

# add style for screen_img_11
screen_img_11.add_style(style_screen_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_cont_1 = lv.obj(screen)
screen_cont_1.set_pos(int(0),int(19))
screen_cont_1.set_size(800,460)
screen_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_8 = lv.label(screen_cont_1)
screen_label_time_8.set_pos(int(733),int(481))
screen_label_time_8.set_size(58,31)
screen_label_time_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_8.set_text("1:56")
screen_label_time_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_8_main_main_default
style_screen_label_time_8_main_main_default = lv.style_t()
style_screen_label_time_8_main_main_default.init()
style_screen_label_time_8_main_main_default.set_radius(0)
style_screen_label_time_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_8_main_main_default.set_bg_opa(0)
style_screen_label_time_8_main_main_default.set_text_color(lv.color_make(0xec,0xdf,0xdf))
try:
    style_screen_label_time_8_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_8_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_8_main_main_default.set_text_letter_space(0)
style_screen_label_time_8_main_main_default.set_text_line_space(0)
style_screen_label_time_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_8_main_main_default.set_pad_left(0)
style_screen_label_time_8_main_main_default.set_pad_right(0)
style_screen_label_time_8_main_main_default.set_pad_top(0)
style_screen_label_time_8_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_8
screen_label_time_8.add_style(style_screen_label_time_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_7 = lv.label(screen_cont_1)
screen_label_time_7.set_pos(int(733),int(418))
screen_label_time_7.set_size(58,31)
screen_label_time_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_7.set_text("3:33")
screen_label_time_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_7_main_main_default
style_screen_label_time_7_main_main_default = lv.style_t()
style_screen_label_time_7_main_main_default.init()
style_screen_label_time_7_main_main_default.set_radius(0)
style_screen_label_time_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_7_main_main_default.set_bg_opa(0)
style_screen_label_time_7_main_main_default.set_text_color(lv.color_make(0xe7,0xdf,0xdf))
try:
    style_screen_label_time_7_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_7_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_7_main_main_default.set_text_letter_space(0)
style_screen_label_time_7_main_main_default.set_text_line_space(0)
style_screen_label_time_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_7_main_main_default.set_pad_left(0)
style_screen_label_time_7_main_main_default.set_pad_right(0)
style_screen_label_time_7_main_main_default.set_pad_top(0)
style_screen_label_time_7_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_7
screen_label_time_7.add_style(style_screen_label_time_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_6 = lv.label(screen_cont_1)
screen_label_time_6.set_pos(int(733),int(356))
screen_label_time_6.set_size(58,31)
screen_label_time_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_6.set_text("2:33")
screen_label_time_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_6_main_main_default
style_screen_label_time_6_main_main_default = lv.style_t()
style_screen_label_time_6_main_main_default.init()
style_screen_label_time_6_main_main_default.set_radius(0)
style_screen_label_time_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_6_main_main_default.set_bg_opa(0)
style_screen_label_time_6_main_main_default.set_text_color(lv.color_make(0xef,0xe6,0xe6))
try:
    style_screen_label_time_6_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_6_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_6_main_main_default.set_text_letter_space(0)
style_screen_label_time_6_main_main_default.set_text_line_space(0)
style_screen_label_time_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_6_main_main_default.set_pad_left(0)
style_screen_label_time_6_main_main_default.set_pad_right(0)
style_screen_label_time_6_main_main_default.set_pad_top(0)
style_screen_label_time_6_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_6
screen_label_time_6.add_style(style_screen_label_time_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_5 = lv.label(screen_cont_1)
screen_label_time_5.set_pos(int(733),int(292))
screen_label_time_5.set_size(58,31)
screen_label_time_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_5.set_text("2:57")
screen_label_time_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_5_main_main_default
style_screen_label_time_5_main_main_default = lv.style_t()
style_screen_label_time_5_main_main_default.init()
style_screen_label_time_5_main_main_default.set_radius(0)
style_screen_label_time_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_5_main_main_default.set_bg_opa(0)
style_screen_label_time_5_main_main_default.set_text_color(lv.color_make(0xf0,0xe6,0xe6))
try:
    style_screen_label_time_5_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_5_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_5_main_main_default.set_text_letter_space(0)
style_screen_label_time_5_main_main_default.set_text_line_space(0)
style_screen_label_time_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_5_main_main_default.set_pad_left(0)
style_screen_label_time_5_main_main_default.set_pad_right(0)
style_screen_label_time_5_main_main_default.set_pad_top(0)
style_screen_label_time_5_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_5
screen_label_time_5.add_style(style_screen_label_time_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_4 = lv.label(screen_cont_1)
screen_label_time_4.set_pos(int(733),int(231))
screen_label_time_4.set_size(58,31)
screen_label_time_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_4.set_text("2:24")
screen_label_time_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_4_main_main_default
style_screen_label_time_4_main_main_default = lv.style_t()
style_screen_label_time_4_main_main_default.init()
style_screen_label_time_4_main_main_default.set_radius(0)
style_screen_label_time_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_4_main_main_default.set_bg_opa(0)
style_screen_label_time_4_main_main_default.set_text_color(lv.color_make(0xec,0xdf,0xdf))
try:
    style_screen_label_time_4_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_4_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_4_main_main_default.set_text_letter_space(0)
style_screen_label_time_4_main_main_default.set_text_line_space(0)
style_screen_label_time_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_4_main_main_default.set_pad_left(0)
style_screen_label_time_4_main_main_default.set_pad_right(0)
style_screen_label_time_4_main_main_default.set_pad_top(0)
style_screen_label_time_4_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_4
screen_label_time_4.add_style(style_screen_label_time_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_3 = lv.label(screen_cont_1)
screen_label_time_3.set_pos(int(733),int(167))
screen_label_time_3.set_size(58,31)
screen_label_time_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_3.set_text("1:54")
screen_label_time_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_3_main_main_default
style_screen_label_time_3_main_main_default = lv.style_t()
style_screen_label_time_3_main_main_default.init()
style_screen_label_time_3_main_main_default.set_radius(0)
style_screen_label_time_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_3_main_main_default.set_bg_opa(0)
style_screen_label_time_3_main_main_default.set_text_color(lv.color_make(0xee,0xe7,0xe7))
try:
    style_screen_label_time_3_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_3_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_3_main_main_default.set_text_letter_space(0)
style_screen_label_time_3_main_main_default.set_text_line_space(0)
style_screen_label_time_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_3_main_main_default.set_pad_left(0)
style_screen_label_time_3_main_main_default.set_pad_right(0)
style_screen_label_time_3_main_main_default.set_pad_top(0)
style_screen_label_time_3_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_3
screen_label_time_3.add_style(style_screen_label_time_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_2 = lv.label(screen_cont_1)
screen_label_time_2.set_pos(int(733),int(105))
screen_label_time_2.set_size(58,31)
screen_label_time_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_2.set_text("2:26")
screen_label_time_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_2_main_main_default
style_screen_label_time_2_main_main_default = lv.style_t()
style_screen_label_time_2_main_main_default.init()
style_screen_label_time_2_main_main_default.set_radius(0)
style_screen_label_time_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_2_main_main_default.set_bg_opa(0)
style_screen_label_time_2_main_main_default.set_text_color(lv.color_make(0xfa,0xf9,0xf9))
try:
    style_screen_label_time_2_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_2_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_2_main_main_default.set_text_letter_space(0)
style_screen_label_time_2_main_main_default.set_text_line_space(0)
style_screen_label_time_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_2_main_main_default.set_pad_left(0)
style_screen_label_time_2_main_main_default.set_pad_right(0)
style_screen_label_time_2_main_main_default.set_pad_top(0)
style_screen_label_time_2_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_2
screen_label_time_2.add_style(style_screen_label_time_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_time_1 = lv.label(screen_cont_1)
screen_label_time_1.set_pos(int(733),int(42))
screen_label_time_1.set_size(58,31)
screen_label_time_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_time_1.set_text("1:14")
screen_label_time_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_time_1_main_main_default
style_screen_label_time_1_main_main_default = lv.style_t()
style_screen_label_time_1_main_main_default.init()
style_screen_label_time_1_main_main_default.set_radius(0)
style_screen_label_time_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_time_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_time_1_main_main_default.set_bg_opa(0)
style_screen_label_time_1_main_main_default.set_text_color(lv.color_make(0xef,0xeb,0xeb))
try:
    style_screen_label_time_1_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_time_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_time_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_time_1_main_main_default.set_text_letter_space(0)
style_screen_label_time_1_main_main_default.set_text_line_space(0)
style_screen_label_time_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_time_1_main_main_default.set_pad_left(0)
style_screen_label_time_1_main_main_default.set_pad_right(0)
style_screen_label_time_1_main_main_default.set_pad_top(0)
style_screen_label_time_1_main_main_default.set_pad_bottom(0)

# add style for screen_label_time_1
screen_label_time_1.add_style(style_screen_label_time_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_8 = lv.label(screen_cont_1)
screen_label_author_8.set_pos(int(90),int(497))
screen_label_author_8.set_size(200,31)
screen_label_author_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_8.set_text("Unknown artist")
screen_label_author_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_8_main_main_default
style_screen_label_author_8_main_main_default = lv.style_t()
style_screen_label_author_8_main_main_default.init()
style_screen_label_author_8_main_main_default.set_radius(0)
style_screen_label_author_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_8_main_main_default.set_bg_opa(0)
style_screen_label_author_8_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_author_8_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_8_main_main_default.set_text_letter_space(0)
style_screen_label_author_8_main_main_default.set_text_line_space(0)
style_screen_label_author_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_8_main_main_default.set_pad_left(0)
style_screen_label_author_8_main_main_default.set_pad_right(0)
style_screen_label_author_8_main_main_default.set_pad_top(0)
style_screen_label_author_8_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_8
screen_label_author_8.add_style(style_screen_label_author_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_7 = lv.label(screen_cont_1)
screen_label_author_7.set_pos(int(90),int(435))
screen_label_author_7.set_size(200,31)
screen_label_author_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_7.set_text("Robotics")
screen_label_author_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_7_main_main_default
style_screen_label_author_7_main_main_default = lv.style_t()
style_screen_label_author_7_main_main_default.init()
style_screen_label_author_7_main_main_default.set_radius(0)
style_screen_label_author_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_7_main_main_default.set_bg_opa(0)
style_screen_label_author_7_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_author_7_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_7_main_main_default.set_text_letter_space(0)
style_screen_label_author_7_main_main_default.set_text_line_space(0)
style_screen_label_author_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_7_main_main_default.set_pad_left(0)
style_screen_label_author_7_main_main_default.set_pad_right(0)
style_screen_label_author_7_main_main_default.set_pad_top(0)
style_screen_label_author_7_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_7
screen_label_author_7.add_style(style_screen_label_author_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_6 = lv.label(screen_cont_1)
screen_label_author_6.set_pos(int(90),int(372))
screen_label_author_6.set_size(200,31)
screen_label_author_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_6.set_text("Robotics")
screen_label_author_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_6_main_main_default
style_screen_label_author_6_main_main_default = lv.style_t()
style_screen_label_author_6_main_main_default.init()
style_screen_label_author_6_main_main_default.set_radius(0)
style_screen_label_author_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_6_main_main_default.set_bg_opa(0)
style_screen_label_author_6_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_author_6_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_6_main_main_default.set_text_letter_space(0)
style_screen_label_author_6_main_main_default.set_text_line_space(0)
style_screen_label_author_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_6_main_main_default.set_pad_left(0)
style_screen_label_author_6_main_main_default.set_pad_right(0)
style_screen_label_author_6_main_main_default.set_pad_top(0)
style_screen_label_author_6_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_6
screen_label_author_6.add_style(style_screen_label_author_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_5 = lv.label(screen_cont_1)
screen_label_author_5.set_pos(int(90),int(310))
screen_label_author_5.set_size(200,31)
screen_label_author_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_5.set_text("My true Name")
screen_label_author_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_5_main_main_default
style_screen_label_author_5_main_main_default = lv.style_t()
style_screen_label_author_5_main_main_default.init()
style_screen_label_author_5_main_main_default.set_radius(0)
style_screen_label_author_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_5_main_main_default.set_bg_opa(0)
style_screen_label_author_5_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_author_5_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_5_main_main_default.set_text_letter_space(0)
style_screen_label_author_5_main_main_default.set_text_line_space(0)
style_screen_label_author_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_5_main_main_default.set_pad_left(0)
style_screen_label_author_5_main_main_default.set_pad_right(0)
style_screen_label_author_5_main_main_default.set_pad_top(0)
style_screen_label_author_5_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_5
screen_label_author_5.add_style(style_screen_label_author_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_4 = lv.label(screen_cont_1)
screen_label_author_4.set_pos(int(90),int(247))
screen_label_author_4.set_size(200,31)
screen_label_author_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_4.set_text("John Smith")
screen_label_author_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_4_main_main_default
style_screen_label_author_4_main_main_default = lv.style_t()
style_screen_label_author_4_main_main_default.init()
style_screen_label_author_4_main_main_default.set_radius(0)
style_screen_label_author_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_4_main_main_default.set_bg_opa(0)
style_screen_label_author_4_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_author_4_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_4_main_main_default.set_text_letter_space(0)
style_screen_label_author_4_main_main_default.set_text_line_space(0)
style_screen_label_author_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_4_main_main_default.set_pad_left(0)
style_screen_label_author_4_main_main_default.set_pad_right(0)
style_screen_label_author_4_main_main_default.set_pad_top(0)
style_screen_label_author_4_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_4
screen_label_author_4.add_style(style_screen_label_author_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_3 = lv.label(screen_cont_1)
screen_label_author_3.set_pos(int(90),int(185))
screen_label_author_3.set_size(200,31)
screen_label_author_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_3.set_text("Robortics")
screen_label_author_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_3_main_main_default
style_screen_label_author_3_main_main_default = lv.style_t()
style_screen_label_author_3_main_main_default.init()
style_screen_label_author_3_main_main_default.set_radius(0)
style_screen_label_author_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_3_main_main_default.set_bg_opa(0)
style_screen_label_author_3_main_main_default.set_text_color(lv.color_make(0xb3,0xa8,0xa8))
try:
    style_screen_label_author_3_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_3_main_main_default.set_text_letter_space(0)
style_screen_label_author_3_main_main_default.set_text_line_space(0)
style_screen_label_author_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_3_main_main_default.set_pad_left(0)
style_screen_label_author_3_main_main_default.set_pad_right(0)
style_screen_label_author_3_main_main_default.set_pad_top(0)
style_screen_label_author_3_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_3
screen_label_author_3.add_style(style_screen_label_author_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_2 = lv.label(screen_cont_1)
screen_label_author_2.set_pos(int(90),int(121))
screen_label_author_2.set_size(200,31)
screen_label_author_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_2.set_text("My true Name")
screen_label_author_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_2_main_main_default
style_screen_label_author_2_main_main_default = lv.style_t()
style_screen_label_author_2_main_main_default.init()
style_screen_label_author_2_main_main_default.set_radius(0)
style_screen_label_author_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_2_main_main_default.set_bg_opa(0)
style_screen_label_author_2_main_main_default.set_text_color(lv.color_make(0xb3,0xa8,0xa8))
try:
    style_screen_label_author_2_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_2_main_main_default.set_text_letter_space(0)
style_screen_label_author_2_main_main_default.set_text_line_space(0)
style_screen_label_author_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_2_main_main_default.set_pad_left(0)
style_screen_label_author_2_main_main_default.set_pad_right(0)
style_screen_label_author_2_main_main_default.set_pad_top(0)
style_screen_label_author_2_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_2
screen_label_author_2.add_style(style_screen_label_author_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_8 = lv.label(screen_cont_1)
screen_label_music_8.set_pos(int(90),int(471))
screen_label_music_8.set_size(200,31)
screen_label_music_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_8.set_text("Go Deeper")
screen_label_music_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_8_main_main_default
style_screen_label_music_8_main_main_default = lv.style_t()
style_screen_label_music_8_main_main_default.init()
style_screen_label_music_8_main_main_default.set_radius(0)
style_screen_label_music_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_8_main_main_default.set_bg_opa(0)
style_screen_label_music_8_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_music_8_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_8_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_8_main_main_default.set_text_letter_space(2)
style_screen_label_music_8_main_main_default.set_text_line_space(0)
style_screen_label_music_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_8_main_main_default.set_pad_left(0)
style_screen_label_music_8_main_main_default.set_pad_right(0)
style_screen_label_music_8_main_main_default.set_pad_top(0)
style_screen_label_music_8_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_8
screen_label_music_8.add_style(style_screen_label_music_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_7 = lv.label(screen_cont_1)
screen_label_music_7.set_pos(int(90),int(407))
screen_label_music_7.set_size(200,31)
screen_label_music_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_7.set_text("Feeling so High")
screen_label_music_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_7_main_main_default
style_screen_label_music_7_main_main_default = lv.style_t()
style_screen_label_music_7_main_main_default.init()
style_screen_label_music_7_main_main_default.set_radius(0)
style_screen_label_music_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_7_main_main_default.set_bg_opa(0)
style_screen_label_music_7_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_music_7_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_7_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_7_main_main_default.set_text_letter_space(0)
style_screen_label_music_7_main_main_default.set_text_line_space(0)
style_screen_label_music_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_7_main_main_default.set_pad_left(0)
style_screen_label_music_7_main_main_default.set_pad_right(0)
style_screen_label_music_7_main_main_default.set_pad_top(0)
style_screen_label_music_7_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_7
screen_label_music_7.add_style(style_screen_label_music_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_6 = lv.label(screen_cont_1)
screen_label_music_6.set_pos(int(90),int(345))
screen_label_music_6.set_size(200,31)
screen_label_music_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_6.set_text("It happened Yesterday")
screen_label_music_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_6_main_main_default
style_screen_label_music_6_main_main_default = lv.style_t()
style_screen_label_music_6_main_main_default.init()
style_screen_label_music_6_main_main_default.set_radius(0)
style_screen_label_music_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_6_main_main_default.set_bg_opa(0)
style_screen_label_music_6_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_music_6_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_6_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_6_main_main_default.set_text_letter_space(0)
style_screen_label_music_6_main_main_default.set_text_line_space(0)
style_screen_label_music_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_6_main_main_default.set_pad_left(0)
style_screen_label_music_6_main_main_default.set_pad_right(0)
style_screen_label_music_6_main_main_default.set_pad_top(0)
style_screen_label_music_6_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_6
screen_label_music_6.add_style(style_screen_label_music_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_5 = lv.label(screen_cont_1)
screen_label_music_5.set_pos(int(90),int(282))
screen_label_music_5.set_size(200,31)
screen_label_music_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_5.set_text("Never Look Back")
screen_label_music_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_5_main_main_default
style_screen_label_music_5_main_main_default = lv.style_t()
style_screen_label_music_5_main_main_default.init()
style_screen_label_music_5_main_main_default.set_radius(0)
style_screen_label_music_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_5_main_main_default.set_bg_opa(0)
style_screen_label_music_5_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_music_5_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_5_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_5_main_main_default.set_text_letter_space(0)
style_screen_label_music_5_main_main_default.set_text_line_space(0)
style_screen_label_music_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_5_main_main_default.set_pad_left(0)
style_screen_label_music_5_main_main_default.set_pad_right(0)
style_screen_label_music_5_main_main_default.set_pad_top(0)
style_screen_label_music_5_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_5
screen_label_music_5.add_style(style_screen_label_music_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_4 = lv.label(screen_cont_1)
screen_label_music_4.set_pos(int(90),int(220))
screen_label_music_4.set_size(200,31)
screen_label_music_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_4.set_text("Why now")
screen_label_music_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_4_main_main_default
style_screen_label_music_4_main_main_default = lv.style_t()
style_screen_label_music_4_main_main_default.init()
style_screen_label_music_4_main_main_default.set_radius(0)
style_screen_label_music_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_4_main_main_default.set_bg_opa(0)
style_screen_label_music_4_main_main_default.set_text_color(lv.color_make(0xa2,0x90,0x90))
try:
    style_screen_label_music_4_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_4_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_4_main_main_default.set_text_letter_space(0)
style_screen_label_music_4_main_main_default.set_text_line_space(0)
style_screen_label_music_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_4_main_main_default.set_pad_left(0)
style_screen_label_music_4_main_main_default.set_pad_right(0)
style_screen_label_music_4_main_main_default.set_pad_top(0)
style_screen_label_music_4_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_4
screen_label_music_4.add_style(style_screen_label_music_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_3 = lv.label(screen_cont_1)
screen_label_music_3.set_pos(int(90),int(157))
screen_label_music_3.set_size(200,31)
screen_label_music_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_3.set_text("Vibrations")
screen_label_music_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_3_main_main_default
style_screen_label_music_3_main_main_default = lv.style_t()
style_screen_label_music_3_main_main_default.init()
style_screen_label_music_3_main_main_default.set_radius(0)
style_screen_label_music_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_3_main_main_default.set_bg_opa(0)
style_screen_label_music_3_main_main_default.set_text_color(lv.color_make(0xf3,0xdd,0xdd))
try:
    style_screen_label_music_3_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_3_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_3_main_main_default.set_text_letter_space(0)
style_screen_label_music_3_main_main_default.set_text_line_space(0)
style_screen_label_music_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_3_main_main_default.set_pad_left(0)
style_screen_label_music_3_main_main_default.set_pad_right(0)
style_screen_label_music_3_main_main_default.set_pad_top(0)
style_screen_label_music_3_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_3
screen_label_music_3.add_style(style_screen_label_music_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_2 = lv.label(screen_cont_1)
screen_label_music_2.set_pos(int(90),int(95))
screen_label_music_2.set_size(200,31)
screen_label_music_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_2.set_text("Need a Better Future")
screen_label_music_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_2_main_main_default
style_screen_label_music_2_main_main_default = lv.style_t()
style_screen_label_music_2_main_main_default.init()
style_screen_label_music_2_main_main_default.set_radius(0)
style_screen_label_music_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_2_main_main_default.set_bg_opa(0)
style_screen_label_music_2_main_main_default.set_text_color(lv.color_make(0xf3,0xdd,0xdd))
try:
    style_screen_label_music_2_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_2_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_2_main_main_default.set_text_letter_space(0)
style_screen_label_music_2_main_main_default.set_text_line_space(0)
style_screen_label_music_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_2_main_main_default.set_pad_left(0)
style_screen_label_music_2_main_main_default.set_pad_right(0)
style_screen_label_music_2_main_main_default.set_pad_top(0)
style_screen_label_music_2_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_2
screen_label_music_2.add_style(style_screen_label_music_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_8 = lv.img(screen_cont_1)
screen_img_8.set_pos(int(0),int(453))
screen_img_8.set_size(70,70)
screen_img_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_8_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_8_img = lv.img_dsc_t({
  'data_size': len(screen_img_8_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_8_img_data
})

screen_img_8.set_src(screen_img_8_img)
screen_img_8.set_pivot(0,0)
screen_img_8.set_angle(0)
# create style style_screen_img_8_main_main_default
style_screen_img_8_main_main_default = lv.style_t()
style_screen_img_8_main_main_default.init()
style_screen_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_8_main_main_default.set_img_recolor_opa(0)
style_screen_img_8_main_main_default.set_img_opa(255)

# add style for screen_img_8
screen_img_8.add_style(style_screen_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_7 = lv.img(screen_cont_1)
screen_img_7.set_pos(int(0),int(390))
screen_img_7.set_size(70,70)
screen_img_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_7_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_7_img = lv.img_dsc_t({
  'data_size': len(screen_img_7_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_7_img_data
})

screen_img_7.set_src(screen_img_7_img)
screen_img_7.set_pivot(0,0)
screen_img_7.set_angle(0)
# create style style_screen_img_7_main_main_default
style_screen_img_7_main_main_default = lv.style_t()
style_screen_img_7_main_main_default.init()
style_screen_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_7_main_main_default.set_img_recolor_opa(0)
style_screen_img_7_main_main_default.set_img_opa(255)

# add style for screen_img_7
screen_img_7.add_style(style_screen_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_6 = lv.img(screen_cont_1)
screen_img_6.set_pos(int(0),int(328))
screen_img_6.set_size(70,70)
screen_img_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_6_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_6_img = lv.img_dsc_t({
  'data_size': len(screen_img_6_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_6_img_data
})

screen_img_6.set_src(screen_img_6_img)
screen_img_6.set_pivot(0,0)
screen_img_6.set_angle(0)
# create style style_screen_img_6_main_main_default
style_screen_img_6_main_main_default = lv.style_t()
style_screen_img_6_main_main_default.init()
style_screen_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_6_main_main_default.set_img_recolor_opa(0)
style_screen_img_6_main_main_default.set_img_opa(255)

# add style for screen_img_6
screen_img_6.add_style(style_screen_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_5 = lv.img(screen_cont_1)
screen_img_5.set_pos(int(0),int(264))
screen_img_5.set_size(70,70)
screen_img_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_5_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_5_img = lv.img_dsc_t({
  'data_size': len(screen_img_5_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_5_img_data
})

screen_img_5.set_src(screen_img_5_img)
screen_img_5.set_pivot(0,0)
screen_img_5.set_angle(0)
# create style style_screen_img_5_main_main_default
style_screen_img_5_main_main_default = lv.style_t()
style_screen_img_5_main_main_default.init()
style_screen_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_5_main_main_default.set_img_recolor_opa(0)
style_screen_img_5_main_main_default.set_img_opa(255)

# add style for screen_img_5
screen_img_5.add_style(style_screen_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_4 = lv.img(screen_cont_1)
screen_img_4.set_pos(int(0),int(202))
screen_img_4.set_size(70,70)
screen_img_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_4_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_4_img = lv.img_dsc_t({
  'data_size': len(screen_img_4_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_4_img_data
})

screen_img_4.set_src(screen_img_4_img)
screen_img_4.set_pivot(0,0)
screen_img_4.set_angle(0)
# create style style_screen_img_4_main_main_default
style_screen_img_4_main_main_default = lv.style_t()
style_screen_img_4_main_main_default.init()
style_screen_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_4_main_main_default.set_img_recolor_opa(0)
style_screen_img_4_main_main_default.set_img_opa(255)

# add style for screen_img_4
screen_img_4.add_style(style_screen_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_3 = lv.img(screen_cont_1)
screen_img_3.set_pos(int(0),int(139))
screen_img_3.set_size(70,70)
screen_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_3_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_3_img = lv.img_dsc_t({
  'data_size': len(screen_img_3_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_3_img_data
})

screen_img_3.set_src(screen_img_3_img)
screen_img_3.set_pivot(0,0)
screen_img_3.set_angle(0)
# create style style_screen_img_3_main_main_default
style_screen_img_3_main_main_default = lv.style_t()
style_screen_img_3_main_main_default.init()
style_screen_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_3_main_main_default.set_img_recolor_opa(0)
style_screen_img_3_main_main_default.set_img_opa(255)

# add style for screen_img_3
screen_img_3.add_style(style_screen_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_2 = lv.img(screen_cont_1)
screen_img_2.set_pos(int(0),int(77))
screen_img_2.set_size(70,70)
screen_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png','rb') as f:
        screen_img_2_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-876957126.png')
    sys.exit()

screen_img_2_img = lv.img_dsc_t({
  'data_size': len(screen_img_2_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_2_img_data
})

screen_img_2.set_src(screen_img_2_img)
screen_img_2.set_pivot(0,0)
screen_img_2.set_angle(0)
# create style style_screen_img_2_main_main_default
style_screen_img_2_main_main_default = lv.style_t()
style_screen_img_2_main_main_default.init()
style_screen_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_2_main_main_default.set_img_recolor_opa(0)
style_screen_img_2_main_main_default.set_img_opa(255)

# add style for screen_img_2
screen_img_2.add_style(style_screen_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_author_1 = lv.label(screen_cont_1)
screen_label_author_1.set_pos(int(90),int(60))
screen_label_author_1.set_size(200,31)
screen_label_author_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_author_1.set_text("The John Smith Band")
screen_label_author_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_author_1_main_main_default
style_screen_label_author_1_main_main_default = lv.style_t()
style_screen_label_author_1_main_main_default.init()
style_screen_label_author_1_main_main_default.set_radius(0)
style_screen_label_author_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_author_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_author_1_main_main_default.set_bg_opa(0)
style_screen_label_author_1_main_main_default.set_text_color(lv.color_make(0xb3,0xa8,0xa8))
try:
    style_screen_label_author_1_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_author_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_author_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_author_1_main_main_default.set_text_letter_space(0)
style_screen_label_author_1_main_main_default.set_text_line_space(0)
style_screen_label_author_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_author_1_main_main_default.set_pad_left(0)
style_screen_label_author_1_main_main_default.set_pad_right(0)
style_screen_label_author_1_main_main_default.set_pad_top(0)
style_screen_label_author_1_main_main_default.set_pad_bottom(0)

# add style for screen_label_author_1
screen_label_author_1.add_style(style_screen_label_author_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_music_1 = lv.label(screen_cont_1)
screen_label_music_1.set_pos(int(90),int(31))
screen_label_music_1.set_size(200,31)
screen_label_music_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_music_1.set_text("Waiting for true love")
screen_label_music_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_music_1_main_main_default
style_screen_label_music_1_main_main_default = lv.style_t()
style_screen_label_music_1_main_main_default.init()
style_screen_label_music_1_main_main_default.set_radius(0)
style_screen_label_music_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_music_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_music_1_main_main_default.set_bg_opa(0)
style_screen_label_music_1_main_main_default.set_text_color(lv.color_make(0xf3,0xdd,0xdd))
try:
    style_screen_label_music_1_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_music_1_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_music_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_music_1_main_main_default.set_text_letter_space(0)
style_screen_label_music_1_main_main_default.set_text_line_space(0)
style_screen_label_music_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_music_1_main_main_default.set_pad_left(0)
style_screen_label_music_1_main_main_default.set_pad_right(0)
style_screen_label_music_1_main_main_default.set_pad_top(0)
style_screen_label_music_1_main_main_default.set_pad_bottom(0)

# add style for screen_label_music_1
screen_label_music_1.add_style(style_screen_label_music_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_8 = lv.btn(screen_cont_1)
screen_btn_8.set_pos(int(0),int(458))
screen_btn_8.set_size(790,61)
screen_btn_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_8_main_main_default
style_screen_btn_8_main_main_default = lv.style_t()
style_screen_btn_8_main_main_default.init()
style_screen_btn_8_main_main_default.set_radius(5)
style_screen_btn_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_8_main_main_default.set_bg_opa(0)
style_screen_btn_8_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_8_main_main_default.set_border_width(0)
style_screen_btn_8_main_main_default.set_border_opa(255)
style_screen_btn_8_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_8_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_8_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_8
screen_btn_8.add_style(style_screen_btn_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_7 = lv.btn(screen_cont_1)
screen_btn_7.set_pos(int(0),int(395))
screen_btn_7.set_size(790,61)
screen_btn_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_7_main_main_default
style_screen_btn_7_main_main_default = lv.style_t()
style_screen_btn_7_main_main_default.init()
style_screen_btn_7_main_main_default.set_radius(5)
style_screen_btn_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_7_main_main_default.set_bg_opa(0)
style_screen_btn_7_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_7_main_main_default.set_border_width(0)
style_screen_btn_7_main_main_default.set_border_opa(255)
style_screen_btn_7_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_7_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_7_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_7
screen_btn_7.add_style(style_screen_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_6 = lv.btn(screen_cont_1)
screen_btn_6.set_pos(int(0),int(333))
screen_btn_6.set_size(790,61)
screen_btn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_6_main_main_default
style_screen_btn_6_main_main_default = lv.style_t()
style_screen_btn_6_main_main_default.init()
style_screen_btn_6_main_main_default.set_radius(5)
style_screen_btn_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_6_main_main_default.set_bg_opa(0)
style_screen_btn_6_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_6_main_main_default.set_border_width(0)
style_screen_btn_6_main_main_default.set_border_opa(255)
style_screen_btn_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_6_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_6_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_6
screen_btn_6.add_style(style_screen_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_5 = lv.btn(screen_cont_1)
screen_btn_5.set_pos(int(0),int(270))
screen_btn_5.set_size(790,61)
screen_btn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_5_main_main_default
style_screen_btn_5_main_main_default = lv.style_t()
style_screen_btn_5_main_main_default.init()
style_screen_btn_5_main_main_default.set_radius(5)
style_screen_btn_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_5_main_main_default.set_bg_opa(0)
style_screen_btn_5_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_5_main_main_default.set_border_width(0)
style_screen_btn_5_main_main_default.set_border_opa(255)
style_screen_btn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_5_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_5_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_5
screen_btn_5.add_style(style_screen_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_4 = lv.btn(screen_cont_1)
screen_btn_4.set_pos(int(0),int(208))
screen_btn_4.set_size(790,61)
screen_btn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_4_main_main_default
style_screen_btn_4_main_main_default = lv.style_t()
style_screen_btn_4_main_main_default.init()
style_screen_btn_4_main_main_default.set_radius(5)
style_screen_btn_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_4_main_main_default.set_bg_opa(0)
style_screen_btn_4_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_4_main_main_default.set_border_width(0)
style_screen_btn_4_main_main_default.set_border_opa(0)
style_screen_btn_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_4_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_4_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_4
screen_btn_4.add_style(style_screen_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_3 = lv.btn(screen_cont_1)
screen_btn_3.set_pos(int(0),int(144))
screen_btn_3.set_size(790,61)
screen_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_3_main_main_default
style_screen_btn_3_main_main_default = lv.style_t()
style_screen_btn_3_main_main_default.init()
style_screen_btn_3_main_main_default.set_radius(5)
style_screen_btn_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_3_main_main_default.set_bg_opa(0)
style_screen_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_default.set_border_width(0)
style_screen_btn_3_main_main_default.set_border_opa(0)
style_screen_btn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_3_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_3_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_3
screen_btn_3.add_style(style_screen_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_2 = lv.btn(screen_cont_1)
screen_btn_2.set_pos(int(0),int(82))
screen_btn_2.set_size(790,61)
screen_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_2_main_main_default
style_screen_btn_2_main_main_default = lv.style_t()
style_screen_btn_2_main_main_default.init()
style_screen_btn_2_main_main_default.set_radius(5)
style_screen_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_2_main_main_default.set_bg_opa(0)
style_screen_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_default.set_border_width(0)
style_screen_btn_2_main_main_default.set_border_opa(0)
style_screen_btn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_2_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_2_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_2
screen_btn_2.add_style(style_screen_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_1 = lv.btn(screen_cont_1)
screen_btn_1.set_pos(int(0),int(19))
screen_btn_1.set_size(790,61)
screen_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_btn_1_main_main_default
style_screen_btn_1_main_main_default = lv.style_t()
style_screen_btn_1_main_main_default.init()
style_screen_btn_1_main_main_default.set_radius(5)
style_screen_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_1_main_main_default.set_bg_opa(0)
style_screen_btn_1_main_main_default.set_border_color(lv.color_make(0x67,0x70,0x79))
style_screen_btn_1_main_main_default.set_border_width(0)
style_screen_btn_1_main_main_default.set_border_opa(0)
style_screen_btn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_1_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_1
screen_btn_1.add_style(style_screen_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_1 = lv.img(screen_cont_1)
screen_img_1.set_pos(int(0),int(14))
screen_img_1.set_size(70,70)
screen_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1371925196.png','rb') as f:
        screen_img_1_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1371925196.png')
    sys.exit()

screen_img_1_img = lv.img_dsc_t({
  'data_size': len(screen_img_1_img_data),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_1_img_data
})

screen_img_1.set_src(screen_img_1_img)
screen_img_1.set_pivot(0,0)
screen_img_1.set_angle(0)
# create style style_screen_img_1_main_main_default
style_screen_img_1_main_main_default = lv.style_t()
style_screen_img_1_main_main_default.init()
style_screen_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_1_main_main_default.set_img_recolor_opa(0)
style_screen_img_1_main_main_default.set_img_opa(255)

# add style for screen_img_1
screen_img_1.add_style(style_screen_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_cont_1_main_main_default
style_screen_cont_1_main_main_default = lv.style_t()
style_screen_cont_1_main_main_default.init()
style_screen_cont_1_main_main_default.set_radius(0)
style_screen_cont_1_main_main_default.set_bg_color(lv.color_make(0x34,0x32,0x47))
style_screen_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x34,0x32,0x47))
style_screen_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_cont_1_main_main_default.set_bg_opa(255)
style_screen_cont_1_main_main_default.set_border_color(lv.color_make(0x4a,0x52,0x59))
style_screen_cont_1_main_main_default.set_border_width(0)
style_screen_cont_1_main_main_default.set_border_opa(255)
style_screen_cont_1_main_main_default.set_pad_left(0)
style_screen_cont_1_main_main_default.set_pad_right(0)
style_screen_cont_1_main_main_default.set_pad_top(0)
style_screen_cont_1_main_main_default.set_pad_bottom(0)

# add style for screen_cont_1
screen_cont_1.add_style(style_screen_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_player = lv.obj(screen)
screen_player.set_pos(int(0),int(0))
screen_player.set_size(800,480)
screen_player.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_album = lv.img(screen_player)
screen_img_album.set_pos(int(311),int(148))
screen_img_album.set_size(175,175)
screen_img_album.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_album.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1279233.png','rb') as f:
        screen_img_album_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1279233.png')
    sys.exit()

screen_img_album_img = lv.img_dsc_t({
  'data_size': len(screen_img_album_img_data),
  'header': {'always_zero': 0, 'w': 175, 'h': 175, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_album_img_data
})

screen_img_album.set_src(screen_img_album_img)
screen_img_album.set_pivot(0,0)
screen_img_album.set_angle(0)
# create style style_screen_img_album_main_main_default
style_screen_img_album_main_main_default = lv.style_t()
style_screen_img_album_main_main_default.init()
style_screen_img_album_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_album_main_main_default.set_img_recolor_opa(0)
style_screen_img_album_main_main_default.set_img_opa(255)

# add style for screen_img_album
screen_img_album.add_style(style_screen_img_album_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_imgbtn_play = lv.imgbtn(screen_player)
screen_imgbtn_play.set_pos(int(360),int(351))
screen_imgbtn_play.set_size(80,84)
screen_imgbtn_play.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1311787669.png','rb') as f:
        screen_imgbtn_play_imgReleased_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1311787669.png')
    sys.exit()

screen_imgbtn_play_imgReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_play_imgReleased_data),
  'header': {'always_zero': 0, 'w': 80, 'h': 84, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_play_imgReleased_data
})
screen_imgbtn_play.set_src(lv.imgbtn.STATE.RELEASED, screen_imgbtn_play_imgReleased, None, None)

try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1311787669.png','rb') as f:
        screen_imgbtn_play_imgPressed_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1311787669.png')
    sys.exit()

screen_imgbtn_play_imgPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_play_imgPressed_data),
  'header': {'always_zero': 0, 'w': 80, 'h': 84, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_play_imgPressed_data
})
screen_imgbtn_play.set_src(lv.imgbtn.STATE.PRESSED, screen_imgbtn_play_imgPressed, None, None)


try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp2093471997.png','rb') as f:
        screen_imgbtn_play_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp2093471997.png')
    sys.exit()

screen_imgbtn_play_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_play_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 80, 'h': 84, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_play_imgCheckedReleased_data
})
screen_imgbtn_play.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, screen_imgbtn_play_imgCheckedReleased, None, None)

try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp2093471997.png','rb') as f:
        screen_imgbtn_play_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp2093471997.png')
    sys.exit()

screen_imgbtn_play_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_play_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 80, 'h': 84, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_play_imgCheckedPressed_data
})
screen_imgbtn_play.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, screen_imgbtn_play_imgCheckedPressed, None, None)

screen_imgbtn_play.add_flag(lv.obj.FLAG.CHECKABLE)
screen_img_9 = lv.img(screen_player)
screen_img_9.set_pos(int(311),int(148))
screen_img_9.set_size(175,175)
screen_img_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp960334784.png','rb') as f:
        screen_img_9_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp960334784.png')
    sys.exit()

screen_img_9_img = lv.img_dsc_t({
  'data_size': len(screen_img_9_img_data),
  'header': {'always_zero': 0, 'w': 175, 'h': 175, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_9_img_data
})

screen_img_9.set_src(screen_img_9_img)
screen_img_9.set_pivot(0,0)
screen_img_9.set_angle(0)
# create style style_screen_img_9_main_main_default
style_screen_img_9_main_main_default = lv.style_t()
style_screen_img_9_main_main_default.init()
style_screen_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_9_main_main_default.set_img_recolor_opa(0)
style_screen_img_9_main_main_default.set_img_opa(255)

# add style for screen_img_9
screen_img_9.add_style(style_screen_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_10 = lv.img(screen_player)
screen_img_10.set_pos(int(311),int(148))
screen_img_10.set_size(175,175)
screen_img_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1921948801.png','rb') as f:
        screen_img_10_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1921948801.png')
    sys.exit()

screen_img_10_img = lv.img_dsc_t({
  'data_size': len(screen_img_10_img_data),
  'header': {'always_zero': 0, 'w': 175, 'h': 175, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_10_img_data
})

screen_img_10.set_src(screen_img_10_img)
screen_img_10.set_pivot(0,0)
screen_img_10.set_angle(0)
# create style style_screen_img_10_main_main_default
style_screen_img_10_main_main_default = lv.style_t()
style_screen_img_10_main_main_default.init()
style_screen_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_10_main_main_default.set_img_recolor_opa(0)
style_screen_img_10_main_main_default.set_img_opa(255)

# add style for screen_img_10
screen_img_10.add_style(style_screen_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_wave_bottom = lv.img(screen_player)
screen_img_wave_bottom.set_pos(int(0),int(428))
screen_img_wave_bottom.set_size(800,51)
screen_img_wave_bottom.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_wave_bottom.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-2044859625.png','rb') as f:
        screen_img_wave_bottom_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-2044859625.png')
    sys.exit()

screen_img_wave_bottom_img = lv.img_dsc_t({
  'data_size': len(screen_img_wave_bottom_img_data),
  'header': {'always_zero': 0, 'w': 800, 'h': 51, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_wave_bottom_img_data
})

screen_img_wave_bottom.set_src(screen_img_wave_bottom_img)
screen_img_wave_bottom.set_pivot(0,0)
screen_img_wave_bottom.set_angle(0)
# create style style_screen_img_wave_bottom_main_main_default
style_screen_img_wave_bottom_main_main_default = lv.style_t()
style_screen_img_wave_bottom_main_main_default.init()
style_screen_img_wave_bottom_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_wave_bottom_main_main_default.set_img_recolor_opa(0)
style_screen_img_wave_bottom_main_main_default.set_img_opa(255)

# add style for screen_img_wave_bottom
screen_img_wave_bottom.add_style(style_screen_img_wave_bottom_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_wave_top = lv.img(screen_player)
screen_img_wave_top.set_pos(int(0),int(0))
screen_img_wave_top.set_size(800,51)
screen_img_wave_top.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_wave_top.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1507932091.png','rb') as f:
        screen_img_wave_top_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1507932091.png')
    sys.exit()

screen_img_wave_top_img = lv.img_dsc_t({
  'data_size': len(screen_img_wave_top_img_data),
  'header': {'always_zero': 0, 'w': 800, 'h': 51, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_wave_top_img_data
})

screen_img_wave_top.set_src(screen_img_wave_top_img)
screen_img_wave_top.set_pivot(0,0)
screen_img_wave_top.set_angle(0)
# create style style_screen_img_wave_top_main_main_default
style_screen_img_wave_top_main_main_default = lv.style_t()
style_screen_img_wave_top_main_main_default.init()
style_screen_img_wave_top_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_wave_top_main_main_default.set_img_recolor_opa(0)
style_screen_img_wave_top_main_main_default.set_img_opa(255)

# add style for screen_img_wave_top
screen_img_wave_top.add_style(style_screen_img_wave_top_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_icn_rnd = lv.img(screen_player)
screen_img_icn_rnd.set_pos(int(70),int(384))
screen_img_icn_rnd.set_size(25,25)
screen_img_icn_rnd.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_rnd.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1603417921.png','rb') as f:
        screen_img_icn_rnd_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp1603417921.png')
    sys.exit()

screen_img_icn_rnd_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_rnd_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_rnd_img_data
})

screen_img_icn_rnd.set_src(screen_img_icn_rnd_img)
screen_img_icn_rnd.set_pivot(0,0)
screen_img_icn_rnd.set_angle(0)
screen_img_icn_loop = lv.img(screen_player)
screen_img_icn_loop.set_pos(int(701),int(384))
screen_img_icn_loop.set_size(25,25)
screen_img_icn_loop.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_loop.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-153703977.png','rb') as f:
        screen_img_icn_loop_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-153703977.png')
    sys.exit()

screen_img_icn_loop_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_loop_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_loop_img_data
})

screen_img_icn_loop.set_src(screen_img_icn_loop_img)
screen_img_icn_loop.set_pivot(0,0)
screen_img_icn_loop.set_angle(0)
screen_img_icn_left = lv.img(screen_player)
screen_img_icn_left.set_pos(int(203),int(360))
screen_img_icn_left.set_size(61,61)
screen_img_icn_left.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_left.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1540330666.png','rb') as f:
        screen_img_icn_left_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1540330666.png')
    sys.exit()

screen_img_icn_left_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_left_img_data),
  'header': {'always_zero': 0, 'w': 61, 'h': 61, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_left_img_data
})

screen_img_icn_left.set_src(screen_img_icn_left_img)
screen_img_icn_left.set_pivot(0,0)
screen_img_icn_left.set_angle(0)
screen_img_icn_right = lv.img(screen_player)
screen_img_icn_right.set_pos(int(530),int(360))
screen_img_icn_right.set_size(61,61)
screen_img_icn_right.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_right.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-198110186.png','rb') as f:
        screen_img_icn_right_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-198110186.png')
    sys.exit()

screen_img_icn_right_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_right_img_data),
  'header': {'always_zero': 0, 'w': 61, 'h': 61, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_right_img_data
})

screen_img_icn_right.set_src(screen_img_icn_right_img)
screen_img_icn_right.set_pivot(0,0)
screen_img_icn_right.set_angle(0)
screen_slider_1 = lv.slider(screen_player)
screen_slider_1.set_pos(int(70),int(441))
screen_slider_1.set_size(570,1)
screen_slider_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_slider_1.set_range(0, 100)
screen_slider_1.set_value(0, False)

# create style style_screen_slider_1_main_main_default
style_screen_slider_1_main_main_default = lv.style_t()
style_screen_slider_1_main_main_default.init()
style_screen_slider_1_main_main_default.set_radius(50)
style_screen_slider_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_slider_1_main_main_default.set_bg_opa(100)
style_screen_slider_1_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_main_default.set_outline_width(0)
style_screen_slider_1_main_main_default.set_outline_opa(255)

# add style for screen_slider_1
screen_slider_1.add_style(style_screen_slider_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_slider_1_main_indicator_default
style_screen_slider_1_main_indicator_default = lv.style_t()
style_screen_slider_1_main_indicator_default.init()
style_screen_slider_1_main_indicator_default.set_radius(50)
style_screen_slider_1_main_indicator_default.set_bg_color(lv.color_make(0x56,0x91,0xf8))
style_screen_slider_1_main_indicator_default.set_bg_grad_color(lv.color_make(0xa6,0x66,0xf1))
style_screen_slider_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_screen_slider_1_main_indicator_default.set_bg_opa(255)

# add style for screen_slider_1
screen_slider_1.add_style(style_screen_slider_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_screen_slider_1_main_knob_default
style_screen_slider_1_main_knob_default = lv.style_t()
style_screen_slider_1_main_knob_default.init()
style_screen_slider_1_main_knob_default.set_radius(50)
style_screen_slider_1_main_knob_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_slider_1_main_knob_default.set_bg_opa(0)

# add style for screen_slider_1
screen_slider_1.add_style(style_screen_slider_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_img_icn_msg = lv.img(screen_player)
screen_img_icn_msg.set_pos(int(635),int(72))
screen_img_icn_msg.set_size(25,25)
screen_img_icn_msg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_msg.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp989924691.png','rb') as f:
        screen_img_icn_msg_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp989924691.png')
    sys.exit()

screen_img_icn_msg_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_msg_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_msg_img_data
})

screen_img_icn_msg.set_src(screen_img_icn_msg_img)
screen_img_icn_msg.set_pivot(0,0)
screen_img_icn_msg.set_angle(0)
# create style style_screen_img_icn_msg_main_main_default
style_screen_img_icn_msg_main_main_default = lv.style_t()
style_screen_img_icn_msg_main_main_default.init()
style_screen_img_icn_msg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_icn_msg_main_main_default.set_img_recolor_opa(0)
style_screen_img_icn_msg_main_main_default.set_img_opa(255)

# add style for screen_img_icn_msg
screen_img_icn_msg.add_style(style_screen_img_icn_msg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_icn_heart = lv.img(screen_player)
screen_img_icn_heart.set_pos(int(140),int(72))
screen_img_icn_heart.set_size(25,25)
screen_img_icn_heart.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_heart.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-374600361.png','rb') as f:
        screen_img_icn_heart_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-374600361.png')
    sys.exit()

screen_img_icn_heart_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_heart_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_heart_img_data
})

screen_img_icn_heart.set_src(screen_img_icn_heart_img)
screen_img_icn_heart.set_pivot(0,0)
screen_img_icn_heart.set_angle(0)
# create style style_screen_img_icn_heart_main_main_default
style_screen_img_icn_heart_main_main_default = lv.style_t()
style_screen_img_icn_heart_main_main_default.init()
style_screen_img_icn_heart_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_icn_heart_main_main_default.set_img_recolor_opa(0)
style_screen_img_icn_heart_main_main_default.set_img_opa(255)

# add style for screen_img_icn_heart
screen_img_icn_heart.add_style(style_screen_img_icn_heart_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_icn_donwload = lv.img(screen_player)
screen_img_icn_donwload.set_pos(int(470),int(72))
screen_img_icn_donwload.set_size(25,25)
screen_img_icn_donwload.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_donwload.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1974319101.png','rb') as f:
        screen_img_icn_donwload_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-1974319101.png')
    sys.exit()

screen_img_icn_donwload_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_donwload_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_donwload_img_data
})

screen_img_icn_donwload.set_src(screen_img_icn_donwload_img)
screen_img_icn_donwload.set_pivot(0,0)
screen_img_icn_donwload.set_angle(0)
# create style style_screen_img_icn_donwload_main_main_default
style_screen_img_icn_donwload_main_main_default = lv.style_t()
style_screen_img_icn_donwload_main_main_default.init()
style_screen_img_icn_donwload_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_icn_donwload_main_main_default.set_img_recolor_opa(0)
style_screen_img_icn_donwload_main_main_default.set_img_opa(255)

# add style for screen_img_icn_donwload
screen_img_icn_donwload.add_style(style_screen_img_icn_donwload_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_img_icn_chart = lv.img(screen_player)
screen_img_icn_chart.set_pos(int(305),int(72))
screen_img_icn_chart.set_size(25,25)
screen_img_icn_chart.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_img_icn_chart.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-309351185.png','rb') as f:
        screen_img_icn_chart_img_data = f.read()
except:
    print('Could not open /home/light/GUI-Guider-Projects/lcd_demo/generated/mPythonImages/mp-309351185.png')
    sys.exit()

screen_img_icn_chart_img = lv.img_dsc_t({
  'data_size': len(screen_img_icn_chart_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_icn_chart_img_data
})

screen_img_icn_chart.set_src(screen_img_icn_chart_img)
screen_img_icn_chart.set_pivot(0,0)
screen_img_icn_chart.set_angle(0)
# create style style_screen_img_icn_chart_main_main_default
style_screen_img_icn_chart_main_main_default = lv.style_t()
style_screen_img_icn_chart_main_main_default.init()
style_screen_img_icn_chart_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_img_icn_chart_main_main_default.set_img_recolor_opa(0)
style_screen_img_icn_chart_main_main_default.set_img_opa(255)

# add style for screen_img_icn_chart
screen_img_icn_chart.add_style(style_screen_img_icn_chart_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_slider_time = lv.label(screen_player)
screen_label_slider_time.set_pos(int(700),int(432))
screen_label_slider_time.set_size(60,19)
screen_label_slider_time.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_slider_time.set_text("0:00")
screen_label_slider_time.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_slider_time_main_main_default
style_screen_label_slider_time_main_main_default = lv.style_t()
style_screen_label_slider_time_main_main_default.init()
style_screen_label_slider_time_main_main_default.set_radius(0)
style_screen_label_slider_time_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_slider_time_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_slider_time_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_slider_time_main_main_default.set_bg_opa(0)
style_screen_label_slider_time_main_main_default.set_text_color(lv.color_make(0x8a,0x86,0xb8))
try:
    style_screen_label_slider_time_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_slider_time_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_slider_time_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_slider_time_main_main_default.set_text_letter_space(0)
style_screen_label_slider_time_main_main_default.set_text_line_space(0)
style_screen_label_slider_time_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_slider_time_main_main_default.set_pad_left(0)
style_screen_label_slider_time_main_main_default.set_pad_right(0)
style_screen_label_slider_time_main_main_default.set_pad_top(0)
style_screen_label_slider_time_main_main_default.set_pad_bottom(0)

# add style for screen_label_slider_time
screen_label_slider_time.add_style(style_screen_label_slider_time_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_tracks = lv.label(screen_player)
screen_label_tracks.set_pos(int(390),int(476))
screen_label_tracks.set_size(20,1)
screen_label_tracks.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_label_tracks_main_main_default
style_screen_label_tracks_main_main_default = lv.style_t()
style_screen_label_tracks_main_main_default.init()
style_screen_label_tracks_main_main_default.set_radius(0)
style_screen_label_tracks_main_main_default.set_bg_color(lv.color_make(0x8a,0x86,0xb8))
style_screen_label_tracks_main_main_default.set_bg_grad_color(lv.color_make(0x8a,0x86,0xb8))
style_screen_label_tracks_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_tracks_main_main_default.set_bg_opa(229)
style_screen_label_tracks_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_label_tracks_main_main_default.set_text_font(lv.font_arial_20)
except AttributeError:
    try:
        style_screen_label_tracks_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_label_tracks_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_tracks_main_main_default.set_text_letter_space(2)
style_screen_label_tracks_main_main_default.set_text_line_space(0)
style_screen_label_tracks_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_tracks_main_main_default.set_pad_left(0)
style_screen_label_tracks_main_main_default.set_pad_right(0)
style_screen_label_tracks_main_main_default.set_pad_top(0)
style_screen_label_tracks_main_main_default.set_pad_bottom(0)

# add style for screen_label_tracks
screen_label_tracks.add_style(style_screen_label_tracks_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_tracks = lv.btn(screen_player)
screen_btn_tracks.set_pos(int(350),int(451))
screen_btn_tracks.set_size(100,28)
screen_btn_tracks.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_btn_tracks_label = lv.label(screen_btn_tracks)
screen_btn_tracks_label.set_text("ALL TRACK")
screen_btn_tracks.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_btn_tracks_label.align(lv.ALIGN.CENTER,0,0)
# create style style_screen_btn_tracks_main_main_default
style_screen_btn_tracks_main_main_default = lv.style_t()
style_screen_btn_tracks_main_main_default.init()
style_screen_btn_tracks_main_main_default.set_radius(5)
style_screen_btn_tracks_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_tracks_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_tracks_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_btn_tracks_main_main_default.set_bg_opa(0)
style_screen_btn_tracks_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_tracks_main_main_default.set_border_width(0)
style_screen_btn_tracks_main_main_default.set_border_opa(255)
style_screen_btn_tracks_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_tracks_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_btn_tracks_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_btn_tracks_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_tracks_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_tracks
screen_btn_tracks.add_style(style_screen_btn_tracks_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_title_music = lv.label(screen_player)
screen_label_title_music.set_pos(int(250),int(8))
screen_label_title_music.set_size(300,31)
screen_label_title_music.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_title_music.set_text("Waiting for true love")
screen_label_title_music.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_title_music_main_main_default
style_screen_label_title_music_main_main_default = lv.style_t()
style_screen_label_title_music_main_main_default.init()
style_screen_label_title_music_main_main_default.set_radius(0)
style_screen_label_title_music_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_title_music_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_title_music_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_title_music_main_main_default.set_bg_opa(0)
style_screen_label_title_music_main_main_default.set_text_color(lv.color_make(0x50,0x4d,0x6d))
try:
    style_screen_label_title_music_main_main_default.set_text_font(lv.font_arial_23)
except AttributeError:
    try:
        style_screen_label_title_music_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_screen_label_title_music_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_title_music_main_main_default.set_text_letter_space(0)
style_screen_label_title_music_main_main_default.set_text_line_space(0)
style_screen_label_title_music_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_title_music_main_main_default.set_pad_left(0)
style_screen_label_title_music_main_main_default.set_pad_right(0)
style_screen_label_title_music_main_main_default.set_pad_top(0)
style_screen_label_title_music_main_main_default.set_pad_bottom(0)

# add style for screen_label_title_music
screen_label_title_music.add_style(style_screen_label_title_music_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_title_author = lv.label(screen_player)
screen_label_title_author.set_pos(int(250),int(38))
screen_label_title_author.set_size(300,31)
screen_label_title_author.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_title_author.set_text("The John Smith Band")
screen_label_title_author.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_title_author_main_main_default
style_screen_label_title_author_main_main_default = lv.style_t()
style_screen_label_title_author_main_main_default.init()
style_screen_label_title_author_main_main_default.set_radius(0)
style_screen_label_title_author_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_title_author_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_title_author_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label_title_author_main_main_default.set_bg_opa(0)
style_screen_label_title_author_main_main_default.set_text_color(lv.color_make(0x50,0x4d,0x6d))
try:
    style_screen_label_title_author_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_screen_label_title_author_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_title_author_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_title_author_main_main_default.set_text_letter_space(0)
style_screen_label_title_author_main_main_default.set_text_line_space(0)
style_screen_label_title_author_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_title_author_main_main_default.set_pad_left(0)
style_screen_label_title_author_main_main_default.set_pad_right(0)
style_screen_label_title_author_main_main_default.set_pad_top(0)
style_screen_label_title_author_main_main_default.set_pad_bottom(0)

# add style for screen_label_title_author
screen_label_title_author.add_style(style_screen_label_title_author_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_player_main_main_default
style_screen_player_main_main_default = lv.style_t()
style_screen_player_main_main_default.init()
style_screen_player_main_main_default.set_radius(0)
style_screen_player_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_player_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_player_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_player_main_main_default.set_bg_opa(255)
style_screen_player_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_player_main_main_default.set_border_width(0)
style_screen_player_main_main_default.set_border_opa(255)
style_screen_player_main_main_default.set_pad_left(0)
style_screen_player_main_main_default.set_pad_right(0)
style_screen_player_main_main_default.set_pad_top(0)
style_screen_player_main_main_default.set_pad_bottom(0)

# add style for screen_player
screen_player.add_style(style_screen_player_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)











# content from custom.py
def anim_zoom_cb(obj, v):
    obj.set_zoom(v)
    
try:
    with open(sys.path[0].replace("generated","custom") + "/mp1544294806.png",'rb') as f:
        screen_img_album_2_img_data = f.read()
except:
    raise

screen_img_album_2_img = lv.img_dsc_t({
  'data_size': len(screen_img_album_2_img_data),
  'header': {'always_zero': 0, 'w': 105, 'h': 105, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_album_2_img_data
})

try:
    with open(sys.path[0].replace("generated","custom") + "/mp-1789058473.png",'rb') as f:
        screen_img_album_3_img_data = f.read()
except:
    raise

screen_img_album_3_img = lv.img_dsc_t({
  'data_size': len(screen_img_album_3_img_data),
  'header': {'always_zero': 0, 'w': 105, 'h': 105, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_img_album_3_img_data
})

def screen_img_album_update_src(src):
    global screen_img_album
    pos_x = screen_img_album.get_x()
    pos_y = screen_img_album.get_y()
    size_x = screen_img_album.get_width()
    size_y = screen_img_album.get_height()
    scrollbar_mode = screen_img_album.get_scrollbar_mode()
    angle = screen_img_album.get_angle()
    screen_img_album = lv.img(screen_player)
    screen_img_album.set_pos(pos_x, pos_y)
    screen_img_album.set_size(size_x,size_y)
    screen_img_album.set_scrollbar_mode(scrollbar_mode)
    screen_img_album.add_flag(lv.obj.FLAG.CLICKABLE)
    screen_img_album.set_src(src)
    screen_img_album.set_angle(angle)
    screen_img_album.add_event_cb(lambda e: screen_img_album_gesture_event_cb(e,screen_img_album), lv.EVENT.GESTURE, None)
    screen_img_album.clear_flag(lv.obj.FLAG.GESTURE_BUBBLE)

class MusicPlayer():
    def __init__(self) -> None:
        self.active_track_count = 3
        self.current_track_idx = 0
        self.slider_time = 0
        self.show_track_list = False
        self.playing = False
        self.title = [
            "Waiting for true love",
            "Need a Better Future",
            "Vibrations",
            "Why now",
            "Never Look Back",
            "It happened Yesterday",
            "Feeling so High",
            "Go Deeper",
        ]
        
        self.author = [
            "The John Smith Band",
            "My True Name",
            "Robotics",
            "John Smith",
            "My true Name",
            "Robotics",
            "Robotics",
            "Unknown artist",
        ]
        
        self.time = [
            1*60 + 14,
            2*60 + 26,
            1*60 + 54,
            2*60 + 24,
            2*60 + 57,
            2*60 + 33,
            3*60 + 33,
            1*60 + 56,
        ]
        
        self.btn = [
            screen_btn_1,
            screen_btn_2,
            screen_btn_3,
            screen_btn_4,
            screen_btn_5,
            screen_btn_6,
            screen_btn_7,
            screen_btn_8,
        ]
        
        self.icon = [
            screen_img_1,
            screen_img_2,
            screen_img_3,
            screen_img_4,
            screen_img_5,
            screen_img_6,
            screen_img_7,
            screen_img_8,
        ]
        
        self.img_dsc = [
            screen_img_album_img,
            screen_img_album_2_img,
            screen_img_album_3_img,
        ]
        
    def pause_track(self):
        #spectrum_i_pause = spectrum_i
        #spectrum_i = 0
        #lv_anim_del(spectrum_area, spectrum_anim_cb)
        #lv_obj_invalidate(spectrum_area)
        screen_img_album.set_zoom(lv.IMG_ZOOM.NONE)
        sec_counter_timer.pause()
        screen_imgbtn_play.clear_state(lv.STATE.CHECKED)
        screen_imgbtn_play.invalidate()
        
    def resume_track(self):
        #spectrum_i = spectrum_i_pause
        #a = lv.anim_t()
        #a.init()
        #a.set_var(screen_player)
        #a.set_time(1000)
        #a.set_path_cb(lv.anim_t.path_linear)
        #a.set_custom_exec_cb(lambda a,val: anim_y_cb(screen_player,val))
        #lv.anim_t.start(a)
        #
        #lv_anim_set_values(&a, spectrum_i, spectrum_len - 1)
        #lv_anim_set_exec_cb(&a, spectrum_anim_cb)
        #lv_anim_set_var(&a, spectrum_area)
        #lv_anim_set_time(&a, ((spectrum_len - spectrum_i) * 1000) / 30)
        #lv_anim_set_playback_time(&a, 0)
        #lv_anim_set_ready_cb(&a, spectrum_end_cb)
        #lv_anim_start(&a)
        sec_counter_timer.resume()
        screen_imgbtn_play.add_state(lv.STATE.CHECKED)
        screen_imgbtn_play.invalidate()
        
    def load_next_track(self, next=None, forward=True):
        if self.current_track_idx == next:
            return
        self.slider_time = 0
        #spectrum_i = 0
        #spectrum_i_pause = 0
        screen_slider_1.set_value(0, lv.ANIM.OFF)
        screen_label_slider_time.set_text("0:00")
        
        idx = self.current_track_idx
        btn = self.btn[idx]
        icon = self.icon[idx]
        btn.clear_state(lv.STATE.PRESSED)
        icon.set_src(screen_img_2_img)
        #screen_img_album.fade_out(500, 0)
        #a = lv.anim_t()
        #a.init()
        #a.set_var(screen_img_album)
        #a.set_time(500)
        #a.set_path_cb(lv.anim_t.path_ease_out)
        #if forward:
        #    a.set_values(187, 0)
        #else:
        #    a.set_values(187, 374)
        #a.set_custom_exec_cb(lambda a,val: anim_x_cb(screen_img_album,val))
        #a.set_ready_cb(lv.obj.del_anim_ready_cb)
        #lv.anim_t.start(a)
        
        if next or next == 0:
            idx = next
        else:
            if forward:
                idx = (idx + 1) % self.active_track_count
            else:
                idx = (idx - 1 + self.active_track_count) % self.active_track_count
            
        self.current_track_idx = idx
        btn = self.btn[idx]
        icon = self.icon[idx]
        if demoMP.playing:
            btn.add_state(lv.STATE.PRESSED)
            icon.set_src(screen_img_1_img)
        btn.scroll_to_view(lv.ANIM.ON)
        screen_slider_1.set_range(0, self.time[idx])
        screen_label_title_music.set_text(self.title[idx])
        screen_label_title_author.set_text(self.author[idx])
        #a = lv.anim_t()
        #a.init()
        #a.set_var(screen_img_album)
        #a.set_time(500)
        #a.set_path_cb(lv.anim_t.path_linear)
        #a.set_values(lv.IMG_ZOOM.NONE, lv.IMG_ZOOM.NONE // 2)
        #a.set_custom_exec_cb(lambda a,val: anim_zoom_cb(screen_img_album,val))
        #a.set_ready_cb(None)
        #lv.anim_t.start(a)
        #screen_img_album.set_src(demoMP.img_dsc[idx])
        screen_img_album_update_src(demoMP.img_dsc[idx])
        #screen_img_album.fade_in(500, 100)
        #a = lv.anim_t()
        #a.init()
        #a.set_var(screen_img_album)
        #a.set_time(500)
        #a.set_delay(100)
        #a.set_path_cb(lv.anim_t.path_overshoot)
        #a.set_values(lv.IMG_ZOOM.NONE // 4, lv.IMG_ZOOM.NONE)
        #a.set_custom_exec_cb(lambda a,val: anim_zoom_cb(screen_img_album,val))
        #a.set_ready_cb(None)
        #lv.anim_t.start(a)
        
demoMP = MusicPlayer()

def screen_slider_1_event_cb(e):
    slider = e.get_target()
    demoMP.slider_time = slider.get_value()

screen_slider_1.add_event_cb(screen_slider_1_event_cb, lv.EVENT.VALUE_CHANGED, None)

def set_slider_time_cb(timer):
    demoMP.slider_time += 1
    if demoMP.slider_time >= demoMP.time[demoMP.current_track_idx]:
        demoMP.load_next_track(forward=True)
        if demoMP.playing:
            demoMP.resume_track()
    else:
        screen_label_slider_time.set_text(f"{demoMP.slider_time // 60}:{demoMP.slider_time % 60:02}")
        screen_slider_1.set_value(demoMP.slider_time, lv.ANIM.ON)

sec_counter_timer = lv.timer_create(set_slider_time_cb, 1000, None)
sec_counter_timer.pause()

def screen_btn_tracks_clicked_2_event_cb(e,screen_player):
    screen_player_event_move_y = lv.anim_t()
    screen_player_event_move_y.init()
    screen_player_event_move_y.set_var(screen_player)
    if demoMP.show_track_list:
        screen_player_event_move_y.set_values(screen_player.get_y(), 0)
        demoMP.show_track_list = False
    else:
        screen_player_event_move_y.set_values(screen_player.get_y(), -261)
        demoMP.show_track_list = True
    screen_player_event_move_y.set_time(1000)
    screen_player_event_move_y.set_path_cb(lv.anim_t.path_linear)
    screen_player_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(screen_player,val))
    lv.anim_t.start(screen_player_event_move_y)
screen_btn_tracks.add_event_cb(lambda e: screen_btn_tracks_clicked_2_event_cb(e,screen_player), lv.EVENT.CLICKED, None)

def screen_img_album_gesture_event_cb(e,screen_img_album):
    indev = lv.indev_get_act()
    if not indev:
        return
    dir = indev.get_gesture_dir()
    if dir == lv.DIR.LEFT:
        demoMP.load_next_track(forward=False)
    if dir == lv.DIR.RIGHT:
        demoMP.load_next_track(forward=True)
    if demoMP.playing:
        demoMP.resume_track()

screen_img_album.add_event_cb(lambda e: screen_img_album_gesture_event_cb(e,screen_img_album), lv.EVENT.GESTURE, None)
screen_img_album.clear_flag(lv.obj.FLAG.GESTURE_BUBBLE)

def screen_imgbtn_play_released_event_cb(e,obj):
    code = e.get_code()
    btn = demoMP.btn[demoMP.current_track_idx]
    icon = demoMP.icon[demoMP.current_track_idx]
    if code == lv.EVENT.RELEASED:
        if obj.has_state(lv.STATE.CHECKED):
            demoMP.playing = True
            demoMP.resume_track()
            btn.add_state(lv.STATE.PRESSED)
            icon.set_src(screen_img_1_img)
        else:
            demoMP.playing = False
            demoMP.pause_track()
            btn.clear_state(lv.STATE.PRESSED)
            icon.set_src(screen_img_2_img)

screen_imgbtn_play.add_event_cb(lambda e: screen_imgbtn_play_released_event_cb(e,screen_imgbtn_play), lv.EVENT.ALL, None)

def screen_img_icn_clicked_event_cb(e,val):
    code = e.get_code()
    if code == lv.EVENT.CLICKED:
        demoMP.load_next_track(forward=val)
        if demoMP.playing:
            demoMP.resume_track()

screen_img_icn_left.add_event_cb(lambda e: screen_img_icn_clicked_event_cb(e,False), lv.EVENT.ALL, None)
screen_img_icn_right.add_event_cb(lambda e: screen_img_icn_clicked_event_cb(e,True), lv.EVENT.ALL, None)

screen_img_1.set_src(screen_img_2_img)
screen_slider_1.set_range(0, demoMP.time[0])
def screen_track_clicked_event_cb(e,idx):
    code = e.get_code()
    if code == lv.EVENT.CLICKED:
        btn = demoMP.btn[idx]
        icon = demoMP.icon[idx]
        if demoMP.current_track_idx == idx:
            if demoMP.playing:
                demoMP.playing = False
                demoMP.pause_track()
                btn.clear_state(lv.STATE.PRESSED)
                icon.set_src(screen_img_2_img)
            else:
                demoMP.playing = True
                demoMP.resume_track()
                btn.add_state(lv.STATE.PRESSED)
                icon.set_src(screen_img_1_img)
        else:
            demoMP.playing = True
            demoMP.load_next_track(next=idx)
            demoMP.resume_track()

screen_btn_1.add_event_cb(lambda e: screen_track_clicked_event_cb(e, 0), lv.EVENT.CLICKED, None)
screen_img_1.add_event_cb(lambda e: screen_track_clicked_event_cb(e, 0), lv.EVENT.CLICKED, None)
screen_btn_2.add_event_cb(lambda e: screen_track_clicked_event_cb(e, 1), lv.EVENT.CLICKED, None)
screen_img_2.add_event_cb(lambda e: screen_track_clicked_event_cb(e, 1), lv.EVENT.CLICKED, None)
screen_btn_3.add_event_cb(lambda e: screen_track_clicked_event_cb(e, 2), lv.EVENT.CLICKED, None)
screen_img_3.add_event_cb(lambda e: screen_track_clicked_event_cb(e, 2), lv.EVENT.CLICKED, None)

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)
