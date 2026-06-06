BITS 16
ORG 0x7C00

jmp main

LOAD_SEGMENT equ 0x0900
LOAD_OFFSET equ 0x0000

main:
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov sp, 0x7C00

	mov ah, 0x02
	mov al, 1
	mov ch, 0
	mov cl, 2
	mov dh, 0

	mov bx, LOAD_SEGMENT
	mov es, bx
	mov bx, LOAD_OFFSET

	int 0x13
	jc errorDisk

	jmp LOAD_SEGMENT:LOAD_OFFSET

errorDisk:
	mov ah, 0x0E
	mov al, 'E'
	int 0x10
	hlt

times 510 - ($ - $$) db 0

db 0x55
db 0xAA
; ブートセクタ署名
