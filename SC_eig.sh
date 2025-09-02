#!/bin/sh 
#PBS -l walltime=72:00:00,select=1:ncpus=32:mpiprocs=32:mem=1000gb 

module load tools/prod
module load OpenFOAM/10-foss-2022a-20230119
source $FOAM_BASH

#Loading Python

#module load anaconda3/personal
#source activate py39
module load SciPy-bundle/2022.05-foss-2022a

cd $PBS_O_WORKDIR

log_file="loop_times.log"

# Clear the log file if it exists
> $log_file

#compile solver over 1 processor
wclean $PBS_O_WORKDIR/solvers/readUd/ 
wmake $PBS_O_WORKDIR/solvers/readUd/

wclean $PBS_O_WORKDIR/solvers/SC_Linearised/
wmake $PBS_O_WORKDIR/solvers/SC_Linearised/

wclean $PBS_O_WORKDIR/solvers/writeUd050/
wmake $PBS_O_WORKDIR/solvers/writeUd050/

chmod +x SC_run.sh
python3 eig.py

#conda deactivate
#chmod +x SC_run.sh

