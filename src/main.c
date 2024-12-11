#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../include/engine.h"

int main() {
    init_engine();

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

            // Draw a simple object (e.g., a static rectangle)
            for (int y = 5; y < 10; y++) {
                for (int x = 10; x < 30; x++) {
                    draw_pixel(x, y, '#');
                }
            }

            // Render the frame
            render_frame();
        }
    }

    shutdown_engine();
    return 0;
}
