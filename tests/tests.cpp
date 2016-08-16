/*
Copyright (c) 2016 Samuel Utbult

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "redux.hpp"
#include "catch.hpp"
#include <iostream>

using namespace redux;

enum CounterAction {
	INCREMENT,
	DECREMENT
};

int counterReducer(int state, CounterAction action) {
	switch(action) {
		case INCREMENT:
			return state + 1;

		case DECREMENT:
			return state - 1;

		default:
			return state;
	}
}

int counterTemp[2];
void counterSubscriber(int n) {
	counterTemp[0] = n;
}
void secondCounterSubscriber(int n) {
	counterTemp[1] = n;
}

TEST_CASE("A simple counter", "[redux]") {
	Store<int, CounterAction> store(counterReducer, 0);

	SECTION("The counter increments once") {
		store.dispatch(INCREMENT);
		REQUIRE(store.getState() == 1);

		SECTION("The counter increments a second time") {
			store.dispatch(INCREMENT);
			REQUIRE(store.getState() == 2);
		}
		SECTION("The counter decrements") {
			store.dispatch(DECREMENT);
			REQUIRE(store.getState() == 0);
		}
	}
	SECTION("The counter decrements once") {
		store.dispatch(DECREMENT);
		REQUIRE(store.getState() == -1);
	}
	SECTION("The store can be subscribed to") {
		store.subscribe(counterSubscriber);
		store.dispatch(INCREMENT);
		REQUIRE(counterTemp[0] == 1);

		SECTION("With two subscribers") {
			store.subscribe(secondCounterSubscriber);
			store.dispatch(INCREMENT);
			REQUIRE(counterTemp[0] == 2);
			REQUIRE(counterTemp[1] == 2);
		}
	}
	#if __HAS_CPP11_SUPPORT
	SECTION("The store can be subscribed to with an anonymous subscriber") {
		int actual;
		store.subscribe([&] (int state) {
			actual = state;
		});
		store.dispatch(INCREMENT);
		REQUIRE(actual == 1);
	}
	#endif
}
