#!/usr/bin/env bash

STEPS=(10 20 50 100 200 500 1000 2000 2500 3000 4000)
CONFIGS=(build-debug build-release build-openmp-release)
for config in ${CONFIGS[*]}
do
    echo "Starting '$config'..."

    for step in ${STEPS[*]}
    do
        time "./$config/bin/money" $step
        echo "====================================="
        echo
    done 2>&1 | tee "results/$config.txt"

    echo "Done"
    echo
done
