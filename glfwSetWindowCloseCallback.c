#include <mex.h>
#include <GLFW/glfw3.h>
#include <stdint.h>
#include "uthash.h"

typedef struct
{
	GLFWwindow *window;
	mxArray *func;
	UT_hash_handle hh;
} callback;

callback *callbacks = NULL;

void cbfun(GLFWwindow *window)
{
	callback *cb;
	HASH_FIND(hh, callbacks, &window, sizeof(GLFWwindow *), cb);
	if (cb == NULL)
		return;
	
	mxArray *rhs[2];	
	rhs[0] = cb->func;
	mxArray *windowAddr = mxCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
	*((uint64_t *)mxGetData(windowAddr)) = (uint64_t)cb->window;
	rhs[1] = windowAddr;	
	
	mexCallMATLAB(0, NULL, 2, rhs, "feval");
}

void cleanup()
{
	callback *cb, *tmp;
	HASH_ITER(hh, callbacks, cb, tmp) 
	{
		HASH_DEL(callbacks, cb);
		mxDestroyArray(cb->func);
		free(cb);
	}
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs != 2)
	{
		mexErrMsgIdAndTxt("glfw:usage", "Usage: glfwSetWindowCloseCallback(window, cbfun)");
		return;
	}
	mexAtExit(cleanup);
	
	callback *cb;
	cb = malloc(sizeof(callback));
	cb->window = (GLFWwindow *)*((uint64_t *)mxGetData(prhs[0]));
	cb->func = mxDuplicateArray((mxArray *)prhs[1]);
	mexMakeArrayPersistent(cb->func);
	
	callback *replaced;
	HASH_REPLACE(hh, callbacks, window, sizeof(GLFWwindow *), cb, replaced);
	if (replaced != NULL)
	{
		mxDestroyArray(replaced->func);
		free(replaced);
	}
	
	glfwSetWindowCloseCallback(cb->window, cbfun);
}