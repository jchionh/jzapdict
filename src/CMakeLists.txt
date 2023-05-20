add_executable(${PROJECT_NAME} main.cpp WordDict.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime)