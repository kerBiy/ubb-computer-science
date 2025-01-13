(defun f (tree level x)
    (cond 
        ((and (atom tree) (evenp level) (equal tree x)) (list t))
        ((listp tree) (mapcan (lambda (subtree) (f subtree (+ 1 level) x)) tree))
        (t nil)))

(defun main (tree x)
    (car (f tree -1 x)))

(print (main '(a (b (g)) (c (d (e)) (f))) 'h))