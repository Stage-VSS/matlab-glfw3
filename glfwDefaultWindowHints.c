#include <mex.h>
#include "GLFW/glfw3.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 0)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwDefaultWindowHints()");
        return;
    }
    
    glfwDefaultWindowHints();
}