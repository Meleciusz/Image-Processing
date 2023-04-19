.code

Proc1 proc 

push rbp
mov rbp, rsp


xor rax, rax	;
xor rbx, rbx	;Wyczyszczenie rejestow



push r15	;
push r14	;
push r13	;Zapisanie na stos uzywanych rejestrow
push r12	;
push rbx	;

mov r10, rcx	;WskaŸnik na 1 piksel wczytujacy
mov r11, rdx	;Wskaznik na 1 piksel zapisujacy 
mov rcx, r8		;Numpixels (licznik pêtli)
mov rdx, r9		;Szerokosc
mov eax, [rsp+8*11]	;Wysokosc
mov r12, rax 
mov eax, [rsp+8*12] ;Pozycja x
mov r13, rax 
mov eax, [rsp+8*13] ;Pozycja y
mov r14, rax 
mov eax, [rsp+8*14] ;Padding
mov r15, rax 


mov rbx, rdx	; 
imul rbx, 3		;Obliczenie danych uzywanych w petli
add rbx, r15	;


dec r12 ;Wys - 1 (potrzebne do warunkow if)




main_loop:	;Poczatek petli glownej programu

cmp rcx, 0  ;Warunek wyjscia z petli 
je wyjscie	;Skok do konca programu w przypadku spelnienia warunku

dec rdx			;Szer -1 (potrzebne do warunkow if)
cmp r13, 0		;Jezeli x = 0
je next			;Skok przy spelnieniu warunku
cmp r13, rdx	;Jezeli x = szerokosci
je next			;Skok przy spelnieniu warunku
cmp r14, 0		;Jezeli y = 0
je next			;Skok przy spelnieniu warunku
cmp r14, r12	;Jezeli y = wysokosci
je next			;Skok przy spelnieniu warunku


mov r9, r10			;Q11
sub r9, rbx			;
sub r9, 3			;Wyliczenie danego piksela na masce i zapisanie wartosci do rejestru xmm
movups xmm0, [r9]	;

pmovzxbw xmm0, xmm0	;Konwersja wektorów liczb ca³kowitych na liczby ca³kowite o wiêkszej liczbie bitów
psrld xmm0, 2		;Przesuniecie bitowe o 2 w prawo (W celu podzielenia przez 2)

mov r9, r10 ;Q21
sub r9, rbx
add r9, 3
movups xmm1, [r9]

pmovzxbw xmm1, xmm1
psrld xmm1, 2

mov r8, r10 ;Q12
add r8, rbx
sub r8, 3
movups xmm2, [r8] 

pmovzxbw xmm2, xmm2
psrld xmm2, 2


mov r8, r10 ;Q22
add r8, rbx
add r8, 3
movups xmm3, [r8] 

pmovzxbw xmm3, xmm3
psrld xmm3, 2

;petla

paddw xmm0, xmm1	;
paddw xmm0, xmm2	;Dodanie rejestrow
paddw xmm0, xmm3	;



pextrw rax, xmm0, 0		;Pixel B
mov [r11], ax			;Zapisanie		
inc r11					

pextrw rax, xmm0, 1  ;Pixel G
mov [r11], ax			
inc r11

pextrw rax, xmm0, 2  ;Pixel R
mov [r11], ax
inc r11

sub r11, 3		;Odjecie 3 w celu powrocenia do poprzedniego adresu

;koniec petli

next:			;Skok w to miejsce jezeli ktorys z warunkow nie zostal spelniony 
inc r13			;Zwiekszenie pozycji x
add r10, 3		;Przejscie do nastepnego piksela(Odczyt)
add r11, 3		;Przejscie do nastepnego piksela(Zapis)
dec rcx			;Dekrementowanie petli 
inc rdx			;Inkrementacja szerokosci

cmp r13, rdx	;Jezeli y jest rowne szerokosci zdjecia
jne main_loop
inc r14			;Zwiekszenie pozycji y
imul r13, 0		;Wyzerowanie pozycji x
add r10, r15	;Dodanie paddingu
add r11, r15	;Dodanie paddingu 

jmp main_loop	;Koniec petli 

wyjscie: 

pop rbx		;
pop r12		;
pop r13		;Sciagniecie ze stosu 
pop r14		;
pop r15		;

mov rsp, rbp
pop rbp


ret

Proc1 endp

END