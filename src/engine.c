#include <stdio.h>
#include <string.h>
#include "../include/engine.h"

static char framebuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

void init_engine() {
    // Initialize the framebuffer
    clear_framebuffer();
}

void shutdown_engine() {
    // Any cleanup code if needed
    printf("Shutting down engine...\n");
}

void clear_framebuffer() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            framebuffer[y][x] = ' ';
        }
    }
}

void draw_pixel(int x, int y, char c) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        framebuffer[y][x] = c;
    }
}

void render_frame() {
    printf("\033[2J\033[H"); // Clear screen and move cursor to the top-left
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            putchar(framebuffer[y][x]);
        }
        putchar('\n');
    }
}
