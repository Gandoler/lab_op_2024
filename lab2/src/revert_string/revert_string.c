#include "revert_string.h"
#include <stdio.h>

void RevertString(char *str) {
    // Указатель на начало строки
    char *start = str;
    
    // Найдём конец строки
    char *end = str;
    while (*end != '\0') {
        end++;
    }
    end--; // Переместим на последний символ строки (до нуль-терминатора)
    
    // Разворачиваем строку
    while (start < end) {
        // Обмен символов
        char temp = *start;
        *start = *end;
        *end = temp;
        
        // Сдвигаем указатели
        start++;
        end--;
    }
}