#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

#define DEBUG(msg, ...) \
    fprintf(stderr, COLOR_BLUE "[DEBUG]" COLOR_RESET " %s() - " msg "\n", \
            __func__, ##__VA_ARGS__)

#define INFO(msg, ...) \
    fprintf(stderr, COLOR_GREEN "[INFO]" COLOR_RESET " %s() - " msg "\n", \
            __func__, ##__VA_ARGS__)

#define WARN(msg, ...) \
    fprintf(stderr, COLOR_YELLOW "[WARN]" COLOR_RESET " %s() - " msg "\n", \
            __func__, ##__VA_ARGS__)

#define ERROR(msg, ...) \
    fprintf(stderr, COLOR_RED "[ERROR]" COLOR_RESET " %s:%d - " msg "\n", \
            __func__, __LINE__, ##__VA_ARGS__)

#endif // DEBUG_H
