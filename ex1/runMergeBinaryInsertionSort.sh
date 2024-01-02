#!/bin/sh
set -m
clear

print_usage() {
      echo "  1.  Run Sorting Algorithms"
      echo "  2.  Run Sorting Test with different K values"
      echo "  3.  Run Unity Tests"
      echo "  4.  Clear all output files"
}

print_info(){
    printf "Welcome to the Merge Binary Insertion Sort implementation (exercise 1) by Dario Bonfiglio and Alessandra Gullì!\n"
    printf "This script will compile and run the Merge Binary Insertion Sort implementation\n"
    printf "You can choose to run the Merge Binary Insertion Sort implementation, the Merge Binary Insertion Sort tests with different K values or the Unity tests\n"
    printf "You can also choose to clear the build/ folder\n"
    printf "Please select a number from the Main Menu [1-4] or select 'Q' to quit.\n"
    }

while true
do
    print_info
    print_usage
    echo

    printf "Please select a number: "
    read input

    case $input in
        1)
            echo "Running Merge Binary Insertion Sort implementation..."
            echo "Which field do you want to sort by?"
            echo "  1. String"
            echo "  2. Integer"
            echo "  3. Float"
            printf "Please select a number: "
            read field
            echo "Which K value do you want to use?"
            printf "K = "
            read k
            make -s run TYPE=$field K=$k
            exit 1
            ;;

        2)
            echo "Running Merge Binary Insertion Sort tests with different K values..."
            make -s run TYPE=0
            exit 1
            ;;

        3)
            echo "Running Unity tests..."
            make -s run_unityTest
            exit 1
            ;;

        4)
            make -s clear
            printf "build/ cleared successfully\n"
            exit 1
            ;;

        q)
            clear
            exit 1
            ;;

        *)
            clear
            echo "Invalid input!"
            echo "Please select a number from the Main Menu [1-4] or select 'Q' to quit."
            echo "Press any key to continue..."
    esac
done



