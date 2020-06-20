# ftrace
This program allows an executable to be analyzed during execution by showing **functions calls**, **syscalls** and **received signals**.  
Only **86-64 architecture** and a Linux distribution is supported.  

I've really loved to code this project because we've learned a lot about Intel processors, how they can fetch the good function at the wanted time, we've learnt some things such as the **PLT**, the **GOT** and how **ELF format** works. All theses things were really interesting to learn.  

**Group members:**  
  - [@Exylar](https://github.com/Exylar)
  - [@HeyShafty](https://github.com/HeyShafty)
  - [@Kilio22](https://github.com/Kilio22)

# How to use it ?
Clone the project and run this command to compile the program:
```sh
$> make
```
Now run this one and replace `program` by the path (or simply the program's name if it can be found using $PATH environnement variable) of the program you want to trace:
```sh
$> ./ftrace <command>
```
Exemple:
```sh
$> ./ftrace ls
```
