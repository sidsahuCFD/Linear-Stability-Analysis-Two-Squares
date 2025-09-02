#!/bin/bash

# chmod +x SC_run.sh

log_file="loop_times.log"

# Clear the log file if it exists
#> $log_file

# Capture the start time in seconds since epoch
start_time=$(date +%s)
start_time_human=$(date +'%Y-%m-%d %H:%M:%S')
 
readUd
decomposePar
mpirun -np 32 SC_Linearised -case $HOME/PhD/OpenFOAM/SC_ARPACK/Mesh2/run_stept050_8eigs
reconstructPar
writeUd050
  rm -r processor0
  rm -r processor1
  rm -r processor2
  rm -r processor3 
  rm -r processor4
  rm -r processor5
  rm -r processor6
  rm -r processor7  
  rm -r processor8
  rm -r processor9
  rm -r processor10
  rm -r processor11  
  rm -r processor12
  rm -r processor13
  rm -r processor14
  rm -r processor15
  rm -r processor16
  rm -r processor17
  rm -r processor18
  rm -r processor19
  rm -r processor20
  rm -r processor21
  rm -r processor22
  rm -r processor23 
  rm -r processor24
  rm -r processor25
  rm -r processor26
  rm -r processor27  
  rm -r processor28
  rm -r processor29
  rm -r processor30
  rm -r processor31 
 
# Capture the end time in seconds since epoch
end_time=$(date +%s)
end_time_human=$(date +'%Y-%m-%d %H:%M:%S')
 
# Calculate the duration of the iteration
duration=$((end_time - start_time))
 
# Write the information to the log file
  
echo "Iteration $i took $duration seconds" >> $log_file
echo "---------------------------" >> $log_file
echo 

