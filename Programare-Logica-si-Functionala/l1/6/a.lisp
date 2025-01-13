; Sa se scrie de doua ori elementul de pe pozitia a n-a a unei liste liniare. De exemplu, pentru (10 20 30 40 50) si n=3 se va produce (10 20 30 30 40 50).

(defun doubleNthElem (lst n curr)
  (cond
    ((null lst) nil)
    ((= curr n) 
      (cons (car lst) 
            (cons (car lst) 
                  (doubleNthElem (cdr lst) n (+ curr 1)))))
    (t (cons (car lst) (doubleNthElem (cdr lst) n (+ curr 1))))))

(defun main (lst n)
  (doubleNthElem lst n 1))

(print (main '(1 2 3 4 5) 3))