#include "defines.h"
#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch, glm::vec3 target)
    : m_position(position), m_worldUp(up), m_yaw(yaw), m_pitch(pitch), m_target(target),m_fov(45.0f) {
    m_front = glm::normalize(target - position);
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::processKeyboardInput(GLFWwindow *window, float deltaTime) {
    float cameraSpeed = 2.5f * deltaTime;
    float rotationSpeed = 50.0f * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        m_position += cameraSpeed * m_up;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        m_position -= cameraSpeed * m_up;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        m_position -= glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        m_position += glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
    // Update pitch and yaw values based on arrow key input
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        m_pitch += rotationSpeed;
        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        m_pitch -= rotationSpeed;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        m_yaw -= rotationSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        m_yaw += rotationSpeed;
    }

    // Update camera vectors based on the updated pitch and yaw values
    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_up = glm::normalize(glm::cross(m_right, m_front));

    // Ensure that the up vector stays perpendicular to the front vector
    if (abs(glm::dot(m_up, m_front)) > 0.99f) {
        m_up = glm::normalize(glm::cross(m_front, m_right));
    }
}
void Camera::processMouseScroll(float yOffset) {
    m_fov -= yOffset;
    if (m_fov < 1.0f) {
        m_fov = 1.0f;
    }
    if (m_fov > 45.0f) {
        m_fov = 45.0f;
    }
}

