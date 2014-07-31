#include <mex.h>
#include "GLFW/glfw3.h"

void cleanup()
{
	glfwTerminate();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int result;
    
    if (nrhs != 0)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwInit()");
        return;
    }
    mexAtExit(cleanup);
	
    result = glfwInit();
    if (result == GL_FALSE)
    {
        mexErrMsgIdAndTxt("glfw:failed", "An error occurred");
        return;
    }
}