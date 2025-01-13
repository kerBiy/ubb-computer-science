; a) Sa se elimine elementul de pe pozitia a n-a a unei liste liniar.

(defun removeNthElem(lst n curr)
    (cond 
        ((null lst) nil)
        ((equal curr n) (removeNthElem (cdr lst) n (+ curr 1)))
        (t (cons (car lst) (removeNthElem (cdr lst) n (+ curr 1))))))

(defun main (lst n) 
    (removeNthElem lst n 1))

(print (main '(1 2 3 4 5 6 7) 2))
(print (main '(1 2 3 4 5 6 7) 5))
(print (main '(1 2 3 4 5 6 7) 7))
