; Definiti o functie care intoarce cel mai mare divizor comun al numerelor dintr-o lista neliniara.

(defun cmmdc (a b)
  (if (equal b 0)
    a
    (cmmdc b (mod a b))))

(defun listCmmdc (lst)
  (if (null (cdr lst))
    (car lst)
    (cmmdc (car lst) (listCmmdc (cdr lst)))))

(print (listCmmdc '(9 6 12))),
