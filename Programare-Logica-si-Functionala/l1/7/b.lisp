; Definiti o functie care substituie prima aparitie a unui element intr-o lista data.

(defun replaceElem (lst elem new) 
    (cond 
        ((null lst) nil)
        ((equal (car lst) elem) (cons new (cdr lst)))
        (t (cons (car lst) (replaceElem (cdr lst) elem new)))))

 (print (replaceElem '(1 2 3 4 5 2) 2 99))
