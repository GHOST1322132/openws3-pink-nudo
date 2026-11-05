/* ST7735S 80x160 panel, used landscape 160x80, RGB565, bit-banged SPI.  No framebuffer (RAM is 8 KB). */
#ifndef LCD_H
#define LCD_H
#include "compat.h"

#define LCD_PX_W 160
#define LCD_PX_H 80

void lcd_init(void);
void lcd_wake(void);              /* sleep-out; the panel wants 5 ms before lcd_reconfig */
void lcd_reconfig(void);          /* re-send the panel registers (not the picture); see lcd.c */
void lcd_fill(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);

/* A one-colour picture: w x h pixels (w <= 16, h <= 10), one uint16 per row, the leftmost pixel in bit w-1.  Set bits are drawn in
 * the foreground colour, clear bits in the background, the whole picture stretched s times in both directions. */
typedef struct { uint8_t w, h; uint16_t row[10]; } sprite_t;
void lcd_sprite(uint8_t x, uint8_t y, uint8_t s, const CODE sprite_t *sp, uint16_t fg, uint16_t bg);
/* sx, sy: integer stretch of the 6x8 cell.  Characters outside the font draw as space. */
void lcd_text(uint8_t x, uint8_t y, const char *s, uint8_t sx, uint8_t sy, uint16_t fg, uint16_t bg);

#endif
