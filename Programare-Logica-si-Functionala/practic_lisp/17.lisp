; Eliminate all occurances of the maximum numeric element of a non-linear list. For example: (1 2 3 4 5 6) -> (1 2 3 4 5)

(defun findMax (lst)
  (cond 
    ((null lst) 0)
    ((atom (car lst)) 
      (if (numberp (car lst))
        (max (car lst) (findMax (cdr lst)))
        (findMax (cdr lst))))
    (t (max (findMax (car lst)) (findMax (cdr lst))))))

(defun removeElem (lst elem)
  (cond
    ((null lst) nil)
    ((equal (car lst) elem) (removeElem (cdr lst) elem))
    ((listp (car lst)) (cons (removeElem (car lst) elem) (removeElem (cdr lst) elem)))
    (t (cons (car lst) (removeElem (cdr lst) elem)))))

(defun removeMax (lst)
  (removeElem lst (findMax lst)))

(print (removeMax '(1 2 (3 6 5) ((6)))))