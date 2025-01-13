(defun f (lst k)
    (cond
        ((and (= k 0) (atom lst)) 0)
        ((listp lst) (mapcar (lambda (x) (f x (- k 1))) lst))
        (t lst)))

(print (f '(a (1 (2 b)) (c (d))) 2))