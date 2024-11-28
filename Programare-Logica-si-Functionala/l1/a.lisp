;; a) Sa se intercaleze un element pe pozitia a n-a a unei liste liniare.

#|
    Insereaza un element la o pozitie data
    insert-at(lst: lista, elem: int, n: int)
    lst: lista in care se insereaza elem
    elem: elementul inserat in lst
    n: pozitia pe care se inseareaza elem in lst

    Modelul matematic:

    insert-at(l1l2...ln, elem, poz) =
        elem U l1l2...ln        n = 0 sau poz = 1
        l1 U insert-at(l2...ln, elem, poz - 1)      altfel
 |# 
(defun insert-at (lst elem n)
    (if (or (null lst) (= n 1))
        (cons elem lst)
        (cons 
            (car lst) 
            (if (numberp (car lst))
                (insert-at (cdr lst) elem (- n 1))
                (insert-at (cdr lst) elem n)
            )
        )
    )
)

(format t "Test 1: Inserting into an empty list: ~a~%" 
        (insert-at nil 'a 1)) ; Expected: (A)

(format t "Test 2: Inserting at the first position: ~a~%" 
        (insert-at '(1 2 3) 'a 1)) ; Expected: (A 1 2 3)

(format t "Test 3: Inserting at the second position: ~a~%" 
        (insert-at '(1 f b c 2 b d e 3 4 f 5 b 6 d e 8) 'a 6)) ; Expected: (1 A 2 3)

(format t "Test 4: Inserting at the last position: ~a~%" 
        (insert-at '(1 2 3) 'a 4)) ; Expected: (1 2 3 A)

(format t "Test 5: Inserting beyond the list length: ~a~%" 
        (insert-at '(1 2 3) 'a 10)) ; Expected: (1 2 3 A)