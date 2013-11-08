#include <mex.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 3)
    {
        mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetWindowSize(window, width, height)");
        return;
    }
    
    GLFWwindow *window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
    int width = mxGetScalar(prhs[1]);
    int height = mxGetScalar(prhs[2]);
        
    glfwSetWindowSize(window, width, height);
}