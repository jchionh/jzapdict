cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "~/out")
project(jzapdict LANGUAGES CXX)

find_package(aws-lambda-runtime REQUIRED)

add_subdirectory(src)

aws_lambda_package_target(${PROJECT_NAME})