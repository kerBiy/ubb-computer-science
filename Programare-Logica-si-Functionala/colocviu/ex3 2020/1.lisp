(defun F(L)
  ((lambda (expr)
    (cond
      ((null L) 0)
      ((> expr 2) (+ (car L) (F (cdr L))))
      (T expr)
    )) 
    (F (car L))
  ))