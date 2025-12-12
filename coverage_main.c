#include "lwip/init.h"
#include "lwip/ip.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/mem.h"

int main(void) {
    lwip_init();

    struct tcp_pcb *pcb = tcp_new();
    if (pcb) {
        tcp_close(pcb);
    }

    struct udp_pcb *upcb = udp_new();
    if (upcb) {
        udp_remove(upcb);
    }

    mem_init();

    return 0;
}
