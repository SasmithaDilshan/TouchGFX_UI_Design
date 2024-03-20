#include <gui/screen3_screen/Screen3View.hpp>
#include <cmath>
Screen3View::Screen3View()
{
    keyboard.setPosition(144,35,220,220);
    add(keyboard);
    keyboard.setVisible(false);
    keyboard.invalidate();
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
void Screen3View:: Frequencyclicked()
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
void Screen3View:: Amplitudeclicked()
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
void Screen3View:: OffsetClicked()
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
void Screen3View:: okclicked()
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
void Screen3View:: exitclicked()
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