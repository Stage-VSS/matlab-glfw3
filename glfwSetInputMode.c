#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWmonitor *monitor;
    int mode;
    int value;
    
    if (nrhs != 3)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetInputMode(monitor, mode, value)");
        return;
    }
    
    monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
    mode = mxGetScalar(prhs[1]);
    value = mxGetScalar(prhs[2]);
    
    glfwSetInputMode(monitor, mode, value);
}