#include <Arduino.h>
byte errorByte = 0;

// Fungsi untuk mengatur error (mengubah bit terkait menjadi 1)
void setError(int errorNumber)
{
    if (errorNumber >= 1 && errorNumber <= 8)
    {
        errorByte |= (1 << (errorNumber - 1)); // Mengubah bit ke- (errorNumber - 1) menjadi 1
    }
}

// Fungsi untuk menghapus error (mengubah bit terkait menjadi 0)
void unsetError(int errorNumber)
{
    if (errorNumber >= 1 && errorNumber <= 8)
    {
        errorByte &= ~(1 << (errorNumber - 1)); // Mengubah bit ke- (errorNumber - 1) menjadi 0
    }
}

// Fungsi untuk mengecek posisi error pertama, atau mengembalikan 0 jika tidak ada error
int hasError()
{
    for (int i = 0; i < 8; i++)
    {
        if (errorByte & (1 << i))
        {
            return i + 1; // Mengembalikan posisi bit error pertama (1 hingga 8)
        }
    }
    return 0; // Jika tidak ada error, kembalikan 0
}

void setup()
{
    Serial.begin(115200);

    setError(3);
    setError(7);

    int errorPosition = hasError();
    if (errorPosition == 0)
    {
        Serial.println("Tidak ada error.");
    }
    else
    {
        Serial.print("Error pertama ditemukan di posisi: ");
        Serial.println(errorPosition);
    }

    unsetError(3);

    errorPosition = hasError();
    if (errorPosition == 0)
    {
        Serial.println("Tidak ada error.");
    }
    else
    {
        Serial.print("Error pertama ditemukan di posisi: ");
        Serial.println(errorPosition);
    }
}

void loop()
{
    // Loop kosong
}
