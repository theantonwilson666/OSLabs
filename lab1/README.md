## Лабораторная работа №1

***

 ***Задание*** : написать программу на языке C [1] c использование POSIX
[2] системных вызовов, которая реализует базовый функционал оболочки.
Программа должна в бесконечном цикле считывать команды пользователя
и запускать соответствующие им программы. Завершать работу следует
при возникновении ситуации «конец файла».

***

***Комментарий***: компиляция: **make lab1**, запуск: **./lab1** ,
Массив строк работает динамично, **execvp** принимает комманду и аргументы, **execlp** работает если аргументов нету.
