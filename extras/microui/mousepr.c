#include <xinu.h>

process	mousepr(int * mouse_buf_pt)
{
	open(MOUSE, NULL, 0);

	while (TRUE) {
        read(MOUSE, mouse_buf_pt, sizeof(mousec.mouse));
		gui_signal_event();  /* wake GUI to process mouse input */
    }

	close(MOUSE);

    return OK;
}
