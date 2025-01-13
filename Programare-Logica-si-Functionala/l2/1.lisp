
#|
  contains-node(tree: list, element: atom)
  tree: o lista cu reprezentarea 1 a unui arbore
  element: elementul cautat in arbore

  Model matematic:

  contains-node(t1t2...tn, element) =
    nil,    daca n = 0
    adevarat,   daca t1 = element
    contains-node(t3...tn, elemnet), altfel
 |#
(defun contains-node (tree element)
  (cond 
    ((null tree) nil)
    ((eq (car tree) element) t)
    (t (contains-node (cddr tree) element))))

#|
  traverse-left(tree: list, nodes: int, edges: int)
  tree: arbore
  nodes: numarul de noduri vizitate 
  edges: numarul de muchii totale 
  Traverseaza arborele stang

  Modelul matematic:

  traverse-left(t1t2t3...tn, nodes, edges) =
      nil,    n = 0
      nil,    nodes = edges + 1
      t1 U t2 U traverse-left(t3...tn, nodes + 1, edges + t2)
 |#
(defun traverse-left (tree nodes edges)
  (cond
    ((null tree) nil)
    ((= nodes (+ 1 edges)) nil)
    (t (cons (car tree) 
             (cons (cadr tree) 
                   (traverse-left (cddr tree) (+ 1 nodes) 
                                  (+ (cadr tree) edges)))))))

#|
  traverse-right(tree: list, nodes: int, edges: int)
  tree: arbore
  nodes: numarul de noduri vizitate 
  edges: numarul de muchii totale 
  Traverseaza arborele drept

  Modelul matematic:

  traverse-right(t1t2t3...tn, nodes, edges) =
      nil,    n = 0
      t1t2...tn,    nodes = edges + 1
      traverse-right(t3...tn, nodes + 1, edges + t2)
 |#
(defun traverse-right (tree nodes edges)
  (cond
    ((null tree) nil)
    ((= nodes (+ 1 edges)) tree)
    (t (traverse-right (cddr tree) (+ 1 nodes) (+ (cadr tree) edges)))))

#|
  left-subtree(tree: list)
  tree: arbore cu reprezentarea 1
  Helper function petnru arborele stang

  Model matematic:

  left-subtree(t1t2t3...tn) = traverse-left(t3...tn, 0, 0)
 |#
(defun left-subtree (tree)
  (traverse-left (cddr tree) 0 0))

#|
  right-subtree(tree: list)
  tree: arbore cu reprezentarea 1
  Helper function petnru arborele drept 

  Model matematic:

  right-subtree(t1t2t3...tn) = traverse-right(t3...tn, 0, 0)
 |#
(defun right-subtree (tree)
  (traverse-right (cddr tree) 0 0))

#|
  find-path-to-node(tree: list, element: atom)
  tree: arbore cu reprezentarea 1
  element: elementul care trebuie gasit
  Gaseste calea pana la element

  Model matematic:

  find-path-to-node(t1t2t3...tn, element) =
    nil,    daca n = 0
    [t1],   daca t1 = element

    t1 U find-path-to-node(left-subtree(tree), element),
      daca nodul este in subarborele stang

    t1 U find-path-to-node(right-subtree(tree), element),
      altfel (nodul este in subarborele drept)
 |#
(defun find-path-to-node (tree element)
  (cond
    ((null tree) nil) 
    ((eq (car tree) element) (list (car tree))) 
    ((contains-node (left-subtree tree) element) 
     (cons (car tree) (find-path-to-node (left-subtree tree) element))) 
    (t 
     (cons (car tree) (find-path-to-node (right-subtree tree) element)))))

#|
  find-path(tree: list, element: atom)
  tree: arbore cu reprezentarea 1
  element: elementul care trebuie gasit
  Gaseste calea pana la element (main function)

  Model matematic:

  find-path(t1t2...tn, element) =
    find-path-to-node(t1t2...tn, elment), daca elementul se afla in arbore
    nil, altfel
 |#
(defun find-path (tree element)
  (if (contains-node tree element)
      (find-path-to-node tree element)))


#|
  Teste:
 |#
; (print (find-path '(A 2 B 0 C 2 D 0 E 0) 'F))
; (print (find-path '(A 2 B 0 C 2 D 0 E 0) 'A))
; (print (find-path '(A 2 B 0 C 2 D 0 E 0) 'D))
; (print (find-path '(a 2 b 1 d 1 e 1 f 2 g 0 h 2 j 0 k 0 c 2 l 2 n 0 q 2 p 0 r 0 m 0) 'r))
; (print (find-path '(a 2 b 1 d 1 e 1 f 2 g 0 h 2 j 0 k 0 c 2 l 2 n 0 q 2 p 0 r 0 m 0) 'k))
(print (find-path '(a 2 b 2 d 1 g 0 e 2 h 1 l 2 m 0 n 0 i 0 c 1 f 2 j 0 k 1 q 1 p 2 r 0 s 0) 's))
