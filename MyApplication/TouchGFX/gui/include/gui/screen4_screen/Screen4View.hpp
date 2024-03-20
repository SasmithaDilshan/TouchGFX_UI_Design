#ifndef SCREEN4VIEW_HPP
#define SCREEN4VIEW_HPP

#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>
#include <gui/common/CustomKeyboard.hpp>
class Screen4View : public Screen4ViewBase
{
public:
    Screen4View();
    virtual ~Screen4View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AddSquarewave();
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

#endif // SCREEN4VIEW_HPP
