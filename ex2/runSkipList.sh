#!/bin/sh
set -m
clear

print_usage() {
      echo "  1.  Run SkipList Algorithm"
      echo "  2.  Run SkipList Algorithm with different Height values"
      echo "  3.  Run Unity Tests"
      echo "  4.  Clear all output files"
}

print_info(){
    printf "Welcome to the SkipList implementation (exercise 2) by Dario Bonfiglio and Inyan Fornaroli!\n"
    printf "This script will compile and run the SkipList implementation\n"
    printf "You can choose to run the SkipList Algorithm implementation, the SkipList Algorithm implementation with different Height values or the Unity tests\n"
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
            echo "Running the SkipList Algorithm implementation..."
            echo "Which Height value do you want to use?"
            printf "Height = "
            read test
            make -s run TEST=$test
            exit 1
            ;;

        2)
            echo "Running the SkipList Algorithm implementation with different Height values..."
            make -s run TEST=0
            exit 1
            ;;

        3)
            echo "Running Unity tests..."
            make -s run_unity
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



