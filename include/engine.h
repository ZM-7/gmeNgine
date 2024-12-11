#ifndef ENGINE_H
#define ENGINE_H

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

void init_engine();
void shutdown_engine();
void clear_framebuffer();
void draw_pixel(int x, int y, char , float depth);
void render_frame();

#endif
