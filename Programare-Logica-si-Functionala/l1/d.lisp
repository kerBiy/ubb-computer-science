;; d) Sa se scrie o functie care testeaza egalitatea a doua multimi, fara sa se faca apel la diferenta a doua multimi.

#|
    Verifica daca doua seturi sunt egale
    sets-equal(set1: list, set2: list)
    set1: Primul set
    set2: Al doilea set

    Modelul matematic:

    sets-equal(l1l2...ln, s1s2...sm) =
        subsetp(l1l2...ln, s1s2...sm) si subsetp(s1s2...sm, l1l2...ln)
 |#
(defun sets-equal (set1 set2)
    (and 
        (is_subsetp set1 set2) 
        (is_subsetp set2 set1)
    )
)

#|
    Verifica daca un set este subset altui set
    is_subsetp(set1: list, set2: list)
    set1: Primul set
    set2: Al doilea set

    Modelul matematic:

    is_subsetp(l1l2...ln, s1s2...sm) = 
        true        n = 0
        is_memeber(l1, s1s2...sm) si is_subsetp(l2...ln, s1s2...sm)           altfel
 |#
(defun is_subsetp (set1 set2)
    (if (null set1)
        t
        (and 
            (is_member (car set1) set2) 
            (is_subsetp (cdr set1) set2)
        )
    )
)

#|
    Verifica daca un element se afla intr-o lista
    is_member(elem: int, lst: List)
    elem: Elementul cautat in lst 
    lst: Lista in care se cauta elem 

    Modelul matematic:

    is_member(elem, l1l2...ln) =
        nil     n = 0
        true        l1 = elem
        is_member(elem, l2...ln)        altfel
 |#
(defun is_member(elem lst)
    (cond 
        ((null lst) nil)

        ((= (car lst) elem) t)

        (t (is_member elem (cdr lst)))
    )
)



(format t "Test d.1: Comparing two identical sets: ~a~%"
        (sets-equal '(1 2 3) '(3 2 1))) ; Expected: T

(format t "Test d.2: Comparing a set to itself: ~a~%"
        (sets-equal '(1 2 3) '(1 2 3))) ; Expected: T

(format t "Test d.3: Comparing two different sets: ~a~%"
        (sets-equal '(1 2 3) '(4 5 6))) ; Expected: NIL

(format t "Test d.4: Comparing a subset and a superset: ~a~%"
        (sets-equal '(1 2) '(1 2 3))) ; Expected: NIL

(format t "Test d.5: Comparing sets with duplicates: ~a~%"
        (sets-equal '(1 2 2 3) '(3 2 1))) ; Expected: T