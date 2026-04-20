#include "knet.h"
#include "debug.h"

params_t *params_init(void)
{
    params_t *self = malloc(sizeof(params_t));

    if (!self) ERROR("malloc failed");

    *self = (params_t)PARAMS_DEFAULTS;

    return (self);
}

void params_destroy(params_t *self)
{
    if (!self) return;
    free(self->host);
    free(self->ports);
    free(self);
}

void params_set_host(params_t *self, const char *host)
{
    if (!self) ERROR("self is null");
    free(self->host);
    self->host = strdup(host);
}

void params_set_ports(params_t *self, const char *ports)
{
    if (!self) ERROR("self is null");
    free(self->ports);
    self->ports = strdup(ports);
}

void params_set_tcp(params_t *self, bool tcp)
{
    if (!self) ERROR("self is null");
    self->tcp = tcp;
}

void params_set_syn(params_t *self, bool syn)
{
    if (!self) ERROR("self is null");
    self->syn = syn;
}

void params_set_udp(params_t *self, bool udp)
{
    if (!self) ERROR("self is null");
    self->udp = udp;
}

void params_print(const params_t *self)
{
    if (!self) ERROR("self is null");
    puts("params:");
    printf("  host: %s\n", self->host ? self->host : "(null)");
    printf("  ports: %s\n", self->ports ? self->ports : "(null)");
    printf("  tcp: %s\n", self->tcp ? "true" : "false");
    printf("  syn: %s\n", self->syn ? "true" : "false");
    printf("  udp: %s\n", self->udp ? "true" : "false");
    printf("  timeout: %d\n", self->timeout);
    printf("  threads: %d\n", self->threads);
    printf("  verbose: %s\n", self->verbose ? "true" : "false");    
}

// Test
/*int main(void)
{
    params_t *params = params_init();
    params_set_host(params, "localhost");
    params_set_ports(params, "80,443");
    params_print(params);
    params_destroy(params);
    return (0);
}*/
