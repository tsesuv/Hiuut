ORG 0x0000

mov ax, 0x0900
mov ds, ax
mov es, ax

mov si, msg

print: ; str: si, str is terminated $0
	lodsb

	test al, al
	jz return

	mov ah, 0x0E
	int 0x10

	jmp print

return:
	ret

msg:
	db "Hello, welcome to OS-ish!", 0x0D, 0x0A, 0x0
