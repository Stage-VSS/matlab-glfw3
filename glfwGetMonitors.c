#include <mex.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs != 0)
	{
		mexErrMsgIdAndTxt("glfw:usage", "Usage: monitors = glfwGetMonitors()");
		return;
	}
	
	int count;
	GLFWmonitor **monitors = glfwGetMonitors(&count);
	
	mxArray *monitorAddrs = mxCreateNumericMatrix(1, count, mxUINT64_CLASS, mxREAL);
	uint64_t *addrs = (uint64_t *)mxGetData(monitorAddrs);
	for(int i = 0; i < count; i++)
	{
		addrs[i] = (uint64_t)monitors[i];
	}
	
	plhs[0] = monitorAddrs;
}