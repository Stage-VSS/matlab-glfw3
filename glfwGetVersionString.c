#include <mex.h>
#include <GLFW/glfw3.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs != 0)
	{
		mexErrMsgIdAndTxt("glfw:usage", "Usage: version = glfwGetVersionString()");
		return;
	}
	
	const char *version = glfwGetVersionString();
	
	plhs[0] = mxCreateString(version);	
}