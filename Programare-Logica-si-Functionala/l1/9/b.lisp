; Definiti o functie care inverseaza o lista impreuna cu toate sublistele sale de pe orice nivel.

(defun reverse-list (lst) 
    (cond
        ((null lst) nil)
        ((atom (car lst)) (append (reverse-list (cdr lst)) (list (car lst)))) 
        (t (append (reverse-list (cdr lst)) (list (reverse-list (car lst)))))))

(print "The original list is: (1 2 (3 (4 5) (6 7)) 8 (9 10 11))")
(print (reverse-list '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))
