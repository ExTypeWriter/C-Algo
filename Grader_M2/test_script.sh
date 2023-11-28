#!/bin/bash

# Compile the C code
compile_c_code() {
    gcc -o Euclid EuclidTwoPoint.c -lm
}

# Run the compiled program with a test case and check the output
run_test_case() {
    output=$(./Euclid < input.txt)
    expected_output=$(tail -n 1 input.txt)  # The expected output is the last line in the test case
    if [ "$(echo "$output" | awk '{printf "%.4f", $1}')" == "$expected_output" ]; then
        echo "Passed"
    else
        echo "Failed: Expected $expected_output, got $output"
    fi
}

# Clean up generated files
clean_up() {
    rm -f input.txt Euclid
}

# Main script
compile_c_code

for ((n = 3; n <= 20000; n += 1000)); do
    echo "Testing case with $n points:"
    echo "$n" > input.txt

    for ((i = 0; i < n; i++)); do
        x=$((RANDOM % 2001 - 1000))
        y=$((RANDOM % 2001 - 1000))
        echo "$x $y" >> input.txt
    done

    # Choose two random points to calculate the expected minimum distance
    point1=$(shuf -n 1 input.txt)
    point2=$(shuf -n 1 input.txt)
    expected_distance=$(echo "$point1 $point2" | awk '{dx=$1-$3; dy=$2-$4; print sqrt(dx*dx + dy*dy)}')

    echo -n "    "
    echo "Expected minimum distance: $expected_distance"
    run_test_case
done

clean_up
