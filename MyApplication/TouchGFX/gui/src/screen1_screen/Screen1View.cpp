#include <gui/screen1_screen/Screen1View.hpp>
#include <cmath>

Screen1View::Screen1View()
{
    keyboard.setPosition(144,35,220,220);
    add(keyboard);
    keyboard.setVisible(false);
    keyboard.invalidate();
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
void Screen1View:: Frequencyclicked()
{
	 keyboard.setVisible(true);
	 keyboard.invalidate();
	 ok.setVisible(true);
	 ok.invalidate();
	 exit.setVisible(true);
	 exit.invalidate();
	 backbutton.setVisible(false);
	 backbutton.invalidate();
	 freq = 1;
	 amp =0;
	 offset = 0;
}
void Screen1View:: Amplitudeclicked()
{
	 keyboard.setVisible(true);
	 keyboard.invalidate();
	 ok.setVisible(true);
	 ok.invalidate();
	 exit.setVisible(true);
	 exit.invalidate();
	 backbutton.setVisible(false);
	 backbutton.invalidate();
	 freq = 0;
	 amp =1;
	 offset = 0;
}
void Screen1View:: OffsetClicked()
{
	 keyboard.setVisible(true);
	 keyboard.invalidate();
	 ok.setVisible(true);
	 ok.invalidate();
	 exit.setVisible(true);
	 exit.invalidate();
	 backbutton.setVisible(false);
	 backbutton.invalidate();
	 freq = 0;
	 amp =0;
	 offset = 1;
}
void Screen1View:: okclicked()
{
	 keyboard.setVisible(false);
	 keyboard.invalidate();
	 ok.setVisible(false);
	 ok.invalidate();
	 exit.setVisible(false);
	 exit.invalidate();
	 backbutton.setVisible(true);
	 backbutton.invalidate();
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
void Screen1View:: exitclicked()
{
	 keyboard.setVisible(false);
	 keyboard.invalidate();
	 ok.setVisible(false);
	 ok.invalidate();
	 exit.setVisible(false);
	 exit.invalidate();
     backbutton.setVisible(true);
	 backbutton.invalidate();
	 freq =0;
	 amp=0;
	 offset=0;
}




