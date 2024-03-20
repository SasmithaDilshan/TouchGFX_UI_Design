#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <gui/common/CustomKeyboard.hpp>
class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AddtrangularWave();
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

#endif // SCREEN3VIEW_HPP
