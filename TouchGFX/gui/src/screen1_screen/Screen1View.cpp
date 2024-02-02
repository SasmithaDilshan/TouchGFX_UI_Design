#include <gui/screen1_screen/Screen1View.hpp>
#include <cmath>

Screen1View::Screen1View()
{
    
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View:: AddGraph()
{
    double amplitude = 5.0;
    double frequency = 0.05;  //keep frequency as a fixed value 
    double timeStep = 0.1;
    

    for (float time = 0; time <= 1000; time += timeStep) {
        float value = amplitude * sin(2 * M_PI * frequency * time);
        graph1.addDataPoint(time, value);
    }
}






