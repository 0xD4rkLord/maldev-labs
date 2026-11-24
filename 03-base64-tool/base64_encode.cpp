#include <windows.h>
#include <wincrypt.h>
#include <iostream>

#pragma comment(lib, "Crypt32.lib")

int main()
{
    const BYTE input[] = {'H', 'e', 'l', 'l', 'o'};

    char output[64] = {};
    DWORD outputSize = sizeof(output);

    BOOL result = CryptBinaryToStringA(input, sizeof(input), CRYPT_STRING_BASE64, output, &outputSize);

    if(!result)
    {
        std::cout << "Error " << GetLastError() << std::endl;
        return 1;
    }

    std::cout << output << std::endl;

    return 0;


}