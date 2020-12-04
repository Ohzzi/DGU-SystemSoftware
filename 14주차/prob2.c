#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;
    char c;
    fd1 = open("foo.txt", O_RDONLY);
    fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while(read(fd1, &c, 1) != 0) {
        int d = write(fd2, &c, 1);
    }

    close(fd1);
    close(fd2);

    return 0;
}