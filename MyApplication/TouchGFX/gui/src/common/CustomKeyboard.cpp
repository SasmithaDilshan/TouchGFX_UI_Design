#include <gui/common/CustomKeyboard.hpp>
#include <string.h>
#include <touchgfx/Color.hpp>

CustomKeyboard::CustomKeyboard() : keyboard(),
    backspacePressed(this, &CustomKeyboard::backspacePressedHandler),
    keyPressed(this, &CustomKeyboard::keyPressedhandler),
    firstCharacterEntry(false)
{

    layout.callbackAreaArray[0].callback = &backspacePressed;

    keyboard.setLayout(&layout);
    keyboard.setKeyListener(keyPressed);
    keyboard.setPosition(0, 0, 220, 220);
    keyboard.setTextIndentation();
    keyboard.setKeymappingList(&keyMappingListNumLower);
    //Allocate the buffer associated with keyboard.
    memset(buffer, 0, sizeof(buffer));
    keyboard.setBuffer(buffer, BUFFER_SIZE);


    firstCharacterEntry = true;


  

    add(keyboard);

}


void CustomKeyboard::backspacePressedHandler()
{
    uint16_t pos = keyboard.getBufferPosition();
    if (pos > 0)
    {
        //Delete the previous entry in the buffer and decrement the position.
        buffer[pos - 1] = 0;
        keyboard.setBufferPosition(pos - 1);

        //Change keymappings if we have reached the first position.
        if (1 == pos)
        {
            firstCharacterEntry = true;
        }
    }
}




void CustomKeyboard::keyPressedhandler(Unicode::UnicodeChar keyChar)
{
    // After the first keypress, the keyboard will shift to lowercase.
    if (firstCharacterEntry && keyChar != 0)
    {
        firstCharacterEntry = false;
    }
}

void CustomKeyboard::setTouchable(bool touch)
{
    Container::setTouchable(touch);
    keyboard.setTouchable(touch);
}
Unicode::UnicodeChar* CustomKeyboard::getBuffer()
{
    return keyboard.getBuffer();
}
void CustomKeyboard::clearBuffer()
{
    memset(buffer,0,BUFFER_SIZE+1);
    keyboard.setBufferPosition(0);
    firstCharacterEntry = true;

}
