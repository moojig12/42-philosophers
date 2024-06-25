# 42-philosophers
Philosophers, a project about mutex and threads.

## Project Guidelines

### Run-through

At a Roundtable sit philosophers with a fork between each individual philosopher  
at the center lies a plate of spaghetti.  
Each philosopher has pre-determined time to eat, think and die.  
### Requirements

philosophers cannot know the state of other philosophers.  
Global variables are forbidden.  
Each philosopher should be a thread.  
When a fork is picked up by one philosopher, it can't be picked up by the adjacent philosopher.  
Any state change of a thread must be formatted as

◦ timestamp_in_ms X has taken a fork  
◦ timestamp_in_ms X is eating  
◦ timestamp_in_ms X is sleeping  
◦ timestamp_in_ms X is thinking  
◦ timestamp_in_ms X died  

The displayed message must not be mixed up with another message.  
Announcement of death should not be more than 10ms later than the time of death.  
Race conditions must be avoided.

More than 200 philosophers may not be tested in Evaluation.

### Bonus Requirements

Every philosopher must be a process. but the main process should not be a philosopher.  
All forks are placed in the center. accessible to every thread
represented as a semaphore(number of available forks), so the forks have no state in memory.


-----------------------------

