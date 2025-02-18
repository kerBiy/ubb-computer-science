(defun f (tree level e)
    (cond 
        ((atom tree) 
         (if (oddp level)
            nil
            (list tree)))

        (t (list (mapcan (lambda (subtree) 
                        (f subtree (+ level 1) e)) tree)))))

(print (f '(a (b (g)) (c (d (e)) (f))) 1 'h))