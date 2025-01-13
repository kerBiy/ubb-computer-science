; Sa se scrie o functie care realizeaza o lista de asociere cu cele doua liste pe care le primeste. De ex: (A B C) (X Y Z) --> ((A.X) (B.Y) (C.Z))

(defun combineLists (firstList secondList)
    (cond 
        ((and (null firstList) (null secondList)) nil)
        ((null secondList) (cons 
                                (list (car firstList))
                                (combineLists (cdr firstList) (cdr secondList)))) 
        ((null firstList) (cons 
                                (list (car secondList))
                                (combineLists (cdr firstList) (cdr secondList)))) 
        (t (cons 
                (list (car firstList) (car secondList)) 
                (combineLists (cdr firstList) (cdr secondList))))))

(print (combineLists '(A B C) '(X Y Z D H)))
