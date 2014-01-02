#include <mex.h>
#include "GLFW/glfw3.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int major;
    int minor;
    int rev;
    
    if (nrhs != 0)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: [major, minor, rev] = glfwGetVersion()");
        return;
    }
    
    glfwGetVersion(&major, &minor, &rev);
    
    plhs[0] = mxCreateDoubleScalar(major);
    plhs[1] = mxCreateDoubleScalar(minor);
    plhs[2] = mxCreateDoubleScalar(rev);
}