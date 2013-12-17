#include <mex.h>
#include "GLFW/glfw3.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 0)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwInit()");
        return;
    }
    
    int result = glfwInit();
    if (result == GL_FALSE)
    {
        mexErrMsgIdAndTxt("glfw:failed", "An error occurred");
        return;
    }
}