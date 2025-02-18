(defun G (L) 
    (list (car L) (car L)))

(setq Q 'G)
(setq P Q)
(print (funcall P '(A B C)))