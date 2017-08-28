#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

// Глобавльная переменная, в которую будет записана функция в случае успеха.
void (*hello_message)(const char *);


/**
* Функция попытки загрузки библиотеки hello в Runtime.
* Возвращает успех операции.
*/
bool init_library() {

    // Подгружаем необходимую библиотеку при необходимости (RTLD_LAZY)
    void *hdl = dlopen("./libHello.so", RTLD_LAZY);
    if (NULL == hdl) return false;

    // Ищем в библиотеке фукнцию hello_message и преобразуем ее к нужному типу (по умолчанию *void)
    hello_message = (void (*)(const char*)) dlsym(hdl, "hello_message");
    if (NULL == hello_message) return false;

    return true;
}

int main() {

    if (init_library())
	    hello_message("Vasya"); // Если удалось загрузить библиотеку
	else
	    printf("Library was not loaded\n");

	return 0;
}
