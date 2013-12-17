#include <mex.h>
#include "GLFW/glfw3.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 2)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwWindowHint(target, hint)");
        return;
    }
    
    int target = mxGetScalar(prhs[0]);
    int hint = mxGetScalar(prhs[1]);
        
    glfwWindowHint(target, hint);
}