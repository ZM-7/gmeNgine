#include <math.h>
#include "../include/engine.h"
#include "../include/math3d.h"

int main() {
    init_engine();

    Vec4 triangle[3] = {
        vec4(0.0f, 1.0f, 0.0f, 1.0f),
        vec4(-1.0f, -1.0f, 0.0f, 1.0f),
        vec4(1.0f, -1.0f, 0.0f, 1.0f)
    };

    Mat4 projection = mat4_perspective(M_PI / 4.0f, (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);
    Mat4 translation = mat4_translation(0.0f, 0.0f, -3.0f);
  int running = 1;
    while (running == 1) {

        for (int i = 0; i < 3; i++) {
            Vec4 vertex = mat4_mul_vec4(translation, triangle[i]);
            vertex = mat4_mul_vec4(projection, vertex);

            // Perspective divide (convert from homogeneous to 3D space)
            vertex.x /= vertex.w;
            vertex.y /= vertex.w;

            // Map to screen space
            int screen_x = (int)((vertex.x + 1.0f) * 0.5f * SCREEN_WIDTH);
            int screen_y = (int)((1.0f - (vertex.y + 1.0f) * 0.5f) * SCREEN_HEIGHT);

            draw_pixel(screen_x, screen_y, 'e', vertex.z);
        }

        render_frame();
    }

    shutdown_engine();
    return 0;
}
