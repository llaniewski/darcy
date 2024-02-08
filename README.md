# Model Overlay for TCLB

## How to use
Just clone and update:
```bash
git clone git@github.com:llaniewski/darcy.git
cd darcy
./update.sh
make configure
./configure
make -j 16 darcy
CLB/darcy/main example/anderson.xml
CLB/darcy/main example/explicit.xml
```
