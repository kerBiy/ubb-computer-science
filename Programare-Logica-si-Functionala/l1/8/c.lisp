; Sa se construiasca multimea atomilor unei liste.
; Exemplu: (1 (2 (1 3 (2 4) 3) 1) (1 4)) ==> (1 2 3 4)

(defun findElem (lst elem) 
    (cond 
        ((null lst) nil)
        ((equal (car lst) elem) t)
        (t (findElem (cdr lst) elem))))

(defun makeSet (lst) 
    (cond
        ((null lst) nil)
        ((findElem (cdr lst) (car lst)) (makeSet (cdr lst)))
        (t (cons (car lst) (makeSet (cdr lst))))))

(defun findAtoms (lst) 
    (cond 
        ((null lst) nil)
        ((atom (car lst)) (cons (car lst) (findAtoms (cdr lst))))
        (t (append (findAtoms (car lst)) (findAtoms (cdr lst))))))

(defun main (lst) 
    (makeSet (findAtoms lst)))

(print (main '(1 (2 (1 3 (2 4) 3) 1) (1 4))))
