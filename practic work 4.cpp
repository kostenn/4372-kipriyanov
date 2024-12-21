#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include<conio.h>
#include<regex>

using namespace std;

string process_txt(const string& input) {
    string result = regex_replace(input, regex("\\s+"), " "); // Заменяем несколько пробелов на один
    result = regex_replace(result, regex("^\\s+|\\s+$"), ""); // Удаляем пробелы в начале и конце строки

    // Удаляем лишние знаки препинания
    result = regex_replace(result, regex(",{2,}"), ","); // Заменяем повторяющиеся запятые на одну
    result = regex_replace(result, regex("\\.{3,}"), "..."); // Оставляем троеточие как есть

    // Исправляем регистр букв
    for (size_t i = 0; i < result.size(); ++i) {
        if (i == 0 || result[i - 1] == ' ') {
            result[i];
        }
        else {
            result[i] = tolower(result[i]); // Остальные буквы строчные
        }
    }

    return result;
}

string reg_txt(const string& input) {
    string result = input;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i == 0 || result[i - 1] == ' ') {
            result[i] = toupper(result[i]); // Первая буква каждого слова заглавная
        }
    }
    return result;
}

void search(string text, string pattern) {
    int n = text.length(); 
    int m = pattern.length(); 

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) // если все символы совпали
            cout << i << " ";
    }
}

int main() {
    setlocale(0, "");
    const int max_words = 51;
    const int max_len = 10;
    string words;
    int k = 0;
    cout << "\033[36m";
    cout << "Чтобы увидеть решение задания, введите его номер, чтобы закончить просмотр практической работы, нажмите 'z' :" << endl;
    cout << "\033[0m";
    while (true) {
        char button = _getch();
        if (button == 'z')
            return 0;
        else {
            switch (button) {
            case'1': {
                cout << "\033[32m";
                cout << "Задание 1 - 2. Ввод последовательности и её редактирование: " << endl;
                cout << "\033[0m";
                cout << "\033[36m";
                cout << "Выберите способ ввода последовательности (файл - '1' или ввод - '2'): " << endl;
                cout << "\033[0m";
                while (true) {
                    char metod = _getch();
                    if (metod == 'x')
                        break;
                    else {
                        string line;
                        switch (metod) {
                        case'1': {
                            string file_name = "practic_work_4.txt";
                            fstream input_file(file_name);
                            cout << "\033[32m";
                            cout << "Вывод неотредактированной последовательности из файла: " << endl;
                            cout << "\033[0m";

                            if (getline(input_file, line)) {
                                cout << line << endl;

                                string processed_line = process_txt(line);
                                words = processed_line;
                                cout << "\033[32m";
                                cout << "Вывод отредактированной последовательности из файла: " << endl;
                                cout << "\033[0m";
                                cout << processed_line << endl;
                            }
                            else {
                                cout << "Файл пуст или не удалось прочитать строку." << endl;
                            }

                            input_file.close();
                            break;
                        }

                        case '2': {
                            cout << "\033[32m";
                            cout << "Вывод неотредактированной последовательности с клавиатуры: " << endl;
                            cout << "\033[0m";

                            getline(cin, line);
                            if (line.back() != '.') {
                                cout << "\033[36m";
                                cout << "Текст не имеет точки в конце, повторите попытку" << endl;
                                cout << "\033[0m";
                                return 0;
                            }
                            cout << "\033[32m";
                            cout << "Вывод отредактированной последовательности: " << endl;
                            cout << "\033[0m";

                            cout << process_txt(line) << endl;
                            istringstream iss(line);
                            string word;
                            while (iss >> word) {
                                k++;
                            }
                            words = process_txt(line);
                            break;
                        }
                        }
                    }
                }
                break;
            }
            case '3': {
                cout << "\033[32m";
                cout << "Задание 3. Вывод слов, введеных с клавиатуры, в обратном порядке: " << endl;
                cout << "\033[0m";
                words.pop_back();
                istringstream iss(words);
                vector<string> line;
                string word;
                while (iss >> word) {
                    line.push_back(word);
                }
                string n;
                for (auto it = line.rbegin(); it != line.rend(); ++it) {
                    n  = n + *it + " ";
                }
                n.pop_back();
                n += '.';
                cout << n;
                cout <<endl;
                break;
            }
            case '4': {
                cout << "\033[32m";
                cout << "Задание 4. Вывод слов, введеных с клавиатуры, с заглавной первой буквой: " << endl;
                cout << "\033[0m";
                string line = reg_txt(words) + '.';
                cout << line << endl;
                break;
            }
            case '5': {
                cout << "\033[32m";
                cout << "Задание 5. Поиск в строке подстроки: " << endl;
                cout << "\033[0m";
                string pattern;
                cout << "\033[36m";
                cout << "Введите подстроку, которую будем искать: " << endl;
                cout << "\033[0m";
                cin >> pattern;
                cout << "Вывод индексов начала найденной подстроки: ";
                search(words, pattern);
                break;
            }
            }
        }
    }
}