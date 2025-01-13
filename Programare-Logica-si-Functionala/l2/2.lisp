; Sa se tipareasca lista nodurilor de pe nivelul k

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

(defun getKLevel (tree k)
    (cond
        ((null tree) nil)
        ((equal k 0) (list (car tree)))
        (t (append 
                (getKLevel (left-subtree tree) (- k 1))
                (getKLevel (right-subtree tree) (- k 1))))))

(print (getKLevel '(A 2 B 0 C 2 D 0 E 0) 1))
(print (getKLevel '(A 2 B 0 C 2 D 0 E 0) 2))