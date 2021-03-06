;;; signed-good.el --- A single-file package with good signature  -*- lexical-binding: t -*-

;; Author: J. R. Hacker <jrh@example.com>
;; Version: 1.0
;; Keywords: frobnicate
;; URL: http://doodles.au

;;; Commentary:

;; This package provides a minor mode to frobnicate and/or bifurcate
;; any flanges you desire.  To activate it, type "C-M-r M-3 butterfly"
;; and all your dreams will come true.

;;; Code:

(defgroup signed-good nil "Simply a file."
  :group 'lisp)

(defcustom signed-good-super-sunday t
  "How great is this?"
  :type 'boolean
  :group 'signed-good)

(defvar signed-good-sudo-sandwich nil
  "Make a sandwich?")

;;;###autoload
(define-minor-mode signed-good-mode
  "It does good things to stuff.")

(provide 'signed-good)

;;; signed-good.el ends here
