    #include <gui/screen_screen/ScreenView.hpp>

ScreenView::ScreenView()
    : addStart(1), addEnd(2)
{}

void ScreenView::setupScreen()
{
    ScreenViewBase::setupScreen();
}

void ScreenView::tearDownScreen()
{
    ScreenViewBase::tearDownScreen();
}
void ScreenView::handleTickEvent()
{

    if (!login.isMoveAnimationRunning())
    {
        
        if (circle.getArcStart() + 340 == circle.getArcEnd())
        {
            addStart = 2;
            addEnd = 1;
        }
        else if (circle.getArcStart() + 20 == circle.getArcEnd())
        {
            addStart = 1;
            addEnd = 2;
        }
        circle.updateArc(circle.getArcStart() + addStart, circle.getArcEnd() + addEnd);
    }
}
