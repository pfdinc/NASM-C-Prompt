#include <stdio.h>
void main()
{



	char ch;
	char nl_ch;
	int array1[10];
	int* pointer; // Declares a pointer to an int/
	pointer = &array1[0]; //obtains the address the first element of the array1
	char mem_ch2;
	char char_prompt[] = "Please input a character: ";
	char out_msg1[] = "The ASCII code of '";
	char out_msg2[] = "' in binary is ";
	char query_msg[] = "Do you want to quit (Y/N): ";

	int i;
	for (i = 0; i < 10; i++)
		array1[i] = 1;
	__asm
	{
	read_char:

	};
	printf(char_prompt);
	scanf("%c", &ch);
	scanf("%c", &nl_ch);

	printf(out_msg1);
	printf("%c", ch);
	printf(out_msg2);
	i = ch;
	__asm
	{
		mov eax, i
		mov ecx, pointer;
		mov ebx, [ecx];
	};
	__asm
	{

		mov     AH, 80H; mask byte = 80H
		mov     ECX, 8; loop count to print 8 bits
			print_bit :
		test    AL, AH; test does not modify AL
			jz      print_0; if tested bit is 0, print it
	}
	__asm
	{
		push	eax
		push	ecx
	}
	__asm
	{
		mov		al, '1'
		mov     mem_ch2, al; otherwise, print 1
	}
	printf("%c", mem_ch2); // %c char/

	__asm
	{
		pop	    ecx
		pop		eax
	}
	__asm
	{

		jmp     skip1
		print_0 :
	}
	__asm
	{
		push	eax
		push	ecx
	}
	__asm
	{
		mov		al, '0'
		mov     mem_ch2, al; otherwise, print 1
	}
	printf("%c", mem_ch2);
	__asm
	{
		pop	    ecx
		pop		eax
	}
	__asm
	{
	skip1:
		shr     AH, 1; right - shift mask bit to test
			;  next bit of the ASCII code
			loop    print_bit
	}
	printf("\r\n");
	printf(query_msg);
	scanf("%c", &ch);
	scanf("%c", &nl_ch);
	i = ch;
	__asm
	{
		mov eax, i
	};
	__asm
	{
		//mov al, ch
			cmp     AL, 'Y'			; if AL is equal 'Y'
			je		done			; program will close
			cmp		AL, 'y'			; if is 'y'
			je		done			; program will close
			cmp	    AL, 'N'			; if AL is equal 'N'
			je      read_char		; program will jump to read_char
			cmp     AL, 'n'			; if AL is equal to 'n'
			je      read_char		; program will jump to read_char
			cmp		AL, ch			; compare AL with Ch
			jne		read_char		; if not equal jump to read_char



	};
	__asm
	{
	done:
	}




	/*	Binary equivalent of characters   BINCHAR.ASM
	;
	;        Objective: To print the binary equivalent of
	;                   ASCII character code.
	;            Input: Requests a character from keyboard.
	;           Output: Prints the ASCII code of the
	;                   input character in binary.
	.MODEL SMALL
	.STACK 100H
	.DATA
	char_prompt    db  "Please input a character: ",0
	out_msg1       db  "The ASCII code of '",0
	out_msg2       db  "' in binary is ",0
	query_msg      db  "Do you want to quit (Y/N): ",0

	.486
	.CODE
	INCLUDE io.mac
	.STARTUP
	read_char:
	PutStr  char_prompt  ; request a char. input
	GetCh   AL           ; read input character
	nwln
	PutStr  out_msg1
	PutCh   AL
	PutStr  out_msg2
	mov     AH,80H       ; mask byte = 80H
	mov     ECX,8        ; loop count to print 8 bits
	print_bit:
	test    AL,AH        ; test does not modify AL
	jz      print_0      ; if tested bit is 0, print it
	PutCh   '1'          ; otherwise, print 1
	jmp     skip1
	print_0:
	PutCh   '0'          ; print 0
	skip1:
	shr     AH,1         ; right-shift mask bit to test
	;  next bit of the ASCII code
	loop    print_bit
	nwln
	PutStr  query_msg    ; query user whether to terminate
	GetCh   AL           ; read response
	nwln
	cmp     AL,'Y'       ; if response is not 'Y'
	jne     read_char    ; read another character
	done:                        ; otherwise, terminate program
	.EXIT
	END*/

}
