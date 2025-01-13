; Sa se tipareasca lista nodurilor de pe nivelul k

(defun left-subtree (tree)
    (cadr tree))

(defun right-subtree (tree) 
    (caddr tree))

(defun getKLevel (tree k)
    (cond
        ((null tree) nil)
        ((equal k 0) (list (car tree)))
        (t (append 
                (getKLevel (left-subtree tree) (- k 1))
                (getKLevel (right-subtree tree) (- k 1))))))

(print (getKLevel '(A (B) (C (D) (E))) 1))
(print (getKLevel '(A (B) (C (D) (E))) 2))
(print (getKLevel '(A (B) (C (D) (E))) 0))