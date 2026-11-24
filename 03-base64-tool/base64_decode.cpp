#include <windows.h>
#include <wincrypt.h>
#include <iostream>

#pragma comment(lib, "Crypt32.lib")

int main()
{
    const char input[] = "SGVsbG8=";

    BYTE output[64] = {};
    DWORD outputSize = sizeof(output);

    BOOL result = CryptStringToBinaryA(input, sizeof(input) - 1, CRYPT_STRING_BASE64, output, &outputSize, nullptr, nullptr);

    if(!result)
    {
        std::cout << "Error " << GetLastError() << std::endl;
        return 1;
    }

    for (DWORD i=0; i<outputSize;i++)
    {
        std::cout << static_cast<char>(output[i]);
    }
    std::cout << std::endl;

    return 0;

}