#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

unsigned short* toUshortArray(mxArray *matrix)
{
    double *pointer;
    unsigned short *array;
    size_t size;
    int i;
    
    pointer = mxGetPr(matrix);
    size = mxGetN(matrix);
    array = mxMalloc(size * sizeof(unsigned short));
    
    for (i = 0; i < size; i++)
    {
        array[i] = (unsigned short)pointer[i];
    }
    
    return array;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWmonitor *monitor;
    const mxArray *rampStruct;
    mxArray *red;
    mxArray *green;
    mxArray *blue;
    size_t size;
    GLFWgammaramp ramp;
    
    if (nrhs != 2)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetGammaRamp(monitor, ramp)");
        return;
    }
    
    monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[0]));
    rampStruct = prhs[1];
    
    red = mxGetField(rampStruct, 0, "red");
    if (red == NULL)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Ramp does not contain a red field");
        return;
    }
    
    green = mxGetField(rampStruct, 0, "green");
    if (green == NULL)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Ramp does not contain a green field");
        return;
    }
    
    blue = mxGetField(rampStruct, 0, "blue");
    if (blue == NULL)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Ramp does not contain a blue field");
        return;
    }
    
    size = mxGetN(red);
    if (size != mxGetN(green) || size != mxGetN(blue))
    {
        mexErrMsgIdAndTxt("glfw:usage", "Red, green, and blue must be of equal length");
        return;
    }
    
    ramp.red = toUshortArray(red);
    ramp.green = toUshortArray(green);
    ramp.blue = toUshortArray(blue);
    ramp.size = size;
    
    glfwSetGammaRamp(monitor, &ramp);
    
    mxFree(ramp.red);
    mxFree(ramp.green);
    mxFree(ramp.blue);
}