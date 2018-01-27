!/bin/bash
cd assembler
make
cd ..
cd simulator/RISC-Simulator-master
make
cd ../..
./assembler/bin/assembler input.asm out.hex
./simulator/RISC-Simulator-master/bin/sim -input out.hex -output out.log
./simulator/RISC-Simulator-master/bin/sim -input out.hex -output pipe.log -pipe 
