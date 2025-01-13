; Sa se scrie o functie care determina numarul de aparitii ale unui atom dat intr-o lista neliniara.

(defun elemCount (lst elem)
  (cond
    ((null lst) 0)

    ((equal (car lst) elem) (+ 1 (elemCount (cdr lst) elem)))

    ((listp (car lst)) 
      (+ 
        (elemCount (car lst) elem) 
        (elemCount (cdr lst) elem)))

    (t (elemCount (cdr lst) elem))))

(print (elemCount '(1 2 A (3 4 (5 6 2 (B)) 3 2) 7 ((3))) 'F))