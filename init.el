(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
;; Comment/uncomment this line to enable MELPA Stable if desired.  See `package-archive-priorities`:
;; and `package-pinned-packages`. Most users will not need or want to do this.
;;(add-to-list 'package-archives '("melpa-stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)

;; Exec path from shell
(when (memq window-system '(mac ns x))
  (exec-path-from-shell-initialize))

(menu-bar-mode 0)
(tool-bar-mode 0)
(ido-mode 1)
(electric-pair-mode 1)

(setq backup-directory-alist '(("." . "~/.emacs_saves")) )

(use-package eglot :ensure t)
(use-package company :ensure t :config (global-company-mode))
(use-package nix-mode :ensure t)
(use-package rust-mode :ensure t)
(use-package zig-mode :ensure t)

(dolist (mode '(nix-mode-hook rust-mode-hook zig-mode-hook))
  (add-hook mode (lambda () (eglot-ensure) (company-mode))))

;; Smex package setup
  (global-set-key (kbd "M-x") 'smex)
  (global-set-key (kbd "M-X") 'smex-major-mode-commands)
  ;; This is your old M-x.
  (global-set-key (kbd "C-c C-c M-x") 'execute-extended-command)


;; NEXT CODE IS AUTOMATICALLY GENERATED BY EMACS

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes '(gruber-darker))
 '(custom-safe-themes
   '("e27c9668d7eddf75373fa6b07475ae2d6892185f07ebed037eedf783318761d7" default))
 '(package-selected-packages
   '(smex zig-mode rust-mode nix-mode gruber-darker-theme exec-path-from-shell consult-eglot company-math)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

