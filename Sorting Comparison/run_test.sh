#!/bin/bash

# Number of times to run the test.
N=10

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Blinking text
Blink='\033[5m'

# Input file
input_file="test_int.txt"

# Compile the C code
gcc -o sort_test QuickSort.c

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo -e "${Green}Compilation successful${Color_Off}"

    # Create a text file to store the results
    result_file="result.txt"
    rm -f "$result_file"  # Remove existing file if it exists

    total_execution_time=0 
    total_cpu_usage=0 
    total_mem_usage=0

    echo "Running the program with input from $input_file"

    for ((i=1; i<=N; i++)); do
        if [ $i -eq 1 ]; then
            echo -e "${i}st Run:"
        elif [ $i -eq 2 ]; then
            echo -e "${i}nd Run:"
        elif [ $i -eq 3 ]; then
            echo -e "${i}rd Run:"
        else
            echo -e "${i}th Run:"
        fi

        # Record start time and CPU usage
        start_time=$(date +%s.%N)
        start_cpu=$(grep 'cpu ' /proc/stat | awk '{usage=($4)*100/($2+$3+$4+$5+$6+$7+$8+$9+$10+$11) } END {print usage}')

        ./sort_test < "$input_file"

        # Record end time and CPU usage
        end_time=$(date +%s.%N)
        end_cpu=$(grep 'cpu ' /proc/stat | awk '{usage=($4)*100/($2+$3+$4+$5+$6+$7+$8+$9+$10+$11) } END {print usage}')

        # Calculate execution time in milliseconds
        execution_time=$(echo "scale=3; ($end_time - $start_time) * 1000" | bc)
        
        # Calculate CPU usage
        cpu_usage=$(awk "BEGIN {printf \"%0.5f\", ($end_cpu - $start_cpu)}")

        # Calculate memory usage
        mem_usage=$(pmap -x $$ | tail -n 1 | awk '{print $3}')

        # Append results to the text file
        printf "Run %d - Execution time: %.3f milliseconds, CPU usage: %s%%, Memory usage: %s KB\n" $i $execution_time $cpu_usage $mem_usage >> "$result_file"
        echo "----------------------------------------" >> "$result_file"

        # Accumulate total execution time, CPU usage, and memory usage
        total_execution_time=$(echo "$total_execution_time + $execution_time" | bc)
        total_cpu_usage=$(echo "$total_cpu_usage + $cpu_usage" | bc)
        total_mem_usage=$(echo "$total_mem_usage + $mem_usage" | bc)
        echo -e "${Green}Pass${Color_Off}"
    done

    # Calculate average execution time, CPU usage, and memory usage
    average_execution_time=$(echo "scale=3; $total_execution_time / $N" | bc)
    average_cpu_usage=$(echo "scale=5; $total_cpu_usage / $N" | bc)
    average_mem_usage=$(echo "scale=3; $total_mem_usage / $N" | bc)

    echo -e "${Cyan}Average Execution Time: $average_execution_time milliseconds${Color_Off}"
    echo -e "${Cyan}Average CPU usage: $average_cpu_usage%${Color_Off}"
    echo -e "${Cyan}Average Memory usage: $average_mem_usage KB${Color_Off}"

    echo -e "\033[33;5mResults saved in $result_file${Color_Off}"
else
    echo -e "${Red}Compilation failed${Color_Off}"
fi
