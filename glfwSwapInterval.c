#include <mex.h>
#include <GLFW/glfw3.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 1)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSwapInterval(interval)");
        return;
    }
    
    int interval = mxGetScalar(prhs[0]);
        
    glfwSwapInterval(interval);
}