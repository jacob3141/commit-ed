![Screenshot](https://github.com/cybercatalyst/commit-ed/blob/master/commit-ed.png "Screenshot")

Specialized lightweight git commit message editor

# How to build
Run these commands in the root directory:
```
qmake
make
sudo make install
```

Then set as the default git editor:
```
git conig --global core.editor commit-ed-gui
```

