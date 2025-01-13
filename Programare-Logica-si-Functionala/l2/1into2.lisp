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

(defun build-tree (tree)
    (cond
        ((null tree) nil)  
        ((= (cadr tree) 0) 
            (list (car tree)))
        (t 
            (cons 
                (car tree)
                (append
                    (list (build-tree (left-subtree tree)))
                    (list (build-tree (right-subtree tree))))))))

(print (build-tree '(A 2 B 0 C 2 D 0 E 0)))