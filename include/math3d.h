#ifndef MATH3D_H
#define MATH3D_H

typedef struct {
    float x, y, z, w; // w is for homogeneous coordinates
} Vec4;

typedef struct {
    float m[4][4]; // 4x4 matrix
} Mat4;

Vec4 vec4(float x, float y, float z, float w);
Vec4 mat4_mul_vec4(Mat4 mat, Vec4 v);
Mat4 mat4_identity();
Mat4 mat4_perspective(float fov, float aspect, float near, float far);
Mat4 mat4_translation(float x, float y, float z);
Mat4 mat4_rotation_y(float angle);

#endif
