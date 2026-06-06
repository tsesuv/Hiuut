ORG 0x0000

mov ax, 0x0900
mov ds, ax
mov es, ax

mov si, msg

print:
	lodsb
	or al, al
	jz printEnd
	mov ah, 0x0E
	int 0x10
	jmp print

	printEnd:
;		hlt
;		jmp printEnd
		mov si, msg
		jmp print

msg:
	db "Hello, welcome to OS-ish!", 0x0D, 0x0A, 0x0
