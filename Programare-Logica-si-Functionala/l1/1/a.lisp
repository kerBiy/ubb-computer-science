; Sa se insereze intr-o lista liniara un atom a dat dupa al 2-lea, al 4-lea, al 6-lea,....element.

(defun insert (lst elem current) 
  (cond
    ((null lst) nil)

    ((and (equal (mod current 2) 1) (not (equal current 1))) 
      (cons elem 
        (cons (car lst) 
        (insert (cdr lst) elem (+ current 1)))))

    (t (cons 
      (car lst) 
      (insert (cdr lst) elem (+ current 1))))
  )
)

(defun main (lst elem)
  (insert lst elem 1))

(print (main '(1 2 3 4 5 6 7) 'A))