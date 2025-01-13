; Sa se elimine dintr-o lista toate elementele care se repeta (de la orice nivel)

(defun exists (lst elem)
  (cond
    ((null lst) nil)
    ((atom (car lst)) 
      (if (equal elem (car lst))
        t
        (exists (cdr lst) elem)))
    (t (or (exists (car lst) elem) (exists (cdr lst) elem)))))

(defun removeElem (lst elem)
  (cond
    ((null lst) nil)
    ((atom (car lst))
      (if (equal elem (car lst))
        (removeElem (cdr lst) elem)
        (cons (car lst) (removeElem (cdr lst) elem))))
    (t (cons (removeElem (car lst) elem) (removeElem (cdr lst) elem)))))

(defun removeDuplicates (lst)
  (cond
    ((null lst) nil)
    ((atom (car lst))
      (if (exists (cdr lst) (car lst))
        (removeDuplicates (removeElem lst (car lst)))
        (cons (car lst) (removeDuplicates (cdr lst)))))
    (t (cons (removeDuplicates (car lst)) (removeDuplicates (cdr lst))))))

(print (removeDuplicates '(1 (2 C F 1 (D 2 C 4)) E)))
(print (removeDuplicates '(1 2 3 4 5 4 3 2 1) ))
(print (removeDuplicates '(A (B C) 3 A (D C A) 5 5) ))
(print (removeDuplicates '(1 2 (A B A (3 A)) (1 (1 (C)) 1))))
