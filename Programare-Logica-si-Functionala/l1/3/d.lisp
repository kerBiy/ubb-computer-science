; Sa se scrie o functie care intoarce intersectia a doua multimi.

(defun findElem (lst elem)
    (cond 
        ((null lst) nil)
        ((equal (car lst) elem) t)
        (t (findElem (cdr lst) elem))))

(defun intersecion (m1 m2)
    (cond
        ((null m1) nil)
        ((findElem m2 (car m1)) (cons (car m1) (intersection (cdr m1) m2)))
        (t (intersection (cdr m1) m2))))

(print (intersection '(1 2 3) '(2 4 1)))