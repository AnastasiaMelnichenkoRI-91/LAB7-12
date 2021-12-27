cli ; �������� ����������"
; DDR"
ldi r16, 1 << PB2 ; ������������ ��������� "0010 0000" � ����� r16"
out DDRB, r16 ; ����������� � ������� r16 � I/O ������ DDRB"

ldi r16, (1 << PC2) | (1 << PC4) ; ������������ ��������� "0010 0010" � ����� r16"
out DDRC, r16 ; ����������� � ������� r16 � I/O ������ DDRC"

ldi r16, (1 << PD4) | (1 << PD6) ; ������������ ��������� "1000 1000" � ����� r16"
out DDRD, r16 ; ����������� � ������� r16 � I/O ������ DDRD"

; PORT (����� ������� �� ���� � ��������)"
ldi r16, 1 << PB1 ; ������������ ��������� "0001 0000" � ����� r16"
out PORTB, r16 ; ����������� � ������� r16 � I/O ������ PORTB"

ldi r16, (1 << PC1) | (1 << PC3) ; ������������ ��������� "0001 0001" � ����� r16"
out PORTC, r16 ; ����������� � ������� r16 � I/O ������ PORTC"

ldi r16, (1 << PD3) | (1 << PD5) ; ������������ ��������� "0100 0100" � ����� r16"
out PORTD, r16 ; ����������� � ������� r16 � I/O ������ PORTD"

sei ; ����� ����������"

start:
cli ; �������� ����������"
; �� Arduino Uno �������� �� pin 13, � ������ �� pin 12"
in r16, PINB ; ����������� � I/O ������� PINB � ������ r16"
sbrc r16, PB1 ; ���������� �������� �������, ���� 4� �� � ������ r16 ������ (������� 0)"
sbi PORTB, PB2 ; ������������ 5�� ��� � I/O ������ PORTB � 1"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
sbrs r16, PB1 ; ���������� �������� �������, ���� 4� �� � ������ r16 ���������� (������� 1)"
cbi PORTB, PB2 ; �������� 5�� ��� � I/O ������ PORTB � 0"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

; �� Arduino Uno �������� �� A1, � ������ �� A0"
in r16, PINC ; ����������� � I/O ������� PINC � ������ r16"
sbrc r16, PC1 ; ���������� �������� �������, ���� 0� �� � ������ r16 ������ (������� 0)"
sbi PORTC, PC2 ; ������������ 1�� ��� � I/O ������ PORTC � 1"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
sbrs r16, PC1 ; ���������� �������� �������, ���� 0� �� � ������ r16 ���������� (������� 1)"
cbi PORTC, PC2 ; �������� 1�� ��� � I/O ������ PORTC � 0"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

; �� Arduino Uno �������� �� A5, � ������ �� A4"
in r16, PINC ; ����������� � I/O ������� PINC � ������ r16"
sbrc r16, PC3 ; ���������� �������� �������, ���� 4� �� � ������ r16 ������ (������� 0)"
sbi PORTC, PC4 ; ������������ 5�� ��� � I/O ������ PORTC � 1"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
sbrs r16, PC3 ; ���������� �������� �������, ���� 4� �� � ������ r16 ���������� (������� 1)"
cbi PORTC, PC4 ; �������� 5�� ��� � I/O ������ PORTC � 0"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

; �� Arduino Uno �������� �� pin 3, � ������ �� pin 2"
in r16, PIND ; ����������� � I/O ������� PIND � ������ r16"
sbrc r16, PD3 ; ���������� �������� �������, ���� 2� �� � ������ r16 ������ (������� 0)"
sbi PORTD, PD4 ; ������������ 3�� ��� � I/O ������ PORTD � 1"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
sbrs r16, PD3 ; ���������� �������� �������, ���� 2� �� � ������ r16 ���������� (������� 1)"
cbi PORTD, PD4 ; �������� 3�� ��� � I/O ������ PORTD � 0"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

; �� Arduino Uno �������� �� pin 7, � ������ �� pin 6"
in r16, PIND ; ����������� � I/O ������� PIND � ������ r16"
sbrc r16, PD5 ; ���������� �������� �������, ���� 6� �� � ������ r16 ������ (������� 0)"
sbi PORTD, PD6 ; ������������ 7�� ��� � I/O ������ PORTD � 1"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
sbrs r16, PD5 ; ���������� �������� �������, ���� 6� �� � ������ r16 ���������� (������� 1)"
cbi PORTD, PD6 ; �������� 7�� ��� � I/O ������ PORTD � 0"
nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

sei ; ����� ����������"
rjmp start
