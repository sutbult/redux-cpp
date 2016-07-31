# Redux-cpp

A C++ implementation of the [Redux](http://redux.js.org/) library

## Installation

All Redux-cpp source code is contained within a single header. The easiet way to install Redux-cpp is simply to drop it inside your project.
Examples and unit tests can easiest be compiled with [CMake](https://cmake.org/).
The respository has no dependencies except the standard library.

## The Gist

An implementation of the [Redux Gist](https://github.com/reactjs/redux/blob/master/README.md#the-gist) in Redux-cpp:

```cpp
#include "redux.hpp"
#include <iostream>

enum Action {
	INCREMENT,
	DECREMENT
};

int reducer(int state, Action action) {
	switch(action) {
		case INCREMENT:
			return state + 1;

		case DECREMENT:
			return state - 1;

		default:
			return state;
	}
}

void log(int state) {
	std::cout << state << std::endl;
}

int main() {
	redux::Store<int, Action> store(reducer, 0);

	store.subscribe(log);

	store.dispatch(INCREMENT);
	// 1
	store.dispatch(INCREMENT);
	// 2
	store.dispatch(DECREMENT);
	// 1
}
```
