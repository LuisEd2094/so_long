#!/bin/bash
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

test_cases=(
    "ValidMap.ber"
    "no_per.ber"
    "invalid_ext.txt"
    "InvalidMap_Size.ber"
    "InvalidMap_Square.ber"
    "Invalid_char.ber"
    "InvalidMap_Border_1.ber"
    "InvalidMap_Border_2.ber"
    "InvalidMap_Border_3.ber"
    "InvalidMap_Border_4.ber"
    "InvalidMap_Border_5.ber"
    "InvalidMap_Border_6.ber"
    "Invalid_path_1.ber"
    "Invalid_path_2.ber"
    "Invalid_path_3.ber"
    "Invalid_path_4.ber"
    "Invalid_path_5.ber"
    "Invalid_no_collec.ber"
    "Invalid_no_exit.ber"
    "Invalid_no_player.ber"
    "Invalid_double_player.ber"
    "Invalid_double_exit.ber"
    "Bigger_map.ber"
)

expected_outputs=(
    $'Valid Map'
    $'Error'
    $'Error\nPlease provide a .ber file'
    $'Error\nPlease provide a rectangular map'
    $'Error\nPlease provide a rectangular map'
    $'Error\nProvide a map with just 1 0 E P C characters'
    $'Error\nProvide a map with a complete border made of obstacles'
    $'Error\nProvide a map with a complete border made of obstacles'
    $'Error\nProvide a map with a complete border made of obstacles'
    $'Error\nProvide a map with a complete border made of obstacles'
    $'Error\nProvide a map with a complete border made of obstacles'
    $'Error\nProvide a map with a complete border made of obstacles'
    $'Error\nCurrent map does not have a valid path'
    $'Error\nCurrent map does not have a valid path'
    $'Error\nCurrent map does not have a valid path'
    $'Error\nCurrent map does not have a valid path'
    $'Error\nCurrent map does not have a valid path'
    $'Error\nMust have at least 1 collectable and 1 player and 1 exit'
    $'Error\nMust have at least 1 collectable and 1 player and 1 exit'
    $'Error\nMust have at least 1 collectable and 1 player and 1 exit'
    $'Error\nMust have at least 1 collectable and 1 player and 1 exit'
    $'Error\nMust have at least 1 collectable and 1 player and 1 exit'
    $'Error\nMax map size is 20 x 12'
)




if [[ -n "$1" ]]; then
    # Run a specific test case if an argument is provided
    index=$(($1 - 1))

    if (( index >= 0 && index < ${#test_cases[@]} )); then
        test_cases=( "${test_cases[$index]}" )
        expected_errors=( "${expected_outputs[$index]}" )
        expected_leaks=( "${expected_leaks[$index]}" )
    else
        echo -e "Invalid test case number."
        exit 1
    fi
fi

for i in "${!test_cases[@]}"; do
    test_case="${test_cases[$i]}"
    expected_output="${expected_outputs[$i]}"
    out_put=$(./so_long maps/"$test_case")
    expected_leak="All heap blocks were freed -- no leaks are possible"

    valgrind_output=$(valgrind --leak-check=full ./so_long maps/"$test_case" 2>&1)
    #exit_status=$?
    #echo -e "Exit status: $exit_status"

    if [[ "$out_put" == "$expected_output" ]]; then
        echo -e "Test case \"$test_case\" ${GREEN}passed${NC}." #\"$out_put\""
    else
        echo -e "Test case \"$test_case\" ${RED}failed${NC}. Expected output: \"$expected_output\" Got \"$out_put\""
    fi

    if [[ "$valgrind_output" == *"$expected_leak"* ]]; then
        echo -e "Test case \"$test_case\" - No leaks message ${GREEN}passed${NC}."
    else
        echo -e "Test case \"$test_case\" - No leaks message ${RED}failed${NC}. Expected: \"$expected_leak\""
    fi

    echo -e ""
done