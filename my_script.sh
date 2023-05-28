#!/bin/bash


test(){
    ./so_long 
    exit_status=$?
    echo "Exit status: $exit_status"

    valgrind --leak-check=full ./so_long maps/ValidMap.ber
    exit_status=$?
    echo "Exit status: $exit_status"

    ./so_long maps/no_per.txt
    exit_status=$?
    echo "Exit status: $exit_status"

    valgrind --leak-check=full ./so_long maps/InvalidMap_Size.ber
    exit_status=$?
    echo "Exit status: $exit_status"
    
    valgrind --leak-check=full ./so_long maps/InvalidMap_Square.ber
    exit_status=$?
    echo "Exit status: $exit_status"
}


test
