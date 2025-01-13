; Definiti o functie care obtine dintr-o lista data lista tuturor atomilor care apar, pe orice nivel, dar in ordine inversa. De exemplu: (((A B) C) (D E)) --> (E D C B A)

(defun makeLiniarReverse (lst)
  (cond
    ((null lst) nil)
    
    ((atom (car lst)) (append 
      (makeLiniarReverse (cdr lst)) 
      (list (car lst))))

    (t (append
      (makeLiniarReverse (cdr lst)) (makeLiniarReverse (car lst))))))

(print (makeLiniarReverse '(((A B) C) (D E))))