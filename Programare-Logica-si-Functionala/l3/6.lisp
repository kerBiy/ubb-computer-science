; 6. Sa se construiasca o functie care intoarce produsul atomilor numerici dintr-o lista, de la orice nivel.

; product (x: list)
; x - lista de unde luam elementele

; Modelul matematic:
; product (x) =
;     x, daca x este numar
;     1, daca x aste atom, dar nu este numar
;     * (x E 1, n) product (xi), unde x = (x1x2...xn)

(defun product (x)
  (cond
    ((numberp x) x)
    ((atom x) 1)
    (t (apply '* (mapcar #'product x)))))

(print (product '(1 2 3 4)))             ; => 24
(print (product '(1 2 (3 (4 5)))))       ; => 120
(print (product '(1 a (2 b (3 c)))))     ; => 6
(print (product '(a b c)))               ; => 1
(print (product '()))                    ; => 1