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
