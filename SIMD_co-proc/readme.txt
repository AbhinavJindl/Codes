----------------compile-------
$./run.sh

(change input file name from "input.asm" to required file.)

-------implementation---------------

1)Assembler:
	opcodes have been added.

2)Simulator:
	1)decode:
			 we have made a vector register file of 16 long long integers.
	         according to instruction, we read from register or vector file.
	2)execute:
			we have made a separate vector alu result pipeline register which stores the result of vector opertaions.
	3)ma:
			for vld memory was read twice for single instruction.
	4)wb:
			we have written to vector file or register file according to required instruction.
			
