#pragma once

#include <vector>
#include <glad/glad.h>
#include <vertex.h>
#include <shader.h>
#include <camera.h>
#include <mesh.h>
#include <light.h>


class NormalMesh {
    public:
        NormalMesh(const std::vector<std::vector<Vertex>>& verticesGrid,std::vector<Light*> lights  ,Camera* camera, GLenum drawMode);
        void draw(Shader* shader,float ratio ) const;
        Mesh createNormalVisualizerMesh(const std::vector<std::vector<Vertex>>& surfaceVertices, float normalLength);

    private:
        std::vector<Vertex> createVertices(const std::vector<std::vector<Vertex>>& verticesGrid);
        std::vector<GLuint> createIndices(const std::vector<std::vector<Vertex>>& verticesGrid);
        void updateNormals();
        void updateVBO(const std::vector<Vertex>& vertices);

        std::vector<Vertex> m_vertices;
        std::vector<std::vector<Vertex>> m_verticesGrid;
        std::vector<GLuint> m_indices;

        GLuint VAO;
        GLuint VBO;
        GLuint EBO;

        GLenum drawMode;
        size_t numVertices;
        size_t numIndices;

        Camera* camera;
        std::vector<Light*> m_lights;
};