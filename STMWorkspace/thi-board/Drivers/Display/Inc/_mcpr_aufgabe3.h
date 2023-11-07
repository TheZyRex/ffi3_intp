#ifndef __MCPR_AUFGABE3_H
#define __MCPR_AUFGABE3_H

#include <inttypes.h>

#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240
#define MAX_STR_LEN 20

#define LCD_BACKGROUND 0xFFFF
#define LCD_BLACK 0x0000
#define LCD_WHITE 0xFFFF

extern void mcpr_LCD_WriteData(uint16_t data);
extern void mcpr_LCD_WriteCommand(uint16_t data);
extern void mcpr_LCD_InitPorts(void);
extern void mcpr_LCD_Init(void);
extern void mcpr_LCD_WriteReg(uint16_t cmd, uint16_t data);

extern void mcpr_LCD_Output16BitWord(uint16_t data);
extern void mcpr_LCD_SetCursor(const uint16_t x, const uint16_t y);
extern void mcpr_LCD_DrawPixel(uint16_t color);
extern void mcpr_LCD_ClearDisplay(uint16_t color);

extern void mcpr_LCD_WriteLetter(uint16_t x, uint16_t y, uint16_t colorfg, uint16_t colorbg, uint8_t c);
extern void mcpr_LCD_WriteString(uint16_t x, uint16_t y, uint16_t colorfg, uint16_t colorbg, char str[MAX_STR_LEN]);

__attribute__((noreturn)) extern void mcpr_DisplayMessung(void);
extern void mcpr_DisplayMessungV2(void);
extern void mcpr_DisplayMain(void);
#endif
