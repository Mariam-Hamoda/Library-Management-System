cmake_minimum_required(VERSION 3.30)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library_Management_System main.cpp
        Books/clsBooks.cpp
        Books/clsBooks.h
        Books/clsBookManager.cpp
        Books/clsBookManager.h
        Books/clsBorrowedManager.h
        Books/BorrowRecord.h
        Files/clsBooksFile.h
        Files/UsersInfoFile.h
        Files/BorrowedBookFile.h
        Person/clsAdmin.cpp
        Person/clsAdmin.h
        Person/clsUser.cpp
        Person/clsUser.h
        Person/clsUsersManager.cpp
        Person/clsUsersManager.h
        Screens/clsScreenAdmin.h
        Screens/clsScreenUser.h
        InputOutput/clsInputOutputAdmin.cpp
        InputOutput/clsInputOutputAdmin.h
        InputOutput/InputOutputUser.cpp
        InputOutput/InputOutputUser.h
        Library/clsLibrary.h)
