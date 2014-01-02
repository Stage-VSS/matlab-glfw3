#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWwindow *window;
    size_t titleLen;
    char *title;
    
    if (nrhs != 2)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetWindowTitle(window, title)");
        return;
    }
    
    window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    
    titleLen = mxGetN(prhs[1]) * sizeof(mxChar) + 1;
    title = mxMalloc(titleLen);
    mxGetString(prhs[1], title, (mwSize)titleLen);
        
    glfwSetWindowTitle(window, title);
}