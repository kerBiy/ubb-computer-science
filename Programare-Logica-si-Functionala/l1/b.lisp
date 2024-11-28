;; b) Sa se construiasca o functie care intoarce suma atomilor numerici dintr-o lista, de la orice nivel.

#|
    Face suma toturor atomilor numerici
    sum-numeric-atoms(lst: list)
    lst: Lista initiala pentru care se face suma atomilor

    Modelul matematic:

    sum-numeric-atoms(l1l2...ln) =
        0       n = 0
        l1 + sum-numeric-atoms(l2...ln)        l1 e atom si e numar
        sum-numeric-atoms(l2...ln)        l1 e atom si nu e numar
        sum-numeric-atoms(l1) + sum-numeric-atoms(l2...ln)      l1 e lista     
        
 |#
(defun sum-numeric-atoms (lst)
    (cond
        ;; Case: Empty list has sum 0
        ((null lst) 0)

        ;; Case: Current element is an atom
        ((atom (car lst)) 
            (if (numberp (car lst)) 
                (+ (car lst) (sum-numeric-atoms (cdr lst)))
                (sum-numeric-atoms (cdr lst))
            )
        )

        ;; Case: Current element is a list
        (t 
            (+ 
                (sum-numeric-atoms (car lst)) 
                (sum-numeric-atoms (cdr lst))
            )
        )
    )
)

(format t "Test b.1: Sum of an empty list: ~a~%"
        (sum-numeric-atoms nil)) ; Expected: 0

(format t "Test b.2: Sum of a flat numeric list: ~a~%"
        (sum-numeric-atoms '(1 2 3 4))) ; Expected: 10

(format t "Test b.3: Sum of a mixed list with atoms: ~a~%"
        (sum-numeric-atoms '(1 "a" 2 (3 4) "b"))) ; Expected: 10

(format t "Test b.4: Sum of a nested list: ~a~%"
        (sum-numeric-atoms '((1 2) (3 (4 5))))) ; Expected: 15

(format t "Test b.5: Sum of a deeply nested list: ~a~%"
        (sum-numeric-atoms '(1 (2 (3 (4 (5))))))) ; Expected: 15
