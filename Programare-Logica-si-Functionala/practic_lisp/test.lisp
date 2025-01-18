; Diferenta a 2 numere reprezentate pe lista

; reverse-lst (lst: list)
; lst - lista pe care vreau sa o oglindesc
; Modelul matematic:
;
; reverse-lst (l1l2...ln) =
;       l1, daca n = 1
;       reverse-lst(l2...ln) U l1, altfel

(defun reverse-lst (lst) 
    (cond
        ((null (cdr lst)) (list (car lst)))
        (t (append (reverse-lst (cdr lst)) (list (car lst))))))
 
; difference (num1: list, num2: list, carry: int)
; num1 - primul numar reprezentat pe o lista
; num2 - al doilea numar reprezentat pe o lista
; carry - restul scaderii
; Modelul matematic:
; 
; difference (d1d2...dn, s1s2...sm c) =
;       nil, daca n = 0 si m = 0
;       difference(d1d2...dn, 0, c), daca m = 0 si n != 0
;       10 + (d1 - s1 - c) U difference (d2...dn, s2...sn, 1), daca d1 - s1 - c < 0 
;       (d1 - s1 - c) U difference (d2...dn, s2...sn, 0), altfel

(defun difference (num1 num2 carry) 
    (cond
        ((and (null num1) (null num2)) nil)
        ((null num2) (difference num1 (list 0) carry))
        ((< (- (car num1) (car num2) carry) 0) 
            (cons (+ 10 (- (car num1) (car num2) carry)) (difference (cdr num1) (cdr num2) 1)))

        (t (cons (- (car num1) (car num2) carry) (difference (cdr num1) (cdr num2) 0)))))

; main (num1: list, num2: list)
; num1 - primul numar reprezentat pe o lista
; num2 - al doilea numar reprezentat pe o lista
;
; Modelul matematic:
; main (d1d2...dn, s1s2...sn) = reverse-lst(difference(reverse-lst(num1), reverse-lst(num2), 0))

(defun main (num1 num2)
    (reverse-lst (difference (reverse-lst num1) (reverse-lst num2) 0)))

(print (main '(3 3 3) '(1 1 1)))
(print (main '(3 3 3) '(2 2)))
(print (main '(3 3 3) '(2 8)))
(print (main '(1 1 1) '(2 5)))



