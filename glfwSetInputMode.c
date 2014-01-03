#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWwindow *window;
    int mode;
    int value;
    
    if (nrhs != 3)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetInputMode(window, mode, value)");
        return;
    }
    
    window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    mode = mxGetScalar(prhs[1]);
    value = mxGetScalar(prhs[2]);
    
    glfwSetInputMode(window, mode, value);
}