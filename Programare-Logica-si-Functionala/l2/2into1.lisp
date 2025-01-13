(defun left-subtree (tree) (cadr tree)) 

(defun right-subtree (tree) (caddr tree))

(defun linearize-tree (tree)
    (if (null tree)
        nil
        (append
            (list (car tree))       
            (list (length (cdr tree))) 
            (linearize-tree (left-subtree tree)) 
            (linearize-tree (right-subtree tree))))) 

(print (linearize-tree '(A (B) (C (D) (E)))))