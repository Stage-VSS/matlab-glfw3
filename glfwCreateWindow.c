#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int width;
    int height;
    size_t titleLen;
    char *title;
    GLFWmonitor *monitor;
    GLFWwindow *share;
    GLFWwindow *window;
    mxArray *windowAddr;
    
    if (nrhs != 5)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: window = glfwCreateWindow(width, height, title, monitor, share)");
        return;
    }
    
    width = mxGetScalar(prhs[0]);
    height = mxGetScalar(prhs[1]);
    
    titleLen = mxGetN(prhs[2]) * sizeof(mxChar) + 1;
    title = mxMalloc(titleLen);
    mxGetString(prhs[2], title, (mwSize)titleLen);
        
    monitor = NULL;
    if (!mxIsEmpty(prhs[3]))
    {
        monitor = (GLFWmonitor *)*((uint64_t *)mxGetData(prhs[3])); 
    }
    
    share = NULL;
    if (!mxIsEmpty(prhs[4]))
    {
        share = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[4]));
    }
    
    window = glfwCreateWindow(width, height, title, monitor, share);
    
    windowAddr = mxCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
    *((uint64_t *)mxGetData(windowAddr)) = (uint64_t)window;
    
    plhs[0] = windowAddr;
}