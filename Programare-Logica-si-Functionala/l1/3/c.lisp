; Definiti o functie care sorteaza fara pastrarea dublurilor o lista liniara.

(defun removeElem (lst elem)
    (cond 
        ((null lst) nil) 
        ((equal (car lst) elem) (removeElem (cdr lst) elem))
        (t (cons (car lst) (removeElem (cdr lst) elem)))))

(defun findMin (lst)
    (cond
        ((null (cdr lst)) (car lst))
        (t (min (car lst) (findMin (cdr lst))))))

(defun sortList (lst)
    (cond 
        ((null lst) nil)
        (t (cons (findMin lst) (sortList (removeElem lst (findMin lst)))))))

(print (sortList '(2 4 2 1 3 6 5)))