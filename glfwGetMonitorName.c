#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWmonitor *monitor;
    const char *name;
    
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: name = glfwGetMonitorName(monitor)");
        return;
    }
    
    monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
    
    name = glfwGetMonitorName(monitor);
    
    plhs[0] = mxCreateString(name);  
}