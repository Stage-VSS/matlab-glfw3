#include <mex.h>
#include "GLFW/glfw3.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double time;
    
    if (nrhs != 0)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: time = glfwGetTime()");
        return;
    }
    
    time = glfwGetTime();
    
    plhs[0] = mxCreateDoubleScalar(time);
}