; Dandu-se o lista, sa se construiasca lista primelor elemente ale tuturor
; elementelor lista ce au un numar impar de elemente la nivel superficial.
; Exemplu: (1 2 (3 (4 5) (6 7)) 8 (9 10 11)) => (1 3 9).

(defun len-list (lst) 
    (cond 
        ((null lst) 0)
        (t (+ 1 (len-list (cdr lst))))))
 

(defun func (lst)
    (cond 
        ((null lst) nil)
        ((and (listp (car lst)) (oddp (len-list (car lst)))) 
            (cons (car (car lst)) (func (cdr lst))))
        (t (func (cdr lst)))))

(print (func '(1 2 (3 (4 5 12) (6 7)) 8 (9 10 11))))
