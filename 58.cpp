#include <iostream>
#include <string>

std::string extractFileNameWithoutExtension(const std::string& fullPath) {
    // Знаходження останнього слеша
    size_t lastSlashPos = fullPath.find_last_of("/\\");
    size_t startPos = (lastSlashPos == std::string::npos) ? 0 : lastSlashPos + 1;

    // Знаходження останньої крапки після останнього слеша
    size_t lastDotPos = fullPath.find_last_of('.');

    // Якщо крапка знайшлася після слеша, виділяємо ім'я файлу без розширення
    if (lastDotPos != std::string::npos && lastDotPos > startPos) {
        return fullPath.substr(startPos, lastDotPos - startPos);
    } else {
        // Якщо крапки немає, вважаємо весь залишок ім'ям файлу
        return fullPath.substr(startPos);
    }
}

int main() {
    // Введення повного шляху до файлу
    std::string fullPath;
    std::cout << "Введіть повний шлях до файлу: ";
    std::getline(std::cin, fullPath);

    // Витягнення імені файлу без розширення
    std::string fileNameWithoutExtension = extractFileNameWithoutExtension(fullPath);

    // Виведення результату
    std::cout << "Ім'я файлу без розширення: " << fileNameWithoutExtension << std::endl;

    return 0;
}
