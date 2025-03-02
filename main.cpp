#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "russian");
    unsigned _int16 A1 = 0xF1FF, A2 = 0xFFFF, A3 = 0x1FFF;
    unsigned _int16 B1 = 0xABCD, B2 = 0xABC0, B3 = 0x0000;
    unsigned _int16 C1, C2, C3;

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

    std::cout << "В шеснадцатиричной: ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << C3 << " ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << C2 << " ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << C1 << "\n";

    unsigned _int64 result = static_cast<unsigned _int64>(C3);
    result = (result << 16) | C2;
    result = (result << 16) | C1;

    std::cout << "В десятичной: " << std::dec << result << "\n";
    return 0;
}