#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 5)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: window = glfwCreateWindow(width, height, title, monitor, share)");
        return;
    }
    
    int width = mxGetScalar(prhs[0]);
    int height = mxGetScalar(prhs[1]);
    
    size_t titleLen = mxGetN(prhs[2]) * sizeof(mxChar) + 1;
    char *title = mxMalloc(titleLen);
    mxGetString(prhs[2], title, (mwSize)titleLen);
        
    GLFWmonitor *monitor = NULL;
    if (!mxIsEmpty(prhs[3]))
    {
        monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[3])); 
    }
    
    GLFWwindow *share = NULL;
    if (!mxIsEmpty(prhs[4]))
    {
        share = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[4]));
    }
    
    GLFWwindow *window = glfwCreateWindow(width, height, title, monitor, share);
    
    mxArray *windowAddr = mxCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
    *((uint64_t *)mxGetData(windowAddr)) = (uint64_t)window;
    
    plhs[0] = windowAddr;
}