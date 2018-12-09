#ifndef HELLO_TRIANGLE_APPLICATION_H
#define HELLO_TRIANGLE_APPLICATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <optional>

class HelloTriangleApplication {
public:
    void run();

private:
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
    GLFWwindow* window = nullptr;
    VkInstance instance;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkDebugUtilsMessengerEXT callback;
    VkSurfaceKHR surface;

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData
    );
    void setupDebugCallback();

    std::vector<VkPhysicalDevice> getPhysicalDevices();
    bool isDeviceSuitable(VkPhysicalDevice device);
    void pickPhysicalDevice();
    void createLogicalDevice();

}; // class HelloTriangleApplication

#endif // HELLO_TRIANGLE_APPLICATION_H
