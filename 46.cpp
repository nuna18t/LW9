#include <iostream>
#include <string>

int custom_compare(const char* str, size_t pos, size_t len, const char* s, size_t n) {
    // Перевірка виходу за межі масиву
    for (size_t i = 0; i < len && i < n; ++i) {
        if (str[pos + i] != s[i]) {
            return (str[pos + i] < s[i]) ? -1 : 1;
        }
    }
    if (len == n) {
        return 0;
    } else {
        return (len < n) ? -1 : 1;
    }
}

int main() {
    // Введення рядка з консолі
    std::string input_str;
    std::cout << "Введіть рядок: ";
    std::getline(std::cin, input_str);

    // Копіювання введеного рядка в масив символів
    size_t str_len = input_str.length();
    char* input_cstr = new char[str_len + 1];
    std::copy(input_str.begin(), input_str.end(), input_cstr);
    input_cstr[str_len] = '\0';

    // Приклади викликів функції
    const char* s = "example";
    size_t pos = 2;
    size_t len = 3;
    size_t n = 3;

    // Виклик користувацької функції
    int result_custom = custom_compare(input_cstr, pos, len, s, n);

    // Виклик методу string::compare
    std::string input_str_sub = input_str.substr(pos, len);
    int result_std = input_str_sub.compare(0, len, s, n);

    // Виведення результатів
    std::cout << "Результат custom_compare: " << result_custom << std::endl;
    std::cout << "Результат string::compare: " << result_std << std::endl;

    // Звільнення виділеної пам'яті
    delete[] input_cstr;

    return 0;
}
