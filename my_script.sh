#!/bin/bash


test(){

    ./so_long 
    exit_status=$?
    echo "Exit status: $exit_status"

    ./so_long maps/map1.ber
    exit_status=$?
    echo "Exit status: $exit_status"

    ./so_long maps/no_per.txt
    exit_status=$?
    echo "Exit status: $exit_status"

}


test
