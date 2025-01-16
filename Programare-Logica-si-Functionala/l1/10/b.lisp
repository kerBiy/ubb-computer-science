; Sa se scrie o functie care, primind o lista, intoarce multimea tuturor perechilor din lista. 
; De exemplu: (a b c d) --> ((a b) (a c) (a d) (b c) (b d) (c d))

(defun get-combo (elem rest-lst) 
    (cond
        ((null rest-lst) nil)
        (t (cons (list elem (car rest-lst)) (get-combo elem (cdr rest-lst))))))
 
 (defun get-pairs (lst) 
    (cond 
        ((null lst) nil)
        (t (append (get-combo (car lst) (cdr lst)) (get-pairs (cdr lst))))))
 
 (print (get-pairs '(a b c d)))
