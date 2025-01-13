; b) Definiti o functie care determina succesorul unui numar reprezentat cifra cu cifra intr-o lista.
; De ex: (1 9 3 5 9 9) --> (1 9 3 6 0 0)

(defun findSuccesor (lst carry) 
    (cond 
        ((null lst) nil)
        ((> (+ (car lst) carry) 9) (cons (mod (+ (car lst) carry) 10) (findSuccesor (cdr lst) 1)))
        (t (cons (+ (car lst) carry) (findSuccesor (cdr lst) 0)))))

(defun main (lst) 
    (reverse (findSuccesor (reverse lst) 1)))

(print (main '(1 9 3 5 9 9)))
(print (main '(1 9 3 5 9 9)))
