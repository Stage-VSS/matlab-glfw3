#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWmonitor *monitor;
    int width;
    int height;
    
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: [width, height] = glfwGetMonitorPhysicalSize(monitor)");
        return;
    }
    
    monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
    
    glfwGetMonitorPhysicalSize(monitor, &width, &height);
    
    plhs[0] = mxCreateDoubleScalar(width);
    plhs[1] = mxCreateDoubleScalar(height);
}