# Libft

Project for [42 Roma Luiss](https://42roma.it/) 

The aim of this project is to code a C library regrouping usual functions that you’ll be allowed to use in all your other projects.

### Description

This project is your very first project as a student at 42.

You will need to recode a few functions of the C standard library as well as some other utility functions
that you will use during your whole cursus.

## Getting Started

The project inside the folder [Libft_v1](Libft_v1) refers to an initial and much older version, tested only on the Mac OS operating system.

In the main folder, we find a recent version of the project developed and tested on a Linux environment.

See the subjects for further information:

[SUBJECTS of old project](Resources/Libft_v1)

[SUBJECT of new project](Resources)

The repository contains a main, usefull to test the functions.

### Build the library

The following command builds the library, without the bonus functions
```
make re
```


The following command builds the complete library, also with the bonus functions
```
make bre
```


For testing the library with the main, use this command:
```
gcc -Wall -Werror -Wextra -L . -lft main_libft.c
```
