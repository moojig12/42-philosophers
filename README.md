# 42-philosophers
Philosophers, a project about mutex and threads.

## Project Guidelines

### Run-through

At a Roundtable sit philosophers with a fork between each individual philosopher__
at the center lies a plate of spaghetti.__
Each philosopher has pre-determined time to eat, think and die.__

### Requirements

philosophers cannot know the state of other philosophers.__
Global variables are forbidden.__
Each philosopher should be a thread.__
When a fork is picked up by one philosopher, it can't be picked up by the adjacent philosopher__
Any state change of a thread must be formatted as__
◦ timestamp_in_ms X has taken a fork__
◦ timestamp_in_ms X is eating__
◦ timestamp_in_ms X is sleeping__
◦ timestamp_in_ms X is thinking__
◦ timestamp_in_ms X died__
The displayed message must not be mixed up with another message.__
Announcement of death should not be more than 10ms later than the time of death.__
Race conditions must be avoided.__

### Bonus Requirements

Every philosopher must be a process. but the main process should not be a philosopher.__
All forks are placed in the center. accessible to every thread
represented as a semaphore(number of available forks), so the forks have no state in memory.__


-----------------------------

