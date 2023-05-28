#!/bin/bash


test(){
    valgrind --leak-check=full ./so_long 
    exit_status=$?
    echo "Exit status: $exit_status"

    valgrind --leak-check=full ./so_long maps/ValidMap.ber
    exit_status=$?
    echo "Exit status: $exit_status"

    valgrind --leak-check=full ./so_long maps/no_per.ber
    exit_status=$?
    echo "Exit status: $exit_status"

    valgrind --leak-check=full ./so_long maps/invalid_ext.txt
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
