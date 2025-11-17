/* gui_events.c - GUI event system for microui */

#include <xinu.h>

sid32 gui_event_sem = SYSERR;

/*------------------------------------------------------------------------
 * gui_events_init - initialize the GUI event system
 *------------------------------------------------------------------------
 */
void gui_events_init(void) {
    gui_event_sem = semcreate(0);  /* Start blocking - wait for events */
}

/*------------------------------------------------------------------------
 * gui_signal_event - signal that a GUI event occurred
 *------------------------------------------------------------------------
 */
void gui_signal_event(void) {
    if (gui_event_sem != SYSERR) {
        signal(gui_event_sem);
    }
}

/*------------------------------------------------------------------------
 * gui_signal_redraw - signal that an app window needs redraw
 *------------------------------------------------------------------------
 */
void gui_signal_redraw(int win_id) {
    /* Apps call this after updating their frame buffer */
    /* For now, just signal the main event - window ID unused */
    /* (Could add dirty flag optimization later) */
    gui_signal_event();
}
