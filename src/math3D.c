#include <math.h>
#include "../include/math3d.h"

// Vector utility
Vec4 vec4(float x, float y, float z, float w) {
    return (Vec4){x, y, z, w};
}

// Matrix multiplication with a vector
Vec4 mat4_mul_vec4(Mat4 mat, Vec4 v) {
    Vec4 result = {0};
    result.x = mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z + mat.m[0][3] * v.w;
    result.y = mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z + mat.m[1][3] * v.w;
    result.z = mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z + mat.m[2][3] * v.w;
    result.w = mat.m[3][0] * v.x + mat.m[3][1] * v.y + mat.m[3][2] * v.z + mat.m[3][3] * v.w;
    return result;
}

// Identity matrix
Mat4 mat4_identity() {
    Mat4 mat = {0};
    for (int i = 0; i < 4; i++) {
        mat.m[i][i] = 1.0f;
    }
    return mat;
}

// Perspective projection matrix
Mat4 mat4_perspective(float fov, float aspect, float near, float far) {
    Mat4 mat = {0};
    float tan_half_fov = tanf(fov / 2.0f);
    mat.m[0][0] = 1.0f / (aspect * tan_half_fov);
    mat.m[1][1] = 1.0f / tan_half_fov;
    mat.m[2][2] = -(far + near) / (far - near);
    mat.m[2][3] = -1.0f;
    mat.m[3][2] = -(2.0f * far * near) / (far - near);
    return mat;
}

// Translation matrix
Mat4 mat4_translation(float x, float y, float z) {
    Mat4 mat = mat4_identity();
    mat.m[0][3] = x;
    mat.m[1][3] = y;
    mat.m[2][3] = z;
    return mat;
}

// Rotation matrix around Y-axis
Mat4 mat4_rotation_y(float angle) {
    Mat4 mat = mat4_identity();
    mat.m[0][0] = cosf(angle);
    mat.m[0][2] = sinf(angle);
    mat.m[2][0] = -sinf(angle);
    mat.m[2][2] = cosf(angle);
    return mat;
}
