function t = tests()
    t = functiontests(localfunctions);
end

function setupOnce(testCase)
    glfwInit();
end

function teardownOnce(testCase)
    glfwTerminate();
end

function testGlfwGetVersion(testCase)
    [major, minor, rev] = glfwGetVersion();
    
    testCase.verifyEqual(major, 3);
    testCase.verifyInstanceOf(minor, 'double');
    testCase.verifyInstanceOf(rev, 'double');
end

function testGlfwGetVersionString(testCase)
    version = glfwGetVersionString();
    
    testCase.verifyInstanceOf(version, 'char');
    testCase.verifyGreaterThan(length(version), 0);
end