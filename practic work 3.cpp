#include <iostream>
#include <ctime>
#include<conio.h>
#include<windows.h>

using namespace std;

int** create_m(int n) {
    int** m = new int* [n];
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];
    }
    // Инициализируем матрицу нулями
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

void print_m(int** m, int n) {
    system("cls"); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(m + i) + j) << "\t";
        }
        cout << endl;
    }
}

void spiral_m(int** m, int n) {
    int top = 0, low = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (num <= n * n) {
        // Заполнение верхней строки
        for (int i = left; i <= right; ++i) {
            m[top][i] = rand() % (n * n) + 1;
            num++;
            print_m(m, n); 
            Sleep(200); 
        }
        top++;

        // Заполнение правого столбца
        for (int i = top; i <= low; ++i) {
            m[i][right] = rand() % (n * n) + 1;
            num++;
            print_m(m, n); 
            Sleep(200); 
        }
        right--;

        // Заполнение нижней строки
        if (top <= low) {
            for (int i = right; i >= left; --i) {
                m[low][i] = rand() % (n * n) + 1;
                num++;
                print_m(m, n); 
                Sleep(200);
            }
            low--;
        }

        // Заполнение левого столбца
        if (left <= right) {
            for (int i = low; i >= top; --i) {
                m[i][left] = rand() % (n * n) + 1;
                num++;
                print_m(m, n); 
                Sleep(200); 
            }
            left++;
        }
    }
}

void cross_m(int** m, int n) {
    int num_1 = n ;
    int num = 2 * n;
    for (int j = 0; j < n / 2; j++) {
        for (int i = 0; i < n; ++i) {
            if (i + i > num - 2)
                break;
            if (m[i + j][i] == 0)
                m[i + j][i] = rand() % (n * n) + 1;
            if (m[i + j][n - 1 - i] == 0)
                m[i + j][n - 1 - i] = rand() % (n * n) + 1;
            print_m(m, n);
            Sleep(1000);
        }
        for (int i = 0; i < n ; ++i) {
            if (i + i > num - 2)
                break;
            if (m[i][i + j] == 0)
                m[i][i + j] = rand() % (n * n) + 1;
            if (m[i][n - 1 - i - j] == 0)
                m[i][n - 1 - i - j] = rand() % (n * n) + 1;
            print_m(m, n);
            Sleep(1000);
        }
        num--;
    }
}

void snake_m(int** m, int n) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { 
            for (int j = 0; j < n; j++) {
                m[j][i] = rand() % (n * n) + 1;
                num++;
                print_m(m, n);
                Sleep(200); 
            }
        }
        else { 
            for (int j = n - 1; j >= 0; j--) {
                m[j][i] = rand() % (n * n) + 1;
                num++;
                print_m(m, n);
                Sleep(200); 
            }
        }
    }
}

void snake_m_moment(int** m, int n) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                m[j][i] = rand() % (n * n) + 1;
                num++;
                print_m(m, n);
                Sleep(0);
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                m[j][i] = rand() % (n * n) + 1;
                num++;
                print_m(m, n);
                Sleep(0);
            }
        }
    }
}

void permutation_1(int** m, int n) {
    int midd = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < midd; j++) {
            swap(*(*(m + i) + j), *(*(m + i) + j + midd));
        }
    }

    for (int i = 0; i < midd; i++) {
        for (int j = 0; j < midd; j++) {
            swap(*(*(m + i) + j), *(*(m + i + midd) + j + midd));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(m + i) + j) << "\t";
        }
        cout << endl;
    }
}

void permutation_2(int** m, int n) {
    int midd = n / 2;

    for (int i = 0; i < midd; i++) {      
        for (int j = 0; j < n; j++) {
            swap(*(*(m + i) + j), *(*(m + i + midd) + j));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < midd; j++) {
            swap(*(*(m + i) + j), *(*(m + i) + j + midd));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(m + i) + j) << "\t";
        }
        cout << endl;
    }

}

void permutation_3(int** m, int n) {
    int midd = n / 2;

    for (int i = 0; i < midd; i++) {
        for (int j = 0; j < n; j++) {
            swap(*(*(m + i) + j), *(*(m + i + midd) + j));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(m + i) + j) << "\t";
        }
        cout << endl;
    }
}

void permutation_4(int** m, int n) {
    int midd = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < midd; j++) {
            swap(*(*(m + i) + j), *(*(m + i) + j + midd));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(m + i) + j) << "\t";
        }
        cout << endl;
    }
}

void quick_sort(int* arr, int begin, int end) {

    int mid = *(arr + (begin + end) / 2);
    int f = begin;
    int l = end;

    while (f <= l) {
        while (*(arr + f) < mid)           
            f++;
        while (*(arr + l) > mid) 
            l--;
        if (f <= l) {
            swap(*(arr + f), *(arr + l));
            f++;
            l--;
        }
    }

    if (begin < l) quick_sort(arr, begin, l);
    if (f < end) quick_sort(arr, f, end);
}

