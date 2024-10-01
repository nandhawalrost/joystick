#include <Windows.h>
#include <Xinput.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib> // For system()

void checkControllerInput() {
    XINPUT_STATE state;
    ZeroMemory(&state, sizeof(XINPUT_STATE));

    // Get the state of the controller (controller index 0 for the first one)
    if (XInputGetState(0, &state) == ERROR_SUCCESS) {
        // Controller is connected
        std::cout << "Controller connected!\n";

        // Buttons: Check if a specific button is pressed
        if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
            std::cout << "A button pressed\n";
        }
        if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {
            std::cout << "B button pressed\n";
        }

        std::cout << "Left thumbstick X: " << state.Gamepad.sThumbLX << "\n";
        std::cout << "Left thumbstick Y: " << state.Gamepad.sThumbLY << "\n";

        std::cout << "Left thumbstick X: " << state.Gamepad.sThumbRX << "\n";
        std::cout << "Left thumbstick Y: " << state.Gamepad.sThumbRY << "\n";

        std::cout <<"Left and Right trigger: " << static_cast<int>(state.Gamepad.bLeftTrigger) <<"," << static_cast<int>(state.Gamepad.bRightTrigger) << "\n";
    } else {
        std::cout << "Controller not connected!\n";
    }
}

int main() {
    while (true) {
      checkControllerInput();
      // std::this_thread::sleep_for(std::chrono::milliseconds(100));
      system("CLS");
    }
    return 0;
}
