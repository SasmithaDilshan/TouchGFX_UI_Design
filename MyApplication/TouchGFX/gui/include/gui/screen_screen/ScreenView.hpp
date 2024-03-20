#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <gui_generated/screen_screen/ScreenViewBase.hpp>
#include <gui/screen_screen/ScreenPresenter.hpp>

class ScreenView : public ScreenViewBase
{
public:
    ScreenView();
    virtual ~ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int16_t addStart;
    int16_t addEnd;
};

#endif // SCREENVIEW_HPP
