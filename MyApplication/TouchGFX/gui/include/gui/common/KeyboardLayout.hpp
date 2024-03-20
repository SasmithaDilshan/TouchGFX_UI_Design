#ifndef KEYBOARD_LAYOUT
#define KEYBOARD_LAYOUT

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/hal/Types.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include "BitmapDatabase.hpp"

using namespace touchgfx;

/**
 * Array specifying the keys used in the CustomKeyboard.
 */
static const Keyboard::Key keyArray[11] =
{
    { 1, Rect(16, 41,44, 26), BITMAP_CARD_ID },
    { 2, Rect(16 + 70, 41, 44, 26), BITMAP_CARD_ID},
    { 3, Rect(16 + 70 * 2, 42, 44, 26), BITMAP_CARD_ID},
    { 4, Rect(16,86, 44, 26), BITMAP_CARD_ID},
    { 5, Rect(16 + 70, 86, 44, 26), BITMAP_CARD_ID},
    { 6, Rect(16 + 70*2, 86, 44, 26), BITMAP_CARD_ID},
    { 7, Rect(16 ,130, 44, 26), BITMAP_CARD_ID},
    { 8, Rect(16 + 70, 130, 44, 26), BITMAP_CARD_ID},
    { 9, Rect(16 + 70*2, 130, 44, 26), BITMAP_CARD_ID},
    { 10, Rect(16 + 70, 175, 44, 26), BITMAP_CARD_ID},
    { 11, Rect(16, 175, 44, 26), BITMAP_CARD_ID},
   
  
};

/**
 * Callback areas for the special buttons on the CustomKeyboard.
 */
static Keyboard::CallbackArea callbackAreas[1] =
{
    {Rect(160, 180, 40, 20), 0,BITMAP_BACKSPACE_ID}   // backspace
   
};

/**
 * The layout for the CustomKeyboard.
 */
static const Keyboard::Layout layout =
{
    BITMAP_KEYBOARD_ID ,
    keyArray,
    11,
    callbackAreas,
    1,
    Rect(16, 5, 184, 30),
    TypedText(T_ENTEREDTEXT),
    0x050505,
    Typography::KEYBOARD,
    0
};

#endif
