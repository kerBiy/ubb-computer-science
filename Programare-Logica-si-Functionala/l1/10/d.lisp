; Definiti o functie care, dintr-o lista de atomi, produce o lista de perechi (atom n), 
; unde atom apare in lista initiala de n ori. 
; De ex: (A B A B A C A) --> ((A 4) (B 2) (C 1)).

(defun make-flat (lst) 
    (cond
        ((null lst) nil)
        ((atom (car lst)) (cons (car lst) (make-flat (cdr lst))))
        (t (append (make-flat (car lst)) (make-flat (cdr lst))))))

(defun get-freq (lst elem) 
    (cond 
        ((null lst) 0)
        ((equal (car lst) elem) (1+ (get-freq (cdr lst) elem)))
        (t (get-freq (cdr lst) elem))))
 
(defun remove-elem (lst elem)
    (cond 
        ((null lst) nil)
        ((equal (car lst) elem) (remove-elem (cdr lst) elem))
        (t (cons (car lst) (remove-elem (cdr lst) elem)))))
 
(defun get-lst-freq (lst) 
    (cond 
        ((null lst) nil)
        (t (cons 
            (list (car lst) (get-freq lst (car lst))) 
            (get-lst-freq (remove-elem lst (car lst)))))))

(defun main (lst) 
    (get-lst-freq (make-flat lst)))
        
(print (main '(A B (A C (B)) (A (A)))))
