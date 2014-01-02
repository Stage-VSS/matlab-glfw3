#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWwindow *window;
    int width;
    int height;
    
    if (nrhs != 3)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetWindowSize(window, width, height)");
        return;
    }
    
    window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    width = mxGetScalar(prhs[1]);
    height = mxGetScalar(prhs[2]);
        
    glfwSetWindowSize(window, width, height);
}