; Sa se construiasca o functie care verifica daca un atom e membru al unei liste nu neaparat liniara.

(defun member-deep (x lst)
  (cond ((null lst) nil)
        ((atom lst) (equal x lst))
        (t (apply 'or (mapcar (lambda (sub) (member-deep x sub)) lst))))))

(print (member-deep '(((A B) C) (D E)) 'A))