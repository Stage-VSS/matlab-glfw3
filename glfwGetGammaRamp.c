#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

mxArray* toMatrix(unsigned short *array, unsigned int size)
{
    mxArray *matrix;
    double *pointer;
    mwSize i;
    
    matrix = mxCreateNumericMatrix(1, size, mxDOUBLE_CLASS, mxREAL);
    pointer = mxGetPr(matrix);
    for (i = 0; i < size; i++)
    {
        pointer[i] = array[i];
    }
    
    return matrix;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWmonitor *monitor;
    const GLFWgammaramp *ramp;
    const char *fieldNames[] = {"red", "green", "blue", "size"};
    mxArray *rampStruct;
    
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: ramp = glfwGetGammaRamp(monitor)");
        return;
    }
    
    monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
        
    ramp = glfwGetGammaRamp(monitor);
    
    rampStruct = mxCreateStructMatrix(1, 1, sizeof(fieldNames) / sizeof(fieldNames[0]), fieldNames);
    mxSetField(rampStruct, 0, "red", toMatrix(ramp->red, ramp->size));
    mxSetField(rampStruct, 0, "green", toMatrix(ramp->green, ramp->size));
    mxSetField(rampStruct, 0, "blue", toMatrix(ramp->blue, ramp->size));
    mxSetField(rampStruct, 0, "size", mxCreateDoubleScalar(ramp->size));
    
    plhs[0] = rampStruct;
}