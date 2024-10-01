// how to compile is link to -lxinput
g++ -o your_program your_program.cpp -lXinput

// or use it below #include syntax to automatically link it at compile time
#pragma comment(lib, "XInput.lib")  // This automatically links XInput.lib