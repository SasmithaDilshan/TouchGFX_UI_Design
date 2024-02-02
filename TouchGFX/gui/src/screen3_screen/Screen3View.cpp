#include <gui/screen3_screen/Screen3View.hpp>
#include <cmath>
Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
void Screen3View:: AddtrangularWave()
{
    double amplitude = 10.0;
    double frequency = 0.05;  // Adjust the frequency to spread the triangular wave throughout the X-axis range
    double timeStep = 0.1;    // Adjust the time step based on your requirements

    for (float time = 0; time <= 20; time += timeStep) {
        float value = (2.0 / M_PI) * asin(sin(2 * M_PI * frequency * time));
        graph2.addDataPoint(time, amplitude * value);
    }
}
