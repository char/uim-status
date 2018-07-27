#include <uim/uim.h>
#include <uim/uim-helper.h>

#include <stdlib.h>
#include <stdio.h>

void exit_uim_status(void) {
    exit(1);
}

int main(void) {
    int uim_fd = uim_helper_init_client_fd(&exit_uim_status);
    uim_helper_send_message(uim_fd, "im_list_get\n");

    while (1) {
        uim_helper_read_proc(uim_fd);
        char *msg = uim_helper_get_message();

        if (msg != NULL) {
            puts(msg);
            free(msg);

            break;
        }
    }

    uim_helper_close_client_fd(uim_fd);
    return 0;
}
