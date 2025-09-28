#include <stdio.h>
#include <unistd.h>   // for fork()
#include <sys/types.h> // for pid_t

int main() {
    int id1 = fork();   // First fork

    int id2 = fork();   // Second fork (executed by BOTH parent and child1)

    if (id1 == 0) {  // This branch is for child1 and its children
        if (id2 == 0) {
            // Child of Child1 → "y"
            printf("We are process y\n");
        } else {
            // Just Child1 → "x"
            printf("We are process x\n");
        }
    } else {
        if (id2 == 0) {
            // Child of Parent (via second fork) → "z"
            printf("We are process z\n");
        } else {
            // The original parent process
            printf("We are the parent process!\n");
        }
    }

    return 0;
}
