User Text Segment [00400000]..[00440000]
[00400000] 8fa40000  lw $4, 0($29)            ; 183: lw $a0 0($sp) # argc               ;$29 = 0                lw = register, ram
[00400004] 27a50004  addiu $5, $29, 4         ; 184: addiu $a1 $sp 4 # argv             ;$5 = 0 + 4             addiu = addtwo registers and store it
[00400008] 24a60004  addiu $6, $5, 4          ; 185: addiu $a2 $a1 4 # envp             ;$6 = 4 + 4
[0040000c] 00041080  sll $2, $4, 2            ; 186: sll $v0 $a0 2                      ;$2 = 10000 = 16        sll = shift left
[00400010] 00c23021  addu $6, $6, $2          ; 187: addu $a2 $a2 $v0 A                 ;$6 = 4 + $2            addu = add unsigned
[00400014] 0c100009  jal 0x00400024 [main]    ; 188: jal main                                                   jal = jump to calculatred address and store return in $31
[00400018] 00000000  nop                      ; 189: nop 
[0040001c] 3402000a  ori $2, $0, 10           ; 191: li $v0 10                                                  li = load immediate address
[00400020] 0000000c  syscall                  ; 192: syscall # syscall 10 (exit)                                ori = or immediate value
[00400024] 3c081001  lui $8, 4097 [flag]      ; 7: la $t0, flag                                                 la = load address from ram into register
[00400028] 00004821  addu $9, $0, $0          ; 8: move $t1, $0                                                 
----------------------------------------
[0040002c] 3401000f  ori $1, $0, 15           ; 11: sgt $t2, $t1, 15                                            $1 = 15
[00400030] 0029502a  slt $10, $1, $9                                                                            slt = set on less than equal 1, else 0
[00400034] 34010001  ori $1, $0, 1            ; 12: beq $t2, 1, exit                                            or-ing 15 with 1?
[00400038] 102a0007  beq $1, $10, 28 [exit-0x00400038]                                                          if we got to 15 then exit
[0040003c] 01095020  add $10, $8, $9          ; 14: add $t2, $t0, $t1                                           add 
[00400040] 81440000  lb $4, 0($10)            ; 15: lb $a0, ($t2)                                               lb = loadbyte
[00400044] 00892026  xor $4, $4, $9           ; 16: xor $a0, $a0, $t1                                           xor
[00400048] a1440000  sb $4, 0($10)            ; 17: sb $a0, 0($t2) 
[0040004c] 21290001  addi $9, $9, 1           ; 19: add $t1, $t1, 1 
[00400050] 0810000b  j 0x0040002c [for]       ; 20: j for 
----------------------------------------
[00400054] 00082021  addu $4, $0, $8          ; 24: move $a0, $t0 
[00400058] 0c100019  jal 0x00400064 [printstring]; 25: jal printstring 
[0040005c] 3402000a  ori $2, $0, 10           ; 26: li $v0, 10 
[00400060] 0000000c  syscall                  ; 27: syscall 
[00400064] 34020004  ori $2, $0, 4            ; 30: li $v0, 4 
[00400068] 0000000c  syscall                  ; 31: syscall 
[0040006c] 03e00008  jr $31                   ; 32: jr $ra 
