; Sa se construiasca o functie care intoarce adancimea unei liste.

(defun depth (lst)
    (cond
      ((atom lst) 0)
      (t (+ 1 (apply 'max (mapcar #'depth lst))))))

(print (depth '(1 2 (3 4) ((5 6) 7))))  ; => 3
(print (depth '(a (b (c d)) e)))        ; => 3
(print (depth '(((())))))               ; => 4
(print (depth '(x y z)))                ; => 1