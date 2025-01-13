; Sa se construiasca lista nodurilor unui arbore de tipul (1) parcurs in inordine.

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

(defun inorder-list (tree)
    (cond 
        ((null tree) nil)
        (t (append 
                (list (car tree)) 
                (inorder-list (left-subtree tree)) 
                (inorder-list (right-subtree tree))))))

(print (inorder-list '(A 2 B 0 C 2 D 0 E 0)))