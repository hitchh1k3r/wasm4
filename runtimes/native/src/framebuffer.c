#include "framebuffer.h"

#include <string.h>

static const uint8_t font[1792] = { 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xc7,0xc7,0xcf,0xcf,0xff,0xcf,0xff,0x93,0x93,0x93,0xff,0xff,0xff,0xff,0xff,0x93,0x01,0x93,0x93,0x93,0x01,0x93,0xff,0xef,0x83,0x2f,0x83,0xe9,0x03,0xef,0xff,0x9d,0x5b,0x37,0xef,0xd9,0xb5,0x73,0xff,0x8f,0x27,0x27,0x8f,0x25,0x33,0x81,0xff,0xcf,0xcf,0xcf,0xff,0xff,0xff,0xff,0xff,0xf3,0xe7,0xcf,0xcf,0xcf,0xe7,0xf3,0xff,0x9f,0xcf,0xe7,0xe7,0xe7,0xcf,0x9f,0xff,0xff,0x93,0xc7,0x01,0xc7,0x93,0xff,0xff,0xff,0xe7,0xe7,0x81,0xe7,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xcf,0x9f,0xff,0xff,0xff,0x81,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xcf,0xff,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xff,0xc7,0xb3,0x39,0x39,0x39,0x9b,0xc7,0xff,0xe7,0xc7,0xe7,0xe7,0xe7,0xe7,0x81,0xff,0x83,0x39,0xf1,0xc3,0x87,0x1f,0x01,0xff,0x81,0xf3,0xe7,0xc3,0xf9,0x39,0x83,0xff,0xe3,0xc3,0x93,0x33,0x01,0xf3,0xf3,0xff,0x03,0x3f,0x03,0xf9,0xf9,0x39,0x83,0xff,0xc3,0x9f,0x3f,0x03,0x39,0x39,0x83,0xff,0x01,0x39,0xf3,0xe7,0xcf,0xcf,0xcf,0xff,0x87,0x3b,0x1b,0x87,0x61,0x79,0x83,0xff,0x83,0x39,0x39,0x81,0xf9,0xf3,0x87,0xff,0xff,0xcf,0xcf,0xff,0xcf,0xcf,0xff,0xff,0xff,0xcf,0xcf,0xff,0xcf,0xcf,0x9f,0xff,0xf3,0xe7,0xcf,0x9f,0xcf,0xe7,0xf3,0xff,0xff,0xff,0x01,0xff,0x01,0xff,0xff,0xff,0x9f,0xcf,0xe7,0xf3,0xe7,0xcf,0x9f,0xff,0x83,0x01,0x39,0xf3,0xc7,0xff,0xc7,0xff,0x83,0x7d,0x45,0x55,0x41,0x7f,0x83,0xff,0xc7,0x93,0x39,0x39,0x01,0x39,0x39,0xff,0x03,0x39,0x39,0x03,0x39,0x39,0x03,0xff,0xc3,0x99,0x3f,0x3f,0x3f,0x99,0xc3,0xff,0x07,0x33,0x39,0x39,0x39,0x33,0x07,0xff,0x01,0x3f,0x3f,0x03,0x3f,0x3f,0x01,0xff,0x01,0x3f,0x3f,0x03,0x3f,0x3f,0x3f,0xff,0xc1,0x9f,0x3f,0x31,0x39,0x99,0xc1,0xff,0x39,0x39,0x39,0x01,0x39,0x39,0x39,0xff,0x81,0xe7,0xe7,0xe7,0xe7,0xe7,0x81,0xff,0xf9,0xf9,0xf9,0xf9,0xf9,0x39,0x83,0xff,0x39,0x33,0x27,0x0f,0x07,0x23,0x31,0xff,0x9f,0x9f,0x9f,0x9f,0x9f,0x9f,0x81,0xff,0x39,0x11,0x01,0x01,0x29,0x39,0x39,0xff,0x39,0x19,0x09,0x01,0x21,0x31,0x39,0xff,0x83,0x39,0x39,0x39,0x39,0x39,0x83,0xff,0x03,0x39,0x39,0x39,0x03,0x3f,0x3f,0xff,0x83,0x39,0x39,0x39,0x21,0x33,0x85,0xff,0x03,0x39,0x39,0x31,0x07,0x23,0x31,0xff,0x87,0x33,0x3f,0x83,0xf9,0x39,0x83,0xff,0x81,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xff,0x39,0x39,0x39,0x39,0x39,0x39,0x83,0xff,0x39,0x39,0x39,0x11,0x83,0xc7,0xef,0xff,0x39,0x39,0x29,0x01,0x01,0x11,0x39,0xff,0x39,0x11,0x83,0xc7,0x83,0x11,0x39,0xff,0x99,0x99,0x99,0xc3,0xe7,0xe7,0xe7,0xff,0x01,0xf1,0xe3,0xc7,0x8f,0x1f,0x01,0xff,0xc3,0xcf,0xcf,0xcf,0xcf,0xcf,0xc3,0xff,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xff,0x87,0xe7,0xe7,0xe7,0xe7,0xe7,0x87,0xff,0xc7,0x93,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x01,0xef,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x83,0xf9,0x81,0x39,0x81,0xff,0x3f,0x3f,0x03,0x39,0x39,0x39,0x83,0xff,0xff,0xff,0x81,0x3f,0x3f,0x3f,0x81,0xff,0xf9,0xf9,0x81,0x39,0x39,0x39,0x81,0xff,0xff,0xff,0x83,0x39,0x01,0x3f,0x83,0xff,0xf1,0xe7,0x81,0xe7,0xe7,0xe7,0xe7,0xff,0xff,0xff,0x81,0x39,0x39,0x81,0xf9,0x83,0x3f,0x3f,0x03,0x39,0x39,0x39,0x39,0xff,0xe7,0xff,0xc7,0xe7,0xe7,0xe7,0x81,0xff,0xf3,0xff,0xe3,0xf3,0xf3,0xf3,0xf3,0x87,0x3f,0x3f,0x31,0x03,0x07,0x23,0x31,0xff,0xc7,0xe7,0xe7,0xe7,0xe7,0xe7,0x81,0xff,0xff,0xff,0x03,0x49,0x49,0x49,0x49,0xff,0xff,0xff,0x03,0x39,0x39,0x39,0x39,0xff,0xff,0xff,0x83,0x39,0x39,0x39,0x83,0xff,0xff,0xff,0x03,0x39,0x39,0x03,0x3f,0x3f,0xff,0xff,0x81,0x39,0x39,0x81,0xf9,0xf9,0xff,0xff,0x91,0x8f,0x9f,0x9f,0x9f,0xff,0xff,0xff,0x83,0x3f,0x83,0xf9,0x03,0xff,0xe7,0xe7,0x81,0xe7,0xe7,0xe7,0xe7,0xff,0xff,0xff,0x39,0x39,0x39,0x39,0x81,0xff,0xff,0xff,0x99,0x99,0x99,0xc3,0xe7,0xff,0xff,0xff,0x49,0x49,0x49,0x49,0x81,0xff,0xff,0xff,0x39,0x01,0xc7,0x01,0x39,0xff,0xff,0xff,0x39,0x39,0x39,0x81,0xf9,0x83,0xff,0xff,0x01,0xe3,0xc7,0x8f,0x01,0xff,0xf3,0xe7,0xe7,0xcf,0xe7,0xe7,0xf3,0xff,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xff,0x9f,0xcf,0xcf,0xe7,0xcf,0xcf,0x9f,0xff,0xff,0xff,0x8f,0x45,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x93,0x93,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xff,0xe7,0xe7,0xc7,0xc7,0xc7,0xff,0xef,0x83,0x29,0x2f,0x29,0x83,0xef,0xff,0xc3,0x99,0x9f,0x03,0x9f,0x9f,0x01,0xff,0xff,0xa5,0xdb,0xdb,0xdb,0xa5,0xff,0xff,0x99,0x99,0xc3,0x81,0xe7,0x81,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xc3,0x99,0x87,0xdb,0xe1,0x99,0xc3,0xff,0x93,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xbd,0x66,0x5e,0x5e,0x66,0xbd,0xc3,0x87,0xc3,0x93,0xc3,0xff,0xff,0xff,0xff,0xff,0xc9,0x93,0x27,0x93,0xc9,0xff,0xff,0xff,0xff,0x81,0xf9,0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xbd,0x46,0x5a,0x46,0x5a,0xbd,0xc3,0x83,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xd7,0xef,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0x81,0xe7,0xe7,0xff,0x81,0xff,0xc7,0xf3,0xe7,0xc3,0xff,0xff,0xff,0xff,0xc3,0xe7,0xf3,0xc7,0xff,0xff,0xff,0xff,0xf7,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x33,0x33,0x33,0x33,0x09,0x3f,0xc1,0x95,0xb5,0x95,0xc1,0xf5,0xf5,0xff,0xff,0xff,0xff,0xcf,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xcf,0xe7,0xc7,0xe7,0xc3,0xff,0xff,0xff,0xff,0xc7,0x93,0x93,0xc7,0xff,0xff,0xff,0xff,0xff,0x27,0x93,0xc9,0x93,0x27,0xff,0xff,0xbd,0x3b,0xb7,0xad,0xd9,0xb1,0x7d,0xff,0xbd,0x3b,0xb7,0xa9,0xdd,0xbb,0x71,0xff,0x1d,0xbb,0xd7,0x2d,0xd9,0xb1,0x7d,0xff,0xc7,0xff,0xc7,0x9f,0x39,0x01,0x83,0xff,0xdf,0xef,0xc7,0x93,0x39,0x01,0x39,0xff,0xf7,0xef,0xc7,0x93,0x39,0x01,0x39,0xff,0xc7,0x93,0xc7,0x93,0x39,0x01,0x39,0xff,0xcb,0xa7,0xc7,0x93,0x39,0x01,0x39,0xff,0x93,0xff,0xc7,0x93,0x39,0x01,0x39,0xff,0xef,0xd7,0xc7,0x93,0x39,0x01,0x39,0xff,0xc1,0x87,0x27,0x21,0x07,0x27,0x21,0xff,0xc3,0x99,0x3f,0x3f,0x99,0xc3,0xf7,0xcf,0xdf,0xef,0x01,0x3f,0x03,0x3f,0x01,0xff,0xf7,0xef,0x01,0x3f,0x03,0x3f,0x01,0xff,0xc7,0x93,0x01,0x3f,0x03,0x3f,0x01,0xff,0x93,0xff,0x01,0x3f,0x03,0x3f,0x01,0xff,0xef,0xf7,0x81,0xe7,0xe7,0xe7,0x81,0xff,0xf7,0xef,0x81,0xe7,0xe7,0xe7,0x81,0xff,0xe7,0xc3,0x81,0xe7,0xe7,0xe7,0x81,0xff,0x99,0xff,0x81,0xe7,0xe7,0xe7,0x81,0xff,0x87,0x93,0x99,0x09,0x99,0x93,0x87,0xff,0xcb,0xa7,0x19,0x09,0x01,0x21,0x31,0xff,0xdf,0xef,0x83,0x39,0x39,0x39,0x83,0xff,0xf7,0xef,0x83,0x39,0x39,0x39,0x83,0xff,0xc7,0x93,0x83,0x39,0x39,0x39,0x83,0xff,0xcb,0xa7,0x83,0x39,0x39,0x39,0x83,0xff,0x93,0xff,0x83,0x39,0x39,0x39,0x83,0xff,0xff,0xbb,0xd7,0xef,0xd7,0xbb,0xff,0xff,0x83,0x39,0x31,0x29,0x19,0x39,0x83,0xff,0xdf,0xef,0x39,0x39,0x39,0x39,0x83,0xff,0xf7,0xef,0x39,0x39,0x39,0x39,0x83,0xff,0xc7,0x93,0xff,0x39,0x39,0x39,0x83,0xff,0x93,0xff,0x39,0x39,0x39,0x39,0x83,0xff,0xf7,0xef,0x99,0x99,0xc3,0xe7,0xe7,0xff,0x3f,0x03,0x39,0x39,0x39,0x03,0x3f,0xff,0xc3,0x99,0x99,0x93,0x99,0x89,0x93,0xff,0xdf,0xef,0x83,0xf9,0x81,0x39,0x81,0xff,0xf7,0xef,0x83,0xf9,0x81,0x39,0x81,0xff,0xc7,0x93,0x83,0xf9,0x81,0x39,0x81,0xff,0xcb,0xa7,0x83,0xf9,0x81,0x39,0x81,0xff,0x93,0xff,0x83,0xf9,0x81,0x39,0x81,0xff,0xef,0xd7,0x83,0xf9,0x81,0x39,0x81,0xff,0xff,0xff,0x83,0xe9,0x81,0x2f,0x83,0xff,0xff,0xff,0x81,0x3f,0x3f,0x81,0xf7,0xcf,0xdf,0xef,0x83,0x39,0x01,0x3f,0x83,0xff,0xf7,0xef,0x83,0x39,0x01,0x3f,0x83,0xff,0xc7,0x93,0x83,0x39,0x01,0x3f,0x83,0xff,0x93,0xff,0x83,0x39,0x01,0x3f,0x83,0xff,0xdf,0xef,0xff,0xc7,0xe7,0xe7,0x81,0xff,0xf7,0xef,0xff,0xc7,0xe7,0xe7,0x81,0xff,0xc7,0x93,0xff,0xc7,0xe7,0xe7,0x81,0xff,0x93,0xff,0xc7,0xe7,0xe7,0xe7,0x81,0xff,0x9b,0x87,0x67,0x83,0x39,0x39,0x83,0xff,0xcb,0xa7,0x03,0x39,0x39,0x39,0x39,0xff,0xdf,0xef,0x83,0x39,0x39,0x39,0x83,0xff,0xf7,0xef,0x83,0x39,0x39,0x39,0x83,0xff,0xc7,0x93,0x83,0x39,0x39,0x39,0x83,0xff,0xcb,0xa7,0x83,0x39,0x39,0x39,0x83,0xff,0x93,0xff,0x83,0x39,0x39,0x39,0x83,0xff,0xff,0xe7,0xff,0x81,0xff,0xe7,0xff,0xff,0xff,0xff,0x83,0x31,0x29,0x19,0x83,0xff,0xdf,0xef,0x39,0x39,0x39,0x39,0x81,0xff,0xf7,0xef,0x39,0x39,0x39,0x39,0x81,0xff,0xc7,0x93,0xff,0x39,0x39,0x39,0x81,0xff,0x93,0xff,0x39,0x39,0x39,0x39,0x81,0xff,0xf7,0xef,0x39,0x39,0x39,0x81,0xf9,0x83,0x3f,0x3f,0x03,0x39,0x39,0x03,0x3f,0x3f,0x93,0xff,0x39,0x39,0x39,0x81,0xf9,0x83 };

