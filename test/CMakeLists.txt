set(SRCS "mainTest.cpp" "mainTest2.cpp")

enable_testing()

foreach (test ${SRCS})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS})
    add_test(${testName} ${testName})
endforeach ()
