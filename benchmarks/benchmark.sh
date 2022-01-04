#!/bin/bash

EXE="../src/proj"
INPUT="sequence"
OUTPUT_1="1.txt"
OUTPUT_2="2.txt"


write_to_file() {
	if [ "$1" == 1 ]; then
		./random_k 1 0 0.5 "$2" > "$INPUT"
	elif [ "$1" == 2 ]; then
		./random_k 2 0 0.5 "$2" "$2" > "$INPUT"
	fi
}

if [ "$1" == 1 ]; then
	touch "$OUTPUT_1"

	for size in $(seq 1 5000 100001); do
		sum_times=0

		for round in $(seq 0 4); do
			write_to_file 1 "$size"
			time=$({ time -p "$EXE" < "$INPUT"; } 2>&1 | grep "real" | awk '{print $2}')
			sum_times=$(echo "scale=3; ${sum_times} + ${time}" | bc -l)
		done

		average=$(echo "scale=3; ${sum_times} / 5" | bc -l)

		echo "$size $average" >> "$OUTPUT_1"
		echo "Finished benchmark for size "$size""
	done
fi

if [ "$1" == 2 ]; then
	touch "$OUTPUT_2"

	for size in $(seq 1 5000 100001); do
		sum_times=0

		for round in $(seq 0 4); do
			write_to_file 2 "$size"
			time=$({ time -p "$EXE" < "$INPUT"; } 2>&1 | grep "real" | awk '{print $2}')
			sum_times=$(echo "scale=3; ${sum_times} + ${time}" | bc -l)
		done

		average=$(echo "scale=3; ${sum_times} / 5" | bc -l)

		echo "$size $average" >> "$OUTPUT_2"
		echo "Finished benchmark for size "$size""
	done

fi
