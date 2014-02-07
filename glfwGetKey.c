#include <mex.h>
#include "GLFW/glfw3.h"
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    GLFWwindow *window;
    int key;
    int state;
    
    if (nrhs != 2)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: state = glfwGetKey(window, key)");
        return;
    }
    
    window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    key = mxGetScalar(prhs[1]);
    
    state = glfwGetKey(window, key);
    
    plhs[0] = mxCreateDoubleScalar(state);
}