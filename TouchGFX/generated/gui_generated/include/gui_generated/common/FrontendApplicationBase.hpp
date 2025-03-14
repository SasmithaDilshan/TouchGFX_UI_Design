/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoScreenScreenNoTransition();
    }

    // Screen
    void gotoScreenScreenNoTransition();

    // Screen1
    void gotoScreen1ScreenNoTransition();

    // Screen3
    void gotoScreen3ScreenNoTransition();

    // Screen4
    void gotoScreen4ScreenNoTransition();

    // Screen5
    void gotoScreen5ScreenCoverTransitionNorth();

    void gotoScreen5ScreenSlideTransitionEast();

    void gotoScreen5ScreenCoverTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen
    void gotoScreenScreenNoTransitionImpl();

    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();

    // Screen3
    void gotoScreen3ScreenNoTransitionImpl();

    // Screen4
    void gotoScreen4ScreenNoTransitionImpl();

    // Screen5
    void gotoScreen5ScreenCoverTransitionNorthImpl();

    void gotoScreen5ScreenSlideTransitionEastImpl();

    void gotoScreen5ScreenCoverTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
