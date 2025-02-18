; (SETQ F 10)
(defun F(L) (Max (CAR L) (CADDR L)))
(SETQ G F)
(print (funcall G '(1 2 3)))