void renderScene() {
    // Bind a vertex array object (VAO)
    bindVertexArray(vaoID);

    // Use a shader program
    useProgram(shaderProgramID);

    // Draw the primitives
    drawArrays(GL_TRIANGLES, 0, vertexCount);

    // Unbind the VAO
    bindVertexArray(0);
}
