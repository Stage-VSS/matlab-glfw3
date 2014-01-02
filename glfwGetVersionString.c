#include <mex.h>
#include "GLFW/glfw3.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    const char *version;
    
    if (nrhs != 0)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: version = glfwGetVersionString()");
        return;
    }
    
    version = glfwGetVersionString();
    
    plhs[0] = mxCreateString(version);  
}