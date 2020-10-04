#!/bin/bash

read ch

printf "%.3f" $(echo "scale=4; $ch" | bc)