#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: [width, height] = glfwGetWindowSize(window)");
        return;
    }
    
    GLFWwindow *window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    
    int width;
    int height;
    glfwGetWindowSize(window, &width, &height);
    
    plhs[0] = mxCreateDoubleScalar(width);
    plhs[1] = mxCreateDoubleScalar(height);
}