static const uint16_t* drawColors;
static uint8_t* framebuffer;

static int min (int a, int b) {
    return a < b ? a : b;
}

static int max (int a, int b) {
    return a > b ? a : b;
}

static void drawPoint (uint8_t color, int x, int y) {
    int idx = (WIDTH * y + x) >> 2;
    int shift = (x & 0x3) << 1;
    int mask = 0x3 << shift;
    framebuffer[idx] = (color << shift) | (framebuffer[idx] & ~mask);
}

void w4_framebufferInit (const uint16_t* drawColors_, uint8_t* framebuffer_) {
    drawColors = drawColors_;
    framebuffer = framebuffer_;
}

void w4_framebufferClear () {
    memset(framebuffer, 0, WIDTH*HEIGHT >> 2);
}

void w4_framebufferRect (int x, int y, int width, int height) {
    // TODO(2021-09-28): Clipping
    uint8_t dc0 = *drawColors & 0xf;

    if (dc0) {
        uint8_t fillColor = dc0 - 1;
        for (int yy = y; yy < y+height; ++yy) {
            for (int xx = x; xx < x+width; ++xx) {
                drawPoint(fillColor, xx, yy);
            }
        }
    }
}

void w4_framebufferText (const char* str, int x, int y) {
    int currentX = x;
    while (*str) {
        switch (*str) {
        case 0:
            return;
        case 10:
            y += 8;
            currentX = x;
            break;
        default:
            w4_framebufferBlit(font, currentX, y, 8, 8, 0, (*str - 32) << 3, 8,
                false, false, false, false);
            currentX += 8;
            break;
        }

        ++str;
    }
}

