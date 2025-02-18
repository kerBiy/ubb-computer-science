; Sa se inlocuiasaca nodurile de pe nivelele impare

(defun replace-odd-helper (lst elem curr-level)
    (cond
        ((and (atom lst) (oddp curr-level)) elem)
        ((and (atom lst) (evenp curr-level)) lst)
        (t (mapcar (lambda (x) (replace-odd-helper x elem (+ 1 curr-level))) lst))))

(defun replace-odd-levels (lst elem) (replace-odd-helper lst elem -1))

(print (replace-odd-levels '(a (b (g)) (c (d (e)) (f))) 'h))