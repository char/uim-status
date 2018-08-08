#include <uim/uim.h>
#include <uim/uim-helper.h>

#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

void exit_uim_status(void) {
    exit(1);
}

char* get_uim_helper_response(int uim_fd) {
    for (;;) {
        uim_helper_read_proc(uim_fd);
        char *msg = uim_helper_get_message();

        if (msg != NULL) {
            return msg;
        }

        sched_yield();
    }
}

int main(void) {
    int uim_fd = uim_helper_init_client_fd(&exit_uim_status);

    uim_helper_send_message(uim_fd, "prop_list_get\n");
    char* msg = get_uim_helper_response(uim_fd);
    puts(msg);
    free(msg);

    uim_helper_close_client_fd(uim_fd);
    return 0;
}
