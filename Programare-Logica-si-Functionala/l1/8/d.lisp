; Sa se scrie o functie care testeaza daca o lista liniara este o multime.

(defun findElem (lst elem)
    (cond 
        ((null lst) nil)
        ((equal (car lst) elem) t)
        (t (findElem (cdr lst) elem))))

(defun setp (lst) 
    (cond 
        ((null lst) t)
        ((findElem (cdr lst) (car lst)) nil)
        (t (setp (cdr lst)))))

(print (setp '(1 2 3 4)))
(print (setp '(1 2 2 4)))
(print (setp '(1 2 3 1)))
