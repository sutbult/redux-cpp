# Copyright (c) 2016 Samuel Utbult
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 2.8)
project(redux_cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(redux_cpp_tests
	${PROJECT_SOURCE_DIR}/tests/main.cpp
	${PROJECT_SOURCE_DIR}/tests/tests.cpp
)
add_executable(redux_counter_example
	${PROJECT_SOURCE_DIR}/examples/counter.cpp
)
add_executable(redux_counter_range_example
	${PROJECT_SOURCE_DIR}/examples/counter_range.cpp
)
set_property(TARGET redux_cpp_tests PROPERTY CXX_STANDARD 11)

enable_testing()
add_test(redux_cpp redux_cpp_tests)
