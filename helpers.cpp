//using namespace std;
#include <QMessageBox>
#include <QString>

bool char_to_hex(char input, char & output)
{
        //Note: assumes memory already allocated

        //Translate the ascii character to a 4 bit hex number 0x30-0x39 are 0-9, and 0x61-0x66 are a-f

        char lnib, rnib;

        lnib = (input & 0xf0) >> 4;
        rnib = input & 0x0f;

        if((lnib == 0x3) && (rnib < 0xa))
        {	// If it's between 0 and 9
                output = rnib;
        }
        else if((input >= 0x61) && (input <= 0x66))
        {	// if it's a-f
                output = 0x9 + rnib;
        }
        else
        {
                return false;
        }

        return true;
}

bool hex_to_char(char input, char output[2])
{
    output[0] = input & 0x0f;
    output[1] = (input & 0xf0) >> 4;

    for(int i = 0; i < 2; i++)
    {
        char res = output[i];

        // If it's less than 10, display a number
        if(res < 0xA)
            res = 0x30 + res;

        // But if it's 10 or over, display a character A-F
        else
            res = 0x41 + (res - 0xA);

        output[i] = res;
    }

    return true;
}

char combine_nibbles(char ln, char rn)
{
    char output = 0x00;

    output |= rn;
    output |= (ln << 4);

    return output;
}

void show_message(const QString & Message)
{
        QMessageBox msgBox;
        msgBox.setText(Message);
        msgBox.exec();
}
