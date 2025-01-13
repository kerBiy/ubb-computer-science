; Sa se inlocuiasca fiecare sublista a unei liste cu ultimul ei element.
; Prin sublista se intelege element de pe primul nivel, care este lista.
; Exemplu: 
; (a (b c) (d (e (f)))) ==> (a c (e (f))) ==> (a c (f)) ==> (a cf)
; (a (b c) (d ((e) f))) ==> (a c ((e) f)) ==> (a c f)

(defun findLastElem (lst) 
    (cond 
        ((null (cdr lst)) (car lst))
        (t (findLastElem (cdr lst)))))

(defun liniarp (lst) 
    (cond 
        ((null lst) t)
        ((listp (car lst)) nil)
        (t (liniarp (cdr lst)))))

(defun replaceWithLast (lst) 
    (cond 
        ((null lst) nil)
        ((listp (car lst)) (cons (findLastElem (car lst)) (replaceWithLast (cdr lst))))
        (t (cons (car lst) (replaceWithLast (cdr lst))))))

(defun main (lst) 
    (if (not (liniarp lst))
        (main (replaceWithLast lst))
        lst))

(print (main '(a (b c) (d (e (f))))))
(print (main '(a (b c) (d ((e) f)))))
