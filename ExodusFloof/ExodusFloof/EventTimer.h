/* 
 *  This is a an event based timer
 *  The timer can be reset or can increment the it's current time
 *  by the length of the timer (so to not miss a tick)
 *
 *  Code by: Sebastian Zander
 *  September 2012
 */

#ifndef EVENTTIMER_H
#define EVENTTIMER_H

#include <ctime>

class EventTimer
{
public:
	EventTimer(double MSTick);
	EventTimer();
	~EventTimer();
	 
	/* this is used to change the length of the tick after creation
	*/
	void SetTickLength(double newMSTick, bool reset = true);

	/* returns true if the timer has ticked since the last reset (or tick increment)
	*/ 
	bool ReadTick() const;				
	
	/* increments the time by the length of one tick, for event based timing
	*/
	void AddTick();		

	/* resets the time
	*/
	void Reset();												
private:
	/* this keeps track of the time*
	*/
	std::clock_t timer;

	/* this is the length of each tick
	*/
	long timerLength;
};

#endif