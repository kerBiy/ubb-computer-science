; Sa se construiasca o functie care intoarce adancimea unei liste.

(defun maxDepth (lst level)
    (cond
        ((null lst) level)

        ((atom (car lst)) (max level (maxDepth (cdr lst) level)))

        (t (max 
            (maxDepth (car lst) (+ 1 level)) 
            (maxDepth (cdr lst) level)))))

(defun main (lst)
    (maxDepth lst 1))

(print (main '()))
(print (main '(1 2 3)))
(print (main '((1 2) 3)))
(print (main '(1 2 A (3 4 (5 6 2 (B)) 3 2) 7 ((3)))))