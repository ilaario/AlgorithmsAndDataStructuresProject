#!/bin/sh
set -m
clear

print_usage() {
      echo "  1.  Run Prim's Algorithm implementation"
      echo "  2.  Run GraphLibrary tests"
      echo "  3.  Run PriorityQueue tests"
      echo "  4.  Clear classes/ folder"
}

print_info(){
  printf "Welcome to Prim's Algorithm and Generic Priority Queue implementations (exercise 3 and 4) by Dario Bonfiglio and Alessandra Gullì!\n"
  printf "This script will compile and run the Prim's Algorithm implementation\n"
  printf "You can choose to run the Prim's Algorithm implementation, the GraphLibrary tests or the PriorityQueue tests\n"
  printf "You can also choose to clear the classes/ folder\n"
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
            clear
            printf "Running Prim Algorithm with input file: italian_dist_graph.csv\n"
            cd ./src || exit
            printf "Compiling..."
            javac -d ../classes/ -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar Graph/*.java
            javac -d ../classes/ -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar GenericPriorityQueue/*.java
            javac -d ../classes/ -cp .:Graph:GenericPriorityQueue:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar Prim/*.java
            printf "  Done!\n"

            cd .. || exit
            printf "Running Main...\n\n"
            cd ./classes || exit
            java Prim.Prim "../input/italian_dist_graph.csv"
            printf "Done! Exiting...\n"
            cd .. || exit
            exit 1
            ;;

        2)
            clear
            printf "Running Graph Tests with JUnit tests\n"
            cd ./src || exit
            printf "Compiling..."
                        javac -d ../classes/ -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar Graph/*.java
            javac -d ../classes/ -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar GenericPriorityQueue/*.java
            javac -d ../classes/ -cp .:Graph:GenericPriorityQueue:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar Prim/*.java
            printf "  Done\n"

            cd .. || exit
            printf "Running Graph Tests...\n\n"
            cd ./classes || exit
            java -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar Graph/GraphJUnitRunner
            printf "Done! Exiting...\n"
            cd .. || exit
            exit 1
            ;;

        3)
            clear
            printf "Running PriorityQueue tests with JUnit tests\n"
            cd ./src || exit
            printf "Compiling..."
            javac -d ../classes/ -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar Graph/*.java
            javac -d ../classes/ -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar GenericPriorityQueue/*.java
            printf "Done"

            cd .. || exit
            printf "Running PriorityQueue Tests...\n\n"
            cd ./classes || exit
            java -cp .:../lib/junit-4.12.jar:../lib/hamcrest-core-1.3.jar GenericPriorityQueue/GPQjunitRunner
            printf "Done! Exiting...\n"
            cd .. || exit
            exit 1
            ;;

        4)
            clear
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
            echo "Press any key to continue..."
    esac
done



