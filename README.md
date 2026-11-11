*This project has been created as part of the 42 curriculum by jcole.*

# get_next_line

## Description

`get_next_line` is a C function that reads a file descriptor and returns one line each time it is called. The goal is to learn about file descriptors, `read()`, `malloc` and static variables.

```c
char *get_next_line(int fd);
```

It returns the line including the `\n` (if there is one), or `NULL` at the end of the file or on error.

I used the GNLTester by Tripouille found at https://github.com/Tripouille/gnlTester

## Instructions

Compile with your own `main.c` and choose a `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
./a.out
```

Every returned line is allocated with `malloc`, so you must `free` it.

## Algorithm

I keep the text that was read but not yet returned in a static variable called `saved`. Each call does three steps:

1. **Read:** read `BUFFER_SIZE` bytes at a time and add them to `saved` until it contains a `\n` or the file ends.
2. **Extract:** copy everything up to and including the first `\n` into a new string. This is the line that is returned.
3. **Update:** keep only the text after that line in `saved` for the next call.

I chose a static variable because `read()` may read past the end of the current line, and the extra text has to be kept for the next call. Reading in chunks means the function works with any line length and any `BUFFER_SIZE`.

## Resources

Tutorials and explainations were from Stack Overflow, Youtube, W3School, Google, 42 Peers

**Use of AI:** I used Claude to help split my function so it fits the Norm's 25-line limit, to understand Valgrind errors (a `NULL` bug in `my_strjoin`), and to help write this README. I wrote the algorithm myself and tested and understood all the code.