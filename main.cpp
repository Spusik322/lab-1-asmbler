#include <iostream>
#include <iomanip>

int main() {
    unsigned short A1 = 0x7FFF, A2 = 0x0000;
    unsigned short B1 = 0xABCD, B2 = 0x0000;
    short A3 = 0x7FFF, B3 = 0x0001, C3;
    unsigned short C1, C2;

    _asm {
        mov ax, A1
        add ax, B1
        mov C1, ax;
        pushf;
    }

    _asm {
        popf;
        mov ax, A2
        adc ax, B2;
        mov C2, ax;
        pushf;
    }

    _asm {
        popf;
        mov ax, A3
        adc ax, B3;
        mov C3, ax;
    }

    std::cout << "IN 16: ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << static_cast<int>(C3) << " ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << static_cast<int>(C2) << " ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << static_cast<int>(C1) << "\n";

    long long result = static_cast<long long>(C3);
    result = (result << 16) | C2;
    result = (result << 16) | C1;

    std::cout << "IN 10: " << std::dec << result << "\n";
    return 0;
}