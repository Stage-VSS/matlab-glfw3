#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: mode = glfwGetVideoMode(monitor)");
        return;
    }
    
    GLFWmonitor *monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
        
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    
    const char *fieldNames[] = {"width", "height", "redBits", "greenBits", "blueBits", "refreshRate"}; 
    mxArray *modeStruct = mxCreateStructMatrix(1, 1, sizeof(fieldNames) / sizeof(fieldNames[0]), fieldNames);
    mxSetField(modeStruct, 0, "width", mxCreateDoubleScalar(mode->width));
    mxSetField(modeStruct, 0, "height", mxCreateDoubleScalar(mode->height));
    mxSetField(modeStruct, 0, "redBits", mxCreateDoubleScalar(mode->redBits));
    mxSetField(modeStruct, 0, "greenBits", mxCreateDoubleScalar(mode->greenBits));
    mxSetField(modeStruct, 0, "blueBits", mxCreateDoubleScalar(mode->blueBits));
    mxSetField(modeStruct, 0, "refreshRate", mxCreateDoubleScalar(mode->refreshRate));
    
    plhs[0] = modeStruct;
}