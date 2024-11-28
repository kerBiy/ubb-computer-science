;; c) Sa se scrie o functie care intoarce multimea tuturor sublistelor unei liste date. Ex: Ptr. lista ((1 2 3) ((4 5) 6)) => ((1 2 3) (4 5) ((4 5) 6))

#|
    Gaseste multimea tutoror sublistelor unei liste date
    all-sublists(lst: list)
    lst: Lista pentru care se realizeza multimea toturor sublistelor

    Modelul matematic:

    all-sublists(l1l2...ln) =
        nil        n = 0
        all_sublists(l2...ln)       l1 e atom
        l1 U (all-sublists(l1) U all-sublists(l2...ln))        l1 e lista
 |#

(defun all-sublists (lst)
    (cond
        ;; Case: Empty list
        ((null lst) nil)

        ;; Case: Current element is an atom, skip it
        ((atom (car lst)) (all-sublists (cdr lst)))

        ;; Case: Current element is a list
        (t 
            (cons 
                (car lst) 
                (append 
                    (all-sublists (car lst)) 
                    (all-sublists (cdr lst))
                )
            )
        )
    )
)

; Tests for c)
(format t "Test c.1: Sublists of an empty list: ~a~%"
        (all-sublists nil)) ; Expected: NIL

(format t "Test c.2: Sublists of a flat list: ~a~%"
        (all-sublists '(1 2 3))) ; Expected: NIL (no sublists)

(format t "Test c.3: Sublists of a list with sublists: ~a~%"
        (all-sublists '((1 2 3) (4 5 6)))) ; Expected: ((1 2 3) (4 5 6))

(format t "Test c.4: Sublists of a nested list: ~a~%"
        (all-sublists '((1 2 3) ((4 5) 6)))) ; Expected: ((1 2 3) (4 5) ((4 5) 6))

(format t "Test c.5: Sublists of a deeply nested list: ~a~%"
        (all-sublists '(((1 2) 3) (4 (5))))) ; Expected: ((1 2) ((1 2) 3) (5) (4 (5)))