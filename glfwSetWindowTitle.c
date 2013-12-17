#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 2)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetWindowTitle(window, title)");
        return;
    }
    
    GLFWwindow *window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    
    size_t titleLen = mxGetN(prhs[1]) * sizeof(mxChar) + 1;
    char *title = mxMalloc(titleLen);
    mxGetString(prhs[1], title, (mwSize)titleLen);
        
    glfwSetWindowTitle(window, title);
}