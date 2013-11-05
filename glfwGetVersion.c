#include <mex.h>
#include <GLFW/glfw3.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs < 0 || nrhs > 0)
	{
		mexErrMsgIdAndTxt("glfw:usage", "Usage: [major, minor, rev] = glfwGetVersion()");
		return;
	}
	
	int major;
	int minor;
	int rev;
	glfwGetVersion(&major, &minor, &rev);
	
	plhs[0] = mxCreateDoubleScalar(major);
	plhs[1] = mxCreateDoubleScalar(minor);
	plhs[2] = mxCreateDoubleScalar(rev);
}