; Definiti o functie care interclaseaza fara pastrarea dublurilor doua liste liniare sortate

(defun makeSetFromSortedLst (lst) 
    (cond 
        ((null lst) nil)
        ((equal (car lst) (cadr lst)) (makeSetFromSortedLst (cdr lst)))
        (t (cons (car lst) (makeSetFromSortedLst (cdr lst))))))

(defun mergeLists (firstLst secondLst) 
    (cond 
        ((and (null firstLst) (null secondLst)) nil)
        ((null firstLst) secondLst)
        ((null secondLst) firstLst)
        ((< (car firstLst) (car secondLst))
            (cons (car firstLst) (mergeLists (cdr firstLst) secondLst)))
        (t (cons (car secondLst) (mergeLists firstLst (cdr secondLst))))))
 
 (defun main (firstLst secondLst) 
    (makeSetFromSortedLst (mergeLists firstLst secondLst)))
 
 (defun mergeIntoSet (firstLst secondLst) 
    (cond
        ((and (null firstLst) (null secondLst)) nil)
        ((null firstLst) secondLst)
        ((null secondLst) firstLst)
        ((equal (car firstLst) (car secondLst)) 
            (mergeIntoSet firstLst (cdr secondLst)))
        ((< (car firstLst) (car secondLst))
            (cons (car firstLst) (mergeIntoSet (cdr firstLst) secondLst)))
        (t (cons (car secondLst) (mergeIntoSet firstLst (cdr secondLst))))))
 

 
 (print (mergeIntoSet '(1 3 6 8) '(2 3 3 6 9 10)))
