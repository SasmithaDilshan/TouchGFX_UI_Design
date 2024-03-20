#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui/common/CustomKeyboard.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AddGraph();
    virtual void Frequencyclicked();
    virtual void okclicked();
    virtual void exitclicked();
    virtual void Amplitudeclicked();
    virtual void OffsetClicked();

    
protected:
    CustomKeyboard keyboard;
    int freq;
    int amp;
    int offset;
};

#endif // SCREEN1VIEW_HPP
