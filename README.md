# NTNU_import_magic's  Codebook
The codebook repository for team NTNU_import_magic. Furthur tutorial of LaTeX and detailed information is currently WIP. 

# Install

- Download and Install *[思源黑體](https://www.beforafter.org/blog/source-han-sans-font)*

  ```bash
   cd ~/Desktop/
   wget https://noto-website.storage.googleapis.com/pkgs/NotoSansCJKtc-hinted.zip
   sudo unzip NotoSansCJKtc-hinted.zip -d /usr/share/fonts/Noto\ Sans\ CJK\ TC/
   # Do environment specific installation
  ```

- Download and Install *Consolas*

  ```bash
   cd ~/Desktop/
   wget https://github.com/kakkoyun/linux.files/raw/master/fonts/Consolas.ttf
   # Do environment specific installation
  ```

- Install *Fira Code*

  - Ubuntu >= 17.04 or Debian >= 9

    ```bash
    sudo apt install fonts-firacode
    ```

  - Mac OS X

    ```bash
    brew tap homebrew/cask-fonts
    brew cask install font-fira-code
    ```

    

## Linux

```bash
 sudo apt-get -y install 	texlive \
 				texlive-full \
 				gedit-latex-plugin \
 				texlive-fonts-recommended \
 				latex-beamer \
 				texpower \
 				texlive-pictures \
 				texlive-latex-extra \
 				texpower-examples \
 				imagemagick
```

## Mac OS X(x86)

- Insall MacTex & rubber

  ```bash
  brew cask install mactex
  ```

# Build

Simply run `make` in "codebook" directory and everything will be good to go.

# Recommended Tools for editing LaTeX

- texmaker
- texshop
- Visual Studio Code Plugin - LaTeX Workshop