void w4_framebufferBlit (const uint8_t* sprite, int dstX, int dstY, int width, int height,
    int srcX, int srcY, int srcStride, bool bpp2, bool flipX, bool flipY, bool rotate) {

    int clipXMin = max(0, dstX) - dstX;
    int clipYMin = max(0, dstY) - dstY;
    int clipXMax = min(width, WIDTH - dstX);
    int clipYMax = min(height, HEIGHT - dstY);
    uint16_t colors = *drawColors;

    if (rotate) {
        flipX = !flipX;
    }

    for (int row = clipYMin; row < clipYMax; ++row) {
        for (int col = clipXMin; col < clipXMax; ++col) {
            // Determine the local position on the sprite
            int sx, sy;
            if (rotate) {
                sx = row;
                sy = col;
            } else {
                sx = col;
                sy = row;
            }
            if (flipX) {
                sx = clipXMax - sx - 1;
            }
            if (flipY) {
                sy = clipYMax - sy - 1;
            }

            // Sample the sprite to get a color index
            int colorIdx;
            int x = srcX + sx, y = srcY + sy;
            if (bpp2) {
                uint8_t byte = sprite[(y * srcStride + x) >> 2];
                int shift = 6 - ((x & 0x03) << 1);
                colorIdx = (byte >> shift) & 0b11;

            } else {
                uint8_t byte = sprite[(y * srcStride + x) >> 3];
                int shift = 7 - (x & 0x07);
                colorIdx = (byte >> shift) & 0b1;
            }

            // Get the final color using the drawColors indirection
            uint8_t dc = (colors >> (colorIdx << 2)) & 0x0f;
            if (dc != 0) {
                drawPoint((dc - 1) & 0x03, dstX + col, dstY + row);
            }
        }
    }
}
