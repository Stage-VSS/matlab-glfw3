#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWwindow *window;

    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwShowWindow(window)");
        return;
    }

    window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));

    glfwShowWindow(window);
}
