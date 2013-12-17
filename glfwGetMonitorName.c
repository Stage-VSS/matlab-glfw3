#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: name = glfwGetMonitorName(monitor)");
        return;
    }
    
    GLFWmonitor *monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
    
    const char *name = glfwGetMonitorName(monitor);
    
    plhs[0] = mxCreateString(name);  
}