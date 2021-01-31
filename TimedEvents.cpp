#include "TimedEvents.h"

namespace sdds 
{
	TimedEvents::TimedEvents()
	{
		te_current_records = { 0 };
		te_start = {};
		te_end = {};
		events->te_name = {};
		events->te_time = {};
		events->te_duration = {};
	}

	void TimedEvents::startClock()
	{
		te_start = chrono::steady_clock::now();
	}

}