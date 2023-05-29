#!/bin/bash


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
)

expected_outputs=(
    $'Valid Map'
    $'Error'
    $'Error\nInvalid map file extension, please provide a .ber file'
    $'Error\nInvalid map. Please provide a rectangular map'
    $'Error\nInvalid map. Please provide a rectangular map'
    $'Error\nInvalid map, please provide a map with just 1 0 E P C characters'
    $'Error\nInvalid map, please provide a map with a complete border made of obstacles'
    $'Error\nInvalid map, please provide a map with a complete border made of obstacles'
    $'Error\nInvalid map, please provide a map with a complete border made of obstacles'
    $'Error\nInvalid map, please provide a map with a complete border made of obstacles'
    $'Error\nInvalid map, please provide a map with a complete border made of obstacles'
    $'Error\nInvalid map, please provide a map with a complete border made of obstacles'
)




if [[ -n "$1" ]]; then
    # Run a specific test case if an argument is provided
    index=$(($1 - 1))

    if (( index >= 0 && index < ${#test_cases[@]} )); then
        test_cases=( "${test_cases[$index]}" )
        expected_errors=( "${expected_outputs[$index]}" )
        expected_leaks=( "${expected_leaks[$index]}" )
    else
        echo "Invalid test case number."
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
    #echo "Exit status: $exit_status"

    if [[ "$out_put" == "$expected_output" ]]; then
        echo "Test case \"$test_case\" passed." #\"$out_put\""
    else
        echo "Test case \"$test_case\" failed. Expected output: \"$expected_output\" Got \"$out_put\""
    fi

    if [[ "$valgrind_output" == *"$expected_leak"* ]]; then
        echo "Test case \"$test_case\" - No leaks message passed."
    else
        echo "Test case \"$test_case\" - No leaks message failed. Expected: \"$expected_leak\""
    fi

    echo ""
done