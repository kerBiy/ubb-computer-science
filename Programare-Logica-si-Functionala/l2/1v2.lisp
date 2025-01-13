(defun contains-node (tree elem)
  (cond 
    ((null tree) nil)
    ((eq (car tree) elem) t)
    ((listp (car tree)) (or (contains-node (car tree) elem) 
                            (contains-node (cdr tree) elem)))
    (t (contains-node (cdr tree) elem))))

(defun left-subtree (tree) (cadr tree)) 

(defun right-subtree (tree) (caddr tree))

(defun find-path-to-node (tree element)
  (cond
    ((null tree) nil) 
    ((eq (car tree) element) (list (car tree))) 
    ((contains-node (left-subtree tree) element) 
     (cons (car tree) (find-path-to-node (left-subtree tree) element))) 
    (t 
     (cons (car tree) (find-path-to-node (right-subtree tree) element)))))

(defun find-path (tree element)
  (if (contains-node tree element)
      (find-path-to-node tree element)))


(print (find-path '(A (B) (C (D) (E))) 'E))
(print (find-path '(A (B (D) (E (F (G) (H)))) (C (I (J (K))))) 'F)) 
(print (find-path '(A (B (D) (E (F (G) (H)))) (C (I (J (K))))) 'G)) 
(print (find-path '(A (B (D) (E (F (G) (H)))) (C (I (J (K))))) 'J)) 
(print (find-path '(A (B (D) (E (F (G) (H)))) (C (I (J (K))))) 'D)) 
