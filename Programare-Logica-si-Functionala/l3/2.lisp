; Definiti o functie care obtine dintr-o lista data lista tuturor atomilor care apar, pe orice nivel, dar in aceeasi ordine. De exemplu (((A B) C) (D E)) --> (A B C D E)

(defun get-list (lst) 
    (cond
        ((atom lst) (list lst))
        (t (mapcan #'get-list lst))))

(print (get-list '(((A B) C) (D E))))