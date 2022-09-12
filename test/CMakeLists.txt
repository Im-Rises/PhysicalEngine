set(SRCS "mainTest.cpp")
set(HEADERS)

enable_testing()

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

add_test(${PROJECT_NAME} ${PROJECT_NAME})
