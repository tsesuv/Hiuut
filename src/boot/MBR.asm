BITS 16
ORG 0x7C00

jmp START

LSEG equ 0x0900
LOFS equ 0x0000

START:
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov sp, 0x7C00

	mov ah, 0x02
	mov al, 1
	mov ch, 0
	mov cl, 1
	mov dh, 0

	mov bx, LSEG
	mov es, bx
	mov bx, LOFS

	push bx
	push dx
	xor dx, dx
	xor si, si

	diskRead:
		inc cl

		int 0x13
		jc errorDisk

		mov bx, LOFS

		test dx, dx
		jz cmp_b_0
		inc bx
		cmp dx, 1
		jz cmp_b_1
		inc bx
		cmp dx, 2
		jz cmp_b_2
		inc bx
		cmp dx, 3
		jz cmp_b_3
		inc bx
		cmp dx, 4
		jz cmp_b_4
		inc bx
		cmp dx, 5
		jz cmp_b_4
		jmp cmp_b_f

		cmp_b_0:
			cmp bx, 'H'
			jz cmp_b_f
		cmp_b_1:
			cmp bx, 't'
			jz cmp_b_f
		cmp_b_2:
			cmp bx, 'F'
			jz cmp_b_f
		cmp_b_3:
			cmp bx, 'S'
			jz cmp_b_f
		cmp_b_4:
			test bl, bl
			jz cmp_b_f

		cmp_b_t:
			inc dx
			jmp cmp_b_endBlock

		cmp_b_f:
			xor dl, dl
			inc si
			cmp si, 20
			jz errorDisk

		cmp_b_endBlock:
		cmp dx, 6
		jnz diskRead

		mov si, bx
		add si, 10

	pop dx
	pop bx

	call print

	cli
	hlt

	jmp LSEG:LOFS

errorDisk:
	mov si, err
	call print

	hlt

print: ; str: si, str is terminated $0
	lodsb

	test al, al
	jz return

	mov ah, 0x0E
	int 0x10

	jmp print

return:
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

err db "MBR: START: int $13: Disk I/O Error", 0x0D, 0x0A, 0x0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

times 510 - ($ - $$) db 0

db 0x55
db 0xAA
; ブートセクタ署名
