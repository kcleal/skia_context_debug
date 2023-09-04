#include <GL/gl.h>
#include <GL/glx.h>
#include <GLFW/glfw3.h>

#define SK_GL
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkCanvas.h"

#include <iostream>

GrDirectContext *sContext = nullptr;
SkSurface *sSurface = nullptr;


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

    GLFWwindow* window = glfwCreateWindow(800, 400, "GL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    int fb_height, fb_width;
    glfwGetFramebufferSize(window, &fb_width, &fb_height);
    sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();

    if (!interface || !interface->validate()) {
        std::cerr << "Error: skia GrGLInterface was not valid" << std::endl;
    }

    glfwTerminate();
    return 0;
}



