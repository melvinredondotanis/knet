#ifndef KNET_H
#define KNET_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct params_s {
    char *host;
    char *ports;
    bool tcp;
    bool syn;
    bool udp;
    int timeout;
    int threads;
    bool verbose;
};

#define PARAMS_DEFAULTS { \
    .host = NULL, \
    .ports = NULL, \
    .tcp = true, \
    .syn = false, \
    .udp = false, \
    .timeout = 3, \
    .threads = 10, \
    .verbose = false \
}

typedef struct params_s params_t;

params_t *params_init(void);
void params_print(const params_t *self);
void params_destroy(params_t *self);
void params_set_host(params_t *self, const char *host);
void params_set_ports(params_t *self, const char *ports);
void params_set_tcp(params_t *self, bool tcp);
void params_set_syn(params_t *self, bool syn);
void params_set_udp(params_t *self, bool udp);

#endif // KNET_H
