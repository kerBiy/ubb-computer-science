; Sa se scrie o functie care testeaza daca o lista este liniara.

(defun liniarp (lst) 
    (cond 
        ((null lst) t)
        ((listp (car lst)) nil)
        (t (liniarp (cdr lst)))))

 (print (liniarp '(1 (2) 3 4 5 6)))
