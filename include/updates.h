#ifndef UPDATES_H
#define UPDATES_H

#include <stdbool.h>

/*
 * actions that the client will be required to perform
 */
typedef struct {
	int *board; // handle to the board state
	int hold; // hold piece
	int *queue; // handle to the next queue
	int curcolor; // active piece color
	bool redraw; // if hold/next queue need to be redrawn
	long timeout; // max amount of time (ms) before the game should be polled again
	char *action; // action text after line clear (e.g. "single")
} Updates;

/*
 * create an update packet
 */
Updates *updates_create();

/*
 * destroy an update packet
 */
void updates_destroy(Updates *updates);

/*
 * flag a redraw of the hold piece and piece queue
 */
void updates_flag_redraw(Updates *updates);

/*
 * poll and clear the hold/queue redraw flag
 */
bool updates_poll_redraw(Updates *updates);

#endif
