# get_next_line

## Описание

get_next_line - второй проект в School 21. Будь то файл, стандартный ввод или даже сетевое соединение, вам всегда понадобится способ чтения содержимого построчно. Пришло время начать работу над этой функцией, которая будет необходима для ваших будущих проектов.

В этом проекте мы используем некоторые функции из libft, так же некоторые функции мы модифицируем.

Компилирование было с флагами: ``gcc -Wall -Wextra -Werror``.

Все файлы проходят на ``Norminette``.

## Оценка

![alt tag](https://downloader.disk.yandex.ru/preview/4631d8b6083309f4849db081d6d566546dc57a130b028c83448849e0720cf9e1/5fbc45d8/tm800Zmi4lNeiRSoOKmIZVEY-chzlEpMqJAkxRwUjdDXcUdOUxcOqVkFl1NrL_6R_nldH5qDsOawB6Or4f5vSw%3D%3D?uid=0&filename=appraisal_get_next_line.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&owner_uid=0&tknv=v2&size=2048x2048 "Оценка проекта get_next_line")

## my_test

Закидываем ``main.c`` и ``text.txt`` в папку с ``get_next_line``, после чего компилируем ``gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c``. Запускаем ``a.out``, так же можем проверить на лики с помощью команды ``leaks a.out``.
