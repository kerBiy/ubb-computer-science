; Sa se determine cel mai mic multiplu comun al valorilor numerice dintr-o lista neliniara.

(defun flatten-lst (lst) 
    (cond 
        ((atom lst) (list lst))
        (t (mapcan #'flatten-lst lst))))

(defun cmmdc (a b) 
    (cond
        ((= b 0) a)
        (t (cmmdc b (mod a b)))))

(defun cmmmc (a b)
    (/ (* a b) (cmmdc a b)))

(defun cmmmc-lst (lst) 
    (cond 
        ((null (cdr lst)) (car lst))
        (t (cmmmc (car lst) (cmmmc-lst (cdr lst))))))

(defun main (lst) (cmmmc-lst (flatten-lst lst)))

(print (main '(6 2 (3 (9 12) (6 2)))))
