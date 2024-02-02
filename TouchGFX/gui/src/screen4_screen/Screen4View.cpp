#include <gui/screen4_screen/Screen4View.hpp>
#include <cmath>
Screen4View::Screen4View()
{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}
void Screen4View :: AddSquarewave()
{
    double amplitude = 10;
    double frequency = 0.05;  // Adjust the frequency to control the number of oscillations within the X-axis range
    double timeStep = 0.1;    // Adjust the time step based on your requirements

    for (float time = 0; time <= 20; time += timeStep) {
        float value = sin(2 * M_PI * frequency * time) >= 0 ? amplitude : -amplitude;
        graph3.addDataPoint(time, value);
    }
}