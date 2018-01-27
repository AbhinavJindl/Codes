.text
mov r0,.array 
mov r2,0
mov r3,0
.main:
vld v0,[r0]
vadd v1,v1,v0
add r0,r0,8
add r3,r3,1
add r5,r5,r0
cmp r3,4
beq .exit
b .main
.exit:
vmov2 r10,v1
lsr r1,r10,16
lsl r2,r10,16
lsr r2,r2,16
lsr r3,r11,16
lsl r4,r11,16
lsr r4,r4,16
add r1,r1,r2
add r1,r1,r3
add r1,r1,r4
.end
.data
.array:
0x00010002
0x00030004
0x00050006
0x00070008
0x0009000a
0x000b000c
0x000d000e
0x000f0000
