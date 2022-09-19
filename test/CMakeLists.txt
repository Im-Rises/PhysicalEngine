set(SRCS_TEST "mainTest.cpp" "mainTest2.cpp")

set(HEADERS)
set(SRCS)

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
