#include<iostream> 
#include<conio.h> 
using namespace std;

int main() {
start: while (true) {
    char button = _getch();
    if (button == 'z')
        return 0;
    else {
        setlocale(0, "");
        cout << "\033[32m";
        cout << "Выберите номер заднания: ";
        cout << "\033[0m";
        int num;
        cin >> num;
        switch (num) {
        case 1: {
            // решение задания 1
            setlocale(0, "");
            cout << "чтобы увидеть объем памяти int - нажмите 1, чтобы увидеть short int - нажмите 2" << endl;
            cout << "чтобы увидеть объем памяти long int - нажмите 3, чтобы увидеть float - нажмите 4" << endl;
            cout << "чтобы увидеть объем памяти double - нажмите 5, чтобы увидеть long double - нажмите 6" << endl;
            cout << "чтобы увидеть объем памяти char - нажмите 7, чтобы увидеть bool - нажмите 8" << endl;
            while (true) {
                char button_1 = _getch();
                if (button_1 == 'x')
                    goto start;
                else {
                    switch (button_1) {
                    case '1':
                        cout << "int = " << sizeof(int) << " байт" << endl;
                        break;
                    case '2':
                        cout << "short int = " << sizeof(short int) << " байт" << endl;
                        break;
                    case '3':
                        cout << "long int = " << sizeof(long int) << " байт" << endl;
                        break;
                    case '4':
                        cout << "float = " << sizeof(float) << " байт" << endl;
                        break;
                    case '5':
                        cout << "double = " << sizeof(double) << " байт" << endl;
                        break;
                    case '6':
                        cout << "long double = " << sizeof(long double) << " байт" << endl;
                        break;
                    case '7':
                        cout << "char = " << sizeof(char) << " байт" << endl;
                        break;
                    case '8':
                        cout << "bool = " << sizeof(bool) << " байт" << endl;
                        break;
                    }
                }
            }
            return 0;
            break;
        }
        case 2: {
            // решение задания 2
            setlocale(0, "");
            while (true) {
                char button_2 = _getch();
                if (button_2 == 'x')
                    goto start;
                else {
                    int num;
                    cout << "Введите число: ";
                    cin >> num;
                    unsigned int mask = 1 << 31;
                    char button = _getch();
                    for (int i = 1; i <= 32; i++) {
                        cout << "\033[31m";
                        if (i >= 2)
                            cout << "\033[0m";
                        cout << (num & mask ? '1' : '0');
                        mask >>= 1;
                        if (i == 1 || i % 8 == 0) {
                            cout << " ";
                        }
                    }
                    cout << endl;
                    if (num < 0) {
                        for (int i = 0; i < 32; i++) {
                            if (i % 2 == 0) {
                                num &= ~(1 << i);
                            }
                        }
                    }
                    else {
                        for (int i = 0; i < 32; i++) {
                            if (i % 2 != 0) {
                                num |= (1 << i);
                            }
                        }
                    }
                    cout << "Вывод этого же числа после ИДЗ:" << endl;
                    for (int i = 31; i >= 0; i--) {
                        cout << ((num & (1 << i)) ? '1' : '0');
                        if (i == 31 || i % 8 == 0)
                            cout << " ";

                    }
                    cout << endl;
                    cout << "Конечный результат: " << num << endl;
                }

            }
            break;
        }
        case 3: {
            // решение задания 3
            setlocale(0, "");
            while (true) {
                char button_3 = _getch();
                if (button_3 == 'x')
                    goto start;
                else {
                    union {
                        float num_f;
                        int num_i;
                    };
                    cout << "Введите число: ";
                    cin >> num_f;
                    unsigned int mask = 1 << 31;
                    for (int i = 1; i <= 32; i++) {
                        cout << "\033[31m";
                        if (i >= 2 and i <= 24)
                            cout << "\033[33m";
                        if (i >= 25 and i <= 32)
                            cout << "\033[35m";
                        putchar(num_i & mask ? '1' : '0');
                        mask >>= 1;
                        if (i == 1 || i % 8 == 0) {
                            cout << " ";
                        }
                    }
                    cout << endl;
                    cout << "\033[0m";
                    if (num_f < 0) {
                        for (int i = 0; i < 32; i++) {
                            if (i % 2 == 0) {
                                num_i &= ~(1 << i);
                            }
                        }
                    }
                    else {
                        for (int i = 0; i < 32; i++) {
                            if (i % 2 != 0) {
                                num_i |= (1 << i);
                            }
                        }
                    }
                    cout << "Вывод этого же числа после ИДЗ:" << endl;
                    for (int i = 31; i >= 0; i--) {
                        cout << ((num_i & (1 << i)) ? '1' : '0');
                        if (i == 31 || i % 8 == 0)
                            cout << " ";

                    }
                    cout << endl;
                    cout << "Конечный результат: " << num_f << endl;
                }
            }
            break;
        }
        case 4: {
            // решение задания 4
            setlocale(0, "");
            while (true) {
                char button = _getch();
                if (button == 'x')
                    goto start;
                else {
                    union {
                        double num_d;
                        int num_i[2];
                    };
                    cout << "Введите число: ";
                    cin >> num_d;
                    int k = 0;
                    cout << "\033[31m";
                    for (int i = 1; i >= 0; i--) {
                        unsigned musk = 1 << 31;
                        for (int j = 1; j <= 32; j++) {
                            cout << (num_i[i] & musk ? '1' : '0');
                            musk >>= 1;
                            k += 1;

                            if (k > 0 and k <= 10)
                                cout << "\033[33m";
                            if (k > 10 and k <= 63)
                                cout << "\033[35m";
                            if (k == 1 || k == 11)
                                cout << " ";
                        }
                    }
                    cout << endl;
                    cout << "\033[0m";
                    if (num_d < 0) {
                        for (int i = 0; i < 2; i++) {
                            for (int j = 0; j < 32; j += 2) {
                                num_i[i] &= ~(1 << j);
                            }
                        }
                    }
                    else {
                        for (int i = 0; i < 2; i++) {
                            for (int j = 1; j < 32; j += 2) {
                                num_i[i] |= (1 << j);
                            }
                        }
                    }
                    cout << "Вывод этого же числа после ИДЗ: " << endl;
                    int n = 0;
                    for (int i = 1; i >= 0; i--) {
                        unsigned mask = 1 << 31;
                        for (int j = 1; j <= 32; j++) {
                            cout << (num_i[i] & mask ? '1' : '0');
                            mask >>= 1;
                            n += 1;

                            if (n == 1 || n == 11)
                                cout << " ";
                        }
                    }
                    cout << endl;
                    cout << "Конечный результат: " << num_d << endl;
                }
            }
        }
        }
    }
}
}