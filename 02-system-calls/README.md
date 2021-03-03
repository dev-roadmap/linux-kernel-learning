# System Calls

Every Operating System has two main spaces. The **Kernel Space** and the **User Space**.

## User Space

When you write software that are complex tasks that you do not control. And those are tasks that you control. For example, if you want to read a file, you will not control the disk driver, but you want to access the data that came from the disk.

The codes that you want to control is the User Space. Is the code have total control. In the code below, you have control when closing a file, but you do not control how this file is closed.

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char ch, file_name[25];
   FILE *fp;

   printf("Enter name of a file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of %s file are:\n", file_name);

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
   return 0;
}
```

## Kernel Space

The Kernel Space is the opposite of User Space. It is the code that you do not want to control. Imagine the hard disk drivers, the network protocols, the treading systems, the memory allocation system, etc...

## What are System Calls?

System Calls are functions that when we call it we request something to the Operation System. This can be:
* Open a file
* Read a file
* Close a file
* Get running process PID

One of my blocking problems, when I start developing software, was knowing how to know about these functions. But this can be solved with the `man` command. The command `man` has all information you need to use some features from Linux. But it is broken into sections. 

* **Section 1**: [user commands](https://linux.die.net/man/1/)
* **Section 2**: [system calls](https://linux.die.net/man/2/)
* **Section 3**: [library functions](https://linux.die.net/man/3/)
* **Section 4**: [special files](https://linux.die.net/man/4/)
* **Section 5**: [file formats](https://linux.die.net/man/5/)
* **Section 6**: [games](https://linux.die.net/man/6/)
* **Section 7**: [conventions and miscellany](https://linux.die.net/man/7/)
* **Section 8**: [administration and privileged commands](https://linux.die.net/man/8/)

Let's use some funtion? I built a program that read the current PID, some file information and kill itself. Let's check which function are System Calls?

```C
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int pid = getpid();
    printf("My PID=%d\n", pid);
    uid_t uid = getuid();
    struct passwd *pwd = getpwuid(uid);
    printf("My UserId=%d username=%s\n", uid, pwd->pw_name);
    printf("I will kill myself...\n");
    kill(pid, SIGKILL);
    printf("Am I alive?");
    return 0;
}
```

| # | Function | Type | `man` description |
|:-:|----------|------|-------------------|
| 1 | getpid | System Call | process identification  |
| 2 | printf | Library Function | formatted output conversion |
| 3 | getuid | System Call | user identity |
| 4 | getpwuid | Library Function | password file entry |
| 5 | kill | System Call | send signal to process |

That means only 1, 3 and 5 are System Calls, so the other function does not access directly the **Kernel Space**.