void sort_m(int** m, int n) {
    int* arr = new int[n * n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(arr + i * n + j) = *(*(m + i) + j);
        }
    }

    quick_sort(arr, 0, n * n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(m + i) + j) = *(arr + i * n + j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(m + i) + j) << "\t";
        }
        cout << endl;
    }
}

void rand_m_idz(int** m, int** m_1, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rand() % (n * n) + 1;
        }
    }
    cout << "\033[32m" << "Первая матрица: " << "\033[0m" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m_1[i][j] = rand() % (n * n) + 1;
        }
    }
    cout << "\033[32m" << "Вторая матрица: " << "\033[0m" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m_1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\033[36m" << "Разность двух матриц: " << "\033[0m" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] - m_1[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    setlocale(0, "");
    srand(time(0));
    cout << "\033[36m";
    cout << "Чтобы увидеть решение задания, введите его номер, чтобы закончить просмотр практической работы, нажмите 'z' :" << endl;
    cout << "\033[0m";
    while (true) {
        char button = _getch();
        if (button == 'z')
            return 0;
        else {
            switch (button) {
            case '1': {
                cout << "Задание 1: " << endl;
                while (true) {
                    cout << "\033[32m" << "Выберите схему, согласно которой будет заполнен двумерный массив: " << "\033[0m" << endl;
                    cout << "1. Спираль " << endl;
                    cout << "2. Змейка " << endl;
                    cout << "Если хотите закончить выполнение задания - нажмите x, а потом номер задания: " << endl;
                    char button_1 = _getch();
                    if (button_1 == 'x')
                        break;
                    switch (button_1) {
                    case '1': {
                        cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                        int n;
                        cin >> n;
                        int** m = create_m(n);
                        spiral_m(m, n);
                        cout << endl;
                        break;
                    }
                    case'2': {
                        cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                        int n;
                        cin >> n;
                        int** m = create_m(n);
                        snake_m(m, n);
                        break;
                    }
                    }
                }
                break;
            }

            case '2': {
                cout << "Задание 2: " << endl;
                while (true) {
                    cout << "\033[32m" << "Выберите схему, согласно которой будут совершены перестановки: " << "\033[0m" << endl;
                    cout << "1. схема a: " << endl;
                    cout << "2. схема b: " << endl;
                    cout << "3. схема c: " << endl;
                    cout << "4. схема d: " << endl;
                    cout << "Если хотите закончить выполнение задания - нажмите x, а потом номер задания: " << endl;
                    char button_2 = _getch();
                    if (button_2 == 'x')
                        break;
                    switch (button_2) {
                    case '1': {
                        cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                        int n;
                        cin >> n;
                        int** m = create_m(n);
                        snake_m_moment(m, n);
                        cout << endl;
                        permutation_1(m, n);
                        break;
                    }
                    case '2': {
                        cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                        int n;
                        cin >> n;
                        int** m = create_m(n);
                        snake_m_moment(m, n);
                        cout << endl;
                        permutation_2(m, n);
                        break;
                    }
                    case '3': {
                        cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                        int n;
                        cin >> n;
                        int** m = create_m(n);
                        snake_m_moment(m, n);
                        cout << endl;
                        permutation_3(m, n);
                        break;
                    }
                    case '4': {
                        cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                        int n;
                        cin >> n;
                        int** m = create_m(n);
                        snake_m_moment(m, n);
                        cout << endl;
                        permutation_4(m, n);
                        break;
                    }
                    }
                }
                break;
            }
            case '3': {
                cout << "Задание 3: " << endl;
                cout << "\033[32m" << "Вывод отсортированного двумерного массива: " << "\033[0m" << endl;
                cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                int n;
                cin >> n;
                int** m = create_m(n);
                snake_m_moment(m, n);
                cout << "\033[36m" << "Отсортированный массив: " << "\033[0m" << endl;
                sort_m(m, n);
                break;
            }
            case '4': {
                cout << "Задание 4: " << endl;
                cout << "\033[32m" << "Уменьшение всех элементов матрицы нa число, введенное пользовтелем: " << "\033[0m" << endl;
                cout << "\033[36m" << "Введите размерность квадратной матрицы: " << "\033[0m";
                int n, k;
                cin >> n;
                int** m = create_m(n);
                snake_m_moment(m, n);
                cout << "\033[36m" << "Введите число, на которое нужно уменьшить: " << "\033[0m";
                cin >> k;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << *(*(m + i) + j) - k << "\t";
                    }
                    cout << endl;
                }
                break;
            }
            case '5': { // ИДЗ
                cout << "\033[32m" << "Идз №3. Вычитание матриц: " << "\033[0m" << endl;
                cout << "\033[36m" << "Введите размерность первой и второй квадратной матрицы: " << "\033[0m";
                int n;
                cin >> n;
                int** m = new int* [n];
                int** m_1 = new int* [n];
                for (int i = 0; i < n; i++) {
                    m[i] = new int[n];
                    m_1[i] = new int[n];
                }
                rand_m_idz(m, m_1, n);
                break;
            }
            }
        }
    }
}
