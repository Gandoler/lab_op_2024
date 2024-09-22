#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/* Определение макроса для вывода адреса переменной */
#define SHW_ADR(ID, I) (printf("ID %s \t is at virtual address: %p\n", ID, (void *)&I))

/* Внешние переменные для памяти процесса */
extern int etext, edata, end; /* Эти переменные должны быть объявлены как символы, а не целые */

/* Статическая строка */
char *cptr = "This message is output by the function showit()\n"; /* Статическая переменная */
char buffer1[25]; /* Массив символов */

/* Прототип функции */
int showit(char *p); /* Нужно добавить тип параметра */

int main() {
  int i = 0; /* Автоматическая переменная */

  /* Вывод информации о памяти */
  printf("\nAddress etext: %p \n", (void *)&etext);
  printf("Address edata: %p \n", (void *)&edata);
  printf("Address end  : %p \n", (void *)&end);

  SHW_ADR("main", main);
  SHW_ADR("showit", showit);
  SHW_ADR("cptr", cptr);
  SHW_ADR("buffer1", buffer1);
  SHW_ADR("i", i);

  strcpy(buffer1, "A demonstration\n");   /* Функция стандартной библиотеки */
  write(1, buffer1, strlen(buffer1)); /* Системный вызов, убираем +1 для правильного вывода */
  showit(cptr);

  return 0; /* Возвращаем 0 в main для корректного завершения */
}

/* Определение функции */
int showit(char *p) {
  char *buffer2;
  SHW_ADR("buffer2", buffer2);

  if ((buffer2 = (char *)malloc(strlen(p) + 1)) != NULL) {
    printf("Allocated memory at %p\n", (void *)buffer2);
    strcpy(buffer2, p);    /* Копируем строку */
    printf("%s", buffer2); /* Выводим строку */
    free(buffer2);         /* Освобождаем память */
  } else {
    printf("Allocation error\n");
    exit(1);
  }

  return 0; /* Добавляем возврат значения */
}