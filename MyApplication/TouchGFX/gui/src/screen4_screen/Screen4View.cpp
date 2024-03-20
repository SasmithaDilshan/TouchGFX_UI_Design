#include <gui/screen4_screen/Screen4View.hpp>
#include <cmath>
Screen4View::Screen4View()
{
    keyboard.setPosition(144,35,220,220);
    add(keyboard);
    keyboard.setVisible(false);
    keyboard.invalidate();
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
void Screen4View:: Frequencyclicked()
{
	 keyboard.setVisible(true);
	 keyboard.invalidate();
	 ok.setVisible(true);
	 ok.invalidate();
	 exit.setVisible(true);
	 exit.invalidate();
	 backbutton1.setVisible(false);
	 backbutton1.invalidate();
	 freq = 1;
	 amp =0;
	 offset = 0;
}
void Screen4View:: Amplitudeclicked()
{
	 keyboard.setVisible(true);
	 keyboard.invalidate();
	 ok.setVisible(true);
	 ok.invalidate();
	 exit.setVisible(true);
	 exit.invalidate();
	 backbutton1.setVisible(false);
	 backbutton1.invalidate();
	 freq = 0;
	 amp =1;
	 offset = 0;
}
void Screen4View:: OffsetClicked()
{
	 keyboard.setVisible(true);
	 keyboard.invalidate();
	 ok.setVisible(true);
	 ok.invalidate();
	 exit.setVisible(true);
	 exit.invalidate();
	 backbutton1.setVisible(false);
	 backbutton1.invalidate();
	 freq = 0;
	 amp =0;
	 offset = 1;
}
void Screen4View:: okclicked()
{
	 keyboard.setVisible(false);
	 keyboard.invalidate();
	 ok.setVisible(false);
	 ok.invalidate();
	 exit.setVisible(false);
	 exit.invalidate();
	 backbutton1.setVisible(true);
	 backbutton1.invalidate();
	 if (freq){
		 Unicode::strncpy(frequencyBuffer,keyboard.getBuffer(),FREQUENCY_SIZE);
		 frequency.invalidate();
	 }
	 if (amp){
		 Unicode::strncpy(AmplitudeBuffer,keyboard.getBuffer(),AMPLITUDE_SIZE);
		 Amplitude.invalidate();
	 }
	 if (offset){
		 Unicode::strncpy(OffsetBuffer,keyboard.getBuffer(),OFFSET_SIZE);
		 Offset.invalidate();
	 }
	 keyboard.clearBuffer();
}
void Screen4View:: exitclicked()
{
	 keyboard.setVisible(false);
	 keyboard.invalidate();
	 ok.setVisible(false);
	 ok.invalidate();
	 exit.setVisible(false);
	 exit.invalidate();
     backbutton1.setVisible(true);
	 backbutton1.invalidate();
	 freq =0;
	 amp=0;
	 offset=0;
}