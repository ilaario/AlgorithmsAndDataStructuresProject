#!/bin/sh
set -m
clear

print_usage() {
      echo "  1.  Run Ex1"
      echo "  2.  Run Ex2"
      echo "  3.  Run Ex3/4"
      echo "  4.  Clear all output files"
}

print_info(){
    printf "Welcome to Algorithms and Data Structures Project by Dario Bonfiglio and Alessandra Gullì!\n"
    printf "This script will compile and run all 4 exercises\n"
    printf "You can choose to run the merge_binary_insertion_sort implementation, the SkipList implementation or the GenericPriorityQueue/Prim implementation\n"
    printf "Please select a number from the Main Menu [1-3] or select 'Q' to quit.\n"
}

pause(){
 read -s -n 1 -p "Press any key to continue..."
 echo ""
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
            cd ./ex1 || exit
            sh runMergeBinaryInsertionSort.sh
            exit 1
            ;;

        2)
            cd ./ex2 || exit
            sh runSkipList.sh
            exit 1
            ;;

        3)
            cd ./ex3-4 || exit
            sh runPrim.sh
            exit 1
            ;;

        4)
            cd ./ex1 || exit
            make -s clear
            cd ../ex2 || exit
            make -s clear
            cd ../ex3-4 || exit
            rm -rf classes/*
            printf "classes/ cleared successfully\n"
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
            pause
            clear
    esac
done



