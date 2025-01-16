; Sa se scrie o functie care sa testeze daca o lista liniara formata din
; numere intregi are aspect de "munte"(o secvență se spune ca are aspect de
; "munte" daca elementele cresc pana la un moment dat, apoi descresc.
; De ex. (10 18 29 17 11 10).

(defun is-mountain-helper (lst ascending) 
    (cond 
        ((null (cdr lst)) t)
        ((and ascending (> (car lst) (cadr lst))) 
            (is-mountain-helper (cdr lst) nil))
        ((and (not ascending) (<= (car lst) (cadr lst))) nil) 
        (t (is-mountain-helper (cdr lst) ascending)))) 

(defun is-mountain (lst) 
    (cond
        ((or (null lst) (null (cdr lst))) nil) 
        (t (is-mountain-helper lst t))))


(print (is-mountain '(10 18 29 17 11 10))) ;; => t (este munte)
(print (is-mountain '(10 18 29 30 17 11 10))) ;; => nil (nu este munte)
(print (is-mountain '(10 18 17))) ;; => t (este munte)
(print (is-mountain '(10))) ;; => nil (nu este munte)
(print (is-mountain '(10 18 29 29 17 11))) ;; => nil (nu este munte)
