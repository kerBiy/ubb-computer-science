; Se da un arbore de tipul (1). Sa se precizeze numarul de niveluri din arbore.

(defun traverse-left (tree nodes edges)
  (cond
    ((null tree) nil)
    ((= nodes (+ 1 edges)) nil)
    (t (cons (car tree) 
             (cons (cadr tree) 
                   (traverse-left (cddr tree) (+ 1 nodes) 
                                  (+ (cadr tree) edges)))))))

(defun traverse-right (tree nodes edges)
  (cond
    ((null tree) nil)
    ((= nodes (+ 1 edges)) tree)
    (t (traverse-right (cddr tree) (+ 1 nodes) (+ (cadr tree) edges)))))

(defun left-subtree (tree)
    (traverse-left (cddr tree) 0 0))

(defun right-subtree (tree) 
    (traverse-right (cddr tree) 0 0))

(defun num-levels (tree)
    (cond 
        ((null tree) -1)
        (t (max 
                (+ 1 (num-levels (left-subtree tree)))
                (+ 1 (num-levels (right-subtree tree)))))))

(print (num-levels '(A 2 B 0 C 2 D 0 E 0)))