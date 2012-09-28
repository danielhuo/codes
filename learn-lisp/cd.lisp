(defvar *db* nil)
(defun add-record (cd) (push cd *db*))
(defun make-cd (title artist rating ripped)
    (list :title title :artist artist :rating rating :ripped ripped))
(add-record (make-cd "Rose" "Kathy Mattea" 7 t))
(add-record (make-cd "Fly" "Dixie Chicks" 8 t))
(defun dump-db ()
    (format t "~{~{~a: ~10t~a~%~}~%~}" *db*))

(defun prompt-read (prompt)
 (format *query-io* "~a: " prompt)
 (force-output *query-io*)
 (read-line *query-io*))

(defun prompt-for-cd ()
 (make-cd
  (prompt-read "Title")
  (prompt-read "Artist")
  (or (parse-integer (prompt-read "Rating") :junk-allowed t) 0)
  (prompt-read "Ripped [y/]")))

(defun add-cds ()
 (loop (add-record (prompt-for-cd))
  (if (not (y-or-n-p "Another? [y/n]: ")) (return))))

(defun save-db (filename)
    (with-open-file (out filename
                     :direction :output
                     :if-exists :supersede)
     (with-standard-io-syntax
      (print *db* out))))
(defun load-db (filename)
    (with-open-file (in filename)
     (with-standard-io-syntax
      (setf *db* (read in)))))

(defun select (selector-fn)
 (remove-if-not selector-fn *db*))

(defun delete-rows (selector-fn)
 (setf *db* (remove-if selector-fn *db*)))

;(defun where (&key title artist rating (ripped nil ripped-p))
; #'(lambda (cd)
;     (and
;      (if title (equal (getf cd :title) title) t)
;      (if artist (equal (getf cd :artist) artist) t)
;      (if rating (equal (getf cd :rating) rating) t)
;      (if ripped-p (equal (getf cd :ripped) ripped) t))))

(defun make-comparison-expr (field value)
 `(equal (getf cd ,field) ,value))

(defun make-comparison-list (fields)
 (loop while fields
  collecting (make-comparison-expr (pop fields) (pop fields))))

(defmacro where (&rest clauses)
 `#'(lambda (cd) (and ,@(make-comparison-list clauses))))

(print (macroexpand-1 `(where :artist "Rose" :arting 7)))

(print (select (where :title "Rose")))
