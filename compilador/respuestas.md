1. primer paso: que se reemplacen los include, los macros, etc. En el ejercicio se va a reemplazar la linea #include "calculator.h" por el contenido de calculator.h dentro del archvio calculator.c. Esto no sobreescribe este archivo sino que genera uno nuevo.
segundo paso: Este ultimo archivo generado se traduce a idioma assembler en un nuevo archivo.
tercer paso: el archivo assembler es traducido a lenguaje maquina.
cuarto paso: se produce el linkeo y se genera el archivo ejecutable.

2. Agregó el contenido de calculator.h en calculator.c (se genera un nuevo archivo, no sobreescribe). dentro de calculartor.h se encuentra #include <stdio.h> que es necesario para que la funcion printf funcione, ya que esta definida alli.

3. Funcion main:
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	DWORD PTR -20[rbp], edi
	mov	QWORD PTR -32[rbp], rsi
	mov	esi, 11
	mov	edi, 31
	call	add_numbers
	mov	DWORD PTR -4[rbp], eax
	mov	eax, DWORD PTR -4[rbp]
	mov	esi, eax
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

funcion add_numbers:
add_numbers:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	DWORD PTR -8[rbp], esi
	mov	edx, DWORD PTR -4[rbp]
	mov	eax, DWORD PTR -8[rbp]
	add	eax, edx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

en la linea 24 del codigo en assembler esta la llamada a la funcion add_numbers: call	add_numbers
en la linea 30 esta la llamada a la funcion printf:
call	printf@PLT

4. los simbolos que se crean en el objeto son los descriptores.
Los descriptores te dicen que tipo son las funciones y variables, y si se puede acceder a ellos desde fuera o no.
Por ejemplo la letra t/T es texto, la letra U es undefined, la r/R read-only, etc. Si la letra está en mayúscula es posible acceder desde fuera, si esta en minúscula no.

5. en el ejecutable aparecen mas simbolos y ademas pueden cambiar los simbolos de undefined que aparecian en el objeto, ya que al linkear se define la funcion. Tambien pueden quedar como undefined pero con una indicacion de donde hay que ir a buscar esa funcion.
