# Overlay Template for TCLB [![](https://img.shields.io/badge/use%20this-template-blue?logo=github)](https://github.com/new?template_name=TCLB_overlay&template_owner=CFD-GO)

This is a template repository for a overlay repository for [TCLB Solver](https://github.com/CFD-GO/TCLB). Kind of a layer you can put on top of the TCLB's repository to allow you to develop and share your models or cases in your own repo, without the "baggage" of the main repo.

## How to use
After you create your own repository from this template you can:
```bash
git clone git@github.com:your_user/your_repo.git project
cd project
./update.sh
```

The update `script.sh` will checkout all the files of the TCLB solver and the two repositories (TCLB, and your overlay) will share the same directory. You can operate on your repository with the standard `git` commands with:
```bash
cp examples/flow/2d/karman.xml ./
## edit karman.xml with your favorite editor
git add karman.xml
git commit -m "My karman case"
git push
```

## Advanced use

### Selecting TCLB repo and branch
You can select the repo and branch with the `--tclb url@branch` option:
```bash
./update.sh --tclb git@github.com/my_user/TCLB.git # the my_user's fork
./update.sh --tclb git@github.com/my_user/TCLB.git@develop # develop branch from my_user's fork
./update.sh --tclb @develop # develop branch from the main repository
```

### Saving the default TCLB repo and branch
You can create a file `.overlay.config` with the default TCLB fork and branch to use when `./update.sh` is run:
```bash
> cat .overlay.config
TCLB_FORK='my_user/TCLB'
TCLB_BRANCH='develop'
> git add .overlay.config
> git commit -m "Adding default TCLB repo and branch"
```
You can also use the commandline option from the previous section with `--save` to create this file.

### Operating on TCLB repository
And can operate on the TCLB repository with `git tclb` command:
```bash
git tclb remote add myfork git@github.com:my_user/TCLB.git
git tclb fetch myfork
git tclb switch -c fix/stuff
## fixing stuff in TCLB
git tclb commit -a -m "I fixed stuff"
git tclb push myfork fix/stuff
## Open pull request at:
## https://github.com/my_user/TCLB/pull/new/fix/stuff
```
