*This project has been created as part of the 42 curriculum by msimoes*

## Description
The Philosophers project represents a classic synchronization problem in computer science, also known as the "Dining Philosophers Problem". This project simulates philosophers sitting at a round table, who must eat, think and sleep while sharing a limited number of forks. Each philosopher brings with him one fork, and to be able to eat, each philosopher needs to use two forks.

The goal of this project is to learn about the basics of threading and mutexes while solving a resource-sharing problem where all philosophers must coordinate to access shared resources (forks) without causing deadlocks or starvation.
The simulation ends when a philosopher dies of starvation or when all philosophers have eaten the required number of times.

## Instructions

### Compilation
To compile the projet simply run:
```bash
make
```
To recompile everything run:
```bash
make re
```

Both of these will create a `philo` executable.

### Usage
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_repeats]
```

### Argumets
- `number_of_philosophers`: Number of philosophers and forks used on the simulation
- `time_to_die`: Time in miliseconds before a philosophers dies if they haven't eaten
- `time_to_eat`: Time in miliseconds a philosopher takes to eat
- `time_to_sleep`: Time in miliseconds a philosophers takes to sleep
- `[number_of_repeats]`: Number of times all philosophers should eat to stop the simultaion (Optional argument)

### Examples
Basic philosopher simulation:
```bash
./philo 5 800 200 200
```
This will create a simulation with 5 philosophers which have 800ms to eat before dying, eating takes 200ms and sleeping 200ms.
```bash
./philo 5 800 200 200 7
```
The same has above but will stop after 7 repeats.

### Cleanup
Remove object files:
```bash
make clean
```
Remove object files and executable:
```bash
make fclean
```

## Resources
- [Dining Philosophers problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Unix Threads playlist - Youtube Code Vault](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [Thread and Mutex manual](https://www.man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)

### AI usage
No AI was used to write the code of this project. AI was only used to find problems with the code and suggest fixes.
It was also used to make a draft for the README.