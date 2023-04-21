#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
            float yaw = -90.0f,
            float pitch = 0.0f,
            glm::vec3 target = glm::vec3(0.0f));

    glm::mat4 getViewMatrix() const;
    void processKeyboardInput(GLFWwindow *window, float deltaTime);
    float getFOV() const { return m_fov; }
    void processMouseScroll(float yOffset);
    glm::vec3 getPosition() const { return m_position; }

private:
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldUp;
    glm::vec3 m_target;
    float m_fov;

    float m_yaw;
    float m_pitch;

    void updateCameraVectors();
};