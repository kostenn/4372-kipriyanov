#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;
//������� ������ 
namespace Color {
    // ANSI escape codes ��� ��������� ����� ������
    const string RESET = "\033[0m"; //�����
    const string RED = "\033[1m\033[31m"; //������� 
    const string GREEN = "\033[1m\033[32m";//�������
    const string YELLOW = "\033[1m\033[33m"; //������
    const string BLUE = "\033[1m\033[34m";//�����
    const string MAGENTA = "\033[1m\033[35m";// ���������
    const string CYAN = "\033[1m\033[36m";// �������
    const string BLACK = "\033[1m\033[30m";// ������
    const string WHITE = "\033[1m\033[37m"; // �����

    void Red(const string& text) {
        cout << RED << text << RESET << endl;
    }
    void Green(const string& text) {
        cout << GREEN << text << RESET << endl;
    }
    void Yellow(const string& text) {
        cout << YELLOW << text << RESET << endl;
    }
    void Blue(const string& text) {
        cout << BLUE << text << RESET << endl;
    }
    void Magenta(const string& text) {
        cout << MAGENTA << text << RESET << endl;
    }
    void Cian(const string& text) {
        cout << CYAN << text << RESET << endl;
    }
    void Black(const string& text) {
        cout << BLACK << text << RESET << endl;
    }
    void White(const string& text) {
        cout << WHITE << text << RESET << endl;
    }

}
using namespace Color;
//���������� �������
void bubble_sort(int res[100])
{
    bool swapped = false;
    for (int i = 0; i < 100; i++)
    {
        swapped = false;
        for (int j = 0; j < 100 - i - 1; j++)
        {
            if (res[j] > res[j + 1])
            {
                std::swap(res[j], res[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
//���������� ������
void shaker_sort(int res[100])
{
    bool swapped = true;
    while (swapped != false)
    {
        swapped = false;
        bool AorB = true;
        if (AorB)
        {
            for (int i = 0; i < 99; i++)
            {
                if (res[i] > res[i + 1])
                {
                    std::swap(res[i], res[i + 1]);
                    swapped = true;
                    AorB = false;
                }
            }
        }
        else
        {
            for (int j = 99; j > 0; j--)
            {
                if (res[j - 1] > res[j])
                {
                    std::swap(res[j], res[j - 1]);
                    swapped = true;
                    AorB = true;
                }
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
//�������� �����
bool BinarySearch(int res[100], int num)
{
    int left = 0;
    int right = 100 - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (res[middle] == num)
        {
            return 1;
        }
        if (res[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}
//���������� ���������
void CombSort(int res[100])
{
    int step = 100;
    bool isSwaps = true;
    while (step > 1 and isSwaps == true)
    {
        step = int(step / 1.247);
        isSwaps = false;
        for (int i = 0; i < 100 - step; i++)
        {
            if (res[i] > res[i + step])
            {
                swap(res[i], res[i + step]);
                isSwaps = true;
            }
        }
    }
}
//���������� ���������
void InsertSort(int res[100])
{
    for (int j = 1; j < 100; j++)
    {
        int bufer = res[j];
        int i = j - 1;
        while (i >= 0 && res[i] > bufer)
        {
            res[i + 1] = res[i];
            i--;
        }
        res[++i] = bufer;
    }
}
//������� ����������
void quickSort(vector<int>& res, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int middle = res[(left + right) / 2];

        // ��������� ������ �� ��� �����
        while (left <= right) {
            // ���� ��������, ������� ����� �������� �������
            while (res[left] < middle) {
                left++;
            }
            while (res[right] > middle) {
                right--;
            }
            if (left <= right) {
                swap(res[left], res[right]);
                left++;
                right--;
            }
        }
        if (first < right) {
            quickSort(res, first, right);
        }
        if (left < last) {
            quickSort(res, left, last);
        }
    }
}

int BinarySearch1(int res[100], int num)
{
    int left = 0;
    int right = 100 - 1;
    int middle;
    int k = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (res[middle] == num)
        {
            return middle;
        }
        if (res[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}

//���������� �����
void shellSort(int res[100]) {
    // �������� � �������� ��������� � ��������� ���
    for (int gap = 100 / 2; gap > 0; gap /= 2) {
        // ��������� ���������� ��������� ��� �������� ���������
        for (int i = gap; i < 100; i++) {
            int temp = res[i];
            int j;
            for (j = i; j >= gap && res[j - gap] > temp; j -= gap) {
                res[j] = res[j - gap];
            }
            res[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end, start1, end1;
    nanoseconds result, result1;

    int yop;

    int key;

    int choice = 0;
    int res[100];

    int mini = 101;
    int maxi = -101;

    while (true) {
        //����
        cout << "\033[1m\033[31m";
        Red("�������� ����� (1-8) ��� 0 ��� ������\n");
        cout << "\033[0m";
        cout << "1. ����� 1. ������ ����������� N = 100\n";
        cout << "2. ����� 2. �������������\n";
        cout << "3. ����� 3. ����� ������������ � ����������� �������\n";
        cout << "4. ����� 4. ������� ������� ��������\n";
        cout << "5. ����� 5. ������ ����� a\n";
        cout << "6. ����� 6. ������ ����� b\n";
        cout << "7. ����� 7. ���� �� ��������� ������������� �����\n";
        cout << "8. ����� 8. ������ ������� �������� �������\n";
        cout << "9. ����� 9. ���������� �����\n";
        cout << "0. �����\n";

        cin >> choice;

        if (choice == 0) {
            std::cout << "\n��������� ��������� ���� ������" << std::endl;
            break;
        }
        switch (choice) {
        case 1:
            while (true)
            {
                cout << "\033[1m\033[31m";
                Green("�� ������� ����� 1");
                cout << "\033[0m";
                Cian("\n��������������� ������: ");
                start = steady_clock::now();
                for (int l = 0; l < 100; l++)
                {
                    int random1 = rand() % 200 - 100;
                    res[l] = random1;
                    if (random1 < mini)
                    {
                        mini = random1;
                    }
                    if (random1 > maxi)
                    {
                        maxi = random1;
                    }
                    cout << res[l] << " ";
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                key = result.count();
                cout << endl;
                char finish;
                cout << "������ ����� �� 1 ������?: y/n: ";
                cin >> finish;
                if (finish == 'y' || finish == 'Y' || finish == '�')
                    break;
            }
        case 2:
            while (true)
            {
                Green("\n�� ������� ����� 2");
                cout << "\n������ �� ������ ������� ��� ����������:\n";
                cout << "1: bubble_sort\n";
                cout << "2: shaker_sort\n";
                cout << "3: CombSort\n";
                cout << "4: InsertSort\n";
                cout << "5: quickSort\n";
                cout << "0: ����� �� ������� ������\n";
                int sorty;
                cin >> sorty;
                if (sorty == 1) {
                    start = steady_clock::now();
                    bubble_sort(res);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 2) {
                    start = steady_clock::now();
                    shaker_sort(res);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 3) {
                    start = steady_clock::now();
                    CombSort(res);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 4) {
                    start = steady_clock::now();
                    InsertSort(res);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 5)
                {
                    vector<int> arr(100);
                    for (int l = 0; l < 100; l++)
                    {
                        int random1 = rand() % 200 - 100;
                        arr[l] = random1;
                    }
                    cout << endl;
                    start = steady_clock::now();
                    quickSort(arr, 0, 99);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << arr[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 0)
                    break;
            }

        case 3:
            while (true)
            {
                Green("�� ������� ����� 3\n");
                cout << "min ������� ������� : " << mini << endl;
                cout << "max ������� ������� : " << maxi << endl;
                Yellow("����� ����������� �� ����� ������������ � ������������� �������� � ��������������� �������: ");
                cout << key << endl;
                Yellow("����� ����������� �� ����� ������������ � ������������� �������� � ������������� �������: ");
                start = steady_clock::now();
                int a = res[0], b = res[99];
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << result.count() << "\n";
                break;
            }
        case 4:
            while (true)
            {
                Green("�� ������� ����� 4\n");
                int srednee = int((mini + maxi) / 2);
                cout << "������� �������� min � max: " << srednee << endl;
                int count = 0;
                int indexi[50];
                int o = 0;
                for (int l = 0; l < 100; l++)
                {
                    if (res[l] == srednee)
                    {
                        count += 1;
                    }
                }
                Cian("���������� ��������� ������ �������� ��������: ");
                cout << count << endl;
                cout << "\033[1m\033[36m";
                cout << "������� ������ ���������: ";
                cout << "\033[00m";
                bool found = false;
                start = steady_clock::now();
                for (int i = 0; i < 100; ++i)
                {
                    if (res[i] == srednee)
                    {
                        cout << i << " ";
                        found = true;
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                if (!found) {
                    Red("��� ���������, ������ �������� ��������.");
                }
                cout << endl;
                cout << "����� ������: " << result.count() << "\n";
                break;
            }
        case 5:
            while (true)
            {
                shaker_sort(res);
                Green("�� ������� ����� 5\n");
                Blue("������� �����, ����� ����� ���������� ��������� ������� a");
                int a;
                cout << "a = ";
                cin >> a;
                cout << "���������� ��������� ������� a: ";
                int fin = BinarySearch1(res, a);
                if (fin != 0) {
                    cout << "���������� ��������� ������� " << a << ": " << fin << endl;
                }
                else {
                    cout << "����� " << a << " ��� � ������." << endl;
                }
                break;
            }
        case 6:
            while (true)
            {
                shaker_sort(res);
                Green("�� ������� ����� 6\n");
                Blue("������� �����, ����� ����� ���������� ��������� ������� a");
                int a;
                cout << "a = ";
                cin >> a;
                int fin = 100 - BinarySearch1(res, a);
                if (fin != 0) {
                    cout << "���������� ��������� ������� " << a << ": " << fin << endl;
                }
                else {
                    cout << "\033[1m\033[31m";
                    cout << "����� " << a << " ��� � ������." << endl;
                    cout << "\033[00m";
                }
                break;
            }
        case 7:
            while (true)
            {
                Green("�� ������� ����� 7\n");
                Blue("������� �����, ������� ������ ����� � ������");
                int choice;
                cout << "choice = ";
                cin >> choice;
                start = steady_clock::now();
                int otvet = BinarySearch(res, choice);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                if (otvet != 0) {
                    cout << "�������� " << choice << " ���� � �������" << endl;
                }
                else {
                    cout << "\033[1m\033[31m";
                    cout << "����� " << choice << " ��� � ������." << endl;
                    cout << "\033[00m";
                }
                cout << "����� ������ ��������� ������: " << result.count() << endl;
                start1 = steady_clock::now();
                for (int i = 0; i < 100; i++)
                {
                    if (res[i] == choice)
                        return 1;
                    else
                        break;
                }
                end1 = steady_clock::now();
                result1 = duration_cast<nanoseconds>(end1 - start1);
                break;
            }
        case 8:
            Green("\n�� ������� ����� 8\n");
            Cian("������ ���������� ���������� ������ ������� ���������, ������������ � ������.");
            int a, b;
            cout << "������� ����� A: ";
            cin >> a;
            cout << "������� ����� B: ";
            cin >> b;
            int bufer;
            start = steady_clock::now();
            bufer = res[a];
            res[a] = res[b];
            res[b] = bufer;
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n��� ���������� ������: ";
            for (int i = 0; i < 100; i++)
                cout << res[i] << " ";
            Blue("\n����� ����� ��������� � ������� ���������: ");
            cout << result.count() << endl;
        case 9:
            while (true)
            {
                Green("�� ������� ����� 9. ���������� �����\n");
                Blue("C����� �� �������� ������ ������� ����� ����������� ����� � Bubble_Sort");
                Cian("������� 1 - ����, 2 - ���������� ����� ��� 0-�����");
                int sorty;
                cin >> sorty;
                if (sorty == 1) {
                    start = steady_clock::now();
                    bubble_sort(res);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 2) {
                    start = steady_clock::now();
                    shellSort(res);
                    Blue("C������������ ������: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "����� ������: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 0)
                    break;
            }
        default:
            cout << "�������� �����. ����������, �������� �� 0 �� 8\n";
        }
    }

    return 0;
}
