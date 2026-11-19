cmake_minimum_required(VERSION 3.15)
project(exercises)

# Define your common flags here
set(COMMON_FLAGS "-g -Wall -pedantic -Wuninitialized -Werror -fsanitize=address -fsanitize=undefined")
set(COMMON_CXX_FLAGS "-std=c++17")


# Apply the flags globally
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${COMMON_CXX_FLAGS} ${EXTRA}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS} ${EXTRA}")

# Add common linker flags
link_libraries(m)

# If you want to choose the compiler, when calling cmake use the following flags (clang in this case):
# cmake <path to CMakeLists.txt, usually ..> -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ 


# Add one line for each executable using the command add_executable(<name> <sources>)
add_executable(t1 t1.cpp)
add_executable(char-types char-types.cpp)
add_executable(fizz-buzz fizz-buzz.cpp)
add_executable(pi pi.cpp)
add_executable(primes primes.cpp)
add_executable(pernicious pernicious.cpp)
add_executable(adigits adigits.cpp)
add_executable(time-add time-add.cpp)
add_executable(equation equation.cpp)
add_executable(advance advance.cpp)
add_executable(bc bc.cpp)
add_executable(bell bell.cpp)
add_executable(time_of_day time_of_day.cpp)
add_executable(interval interval.cpp)
add_executable(fraction fraction.cpp)
add_executable(complex complex.cpp)
add_executable(mandelbrot mandelbrot.cpp)
add_executable(rotate-left rotate-left.cpp)
add_executable(common-letters common-letters.cpp)
add_executable(largest largest.cpp)
add_executable(expand expand.cpp)
add_executable(max max.cpp)
add_executable(merge-arrays merge-arrays.cpp)
add_executable(count-words count-words.cpp)
add_executable(wc wc.cpp)