# CMakeList.txt: проект CMake для PELENG_TEST; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (PELENG_TEST "main.cpp"  "CycledQueue.h" "CycledQueue.cpp" "QueueIterator.h" "QueueNode.h" "QueueNode.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
