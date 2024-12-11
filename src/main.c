#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../include/engine.h"

int main() {
  
    init_engine();
    int ball_x = 5, ball_y = 5;
    int velocity_x = 1, velocity_y = 1;
    bool running = true;
    const int target_fps = 60;
    const double frame_time = 1.0 / target_fps;

    clock_t last_time = clock();

    while (running) {
        // Time management
        clock_t now = clock();
        double elapsed = (double)(now - last_time) / CLOCKS_PER_SEC;

        if (elapsed >= frame_time) {
            last_time = now;

            // Clear the framebuffer
            clear_framebuffer();
            // Move the ball
            ball_x += velocity_x;
            ball_y += velocity_y;

            // Bounce on edges
            if (ball_x <= 0 || ball_x >= SCREEN_WIDTH - 1) velocity_x = -velocity_x;
            if (ball_y <= 0 || ball_y >= SCREEN_HEIGHT - 1) velocity_y = -velocity_y;
            // Draw the ball
            draw_pixel(ball_x, ball_y, 'O');
            // Render the frame
            render_frame();
        }
    }

    shutdown_engine();
    return 0;
}



