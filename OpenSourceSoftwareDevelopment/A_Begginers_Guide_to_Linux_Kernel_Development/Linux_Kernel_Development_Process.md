# Linux Kernel Development Process

## What Does the Release Cycle Look Like?
The kernel development is a continous process, but at certain points during the developmen, when a set of features and bug fixes are ready, a new version of the kerel is released. These new versions are called **keernel releases**. 
The release cycle is:
1. Linux mainline release: Linus Torvalds releases ***mainline*** stable kernel (i.e. 5.2). After that, opens a **merge window** for next release.
2. Two week merge window: Maintainers send git pull requests to Linus. Linus goes through the cycle of pulling each request and testing during the merge window.
3. Linus releases rc1 (Release Candidate 1): Merge window closed. 6 to 7 weeks integration cycle for fixing bugs and regressions after the release candidate 1 (i.e. 5.3-rc1).
4. Stable release process: First stable version released (i.e. 5.2.1) with bug fixes from mainline (5.3-rc1) with other active stable releases. Bug fixes will be included in all active stable releases.
5. Linus releases the mainline stable after rc7 or rc8 based on his confidence level on the quality.

During the 2-week merge window, subsystem maintainers send signed git pull requests to Linus either during the merge window or before. All major new development is added to the kernel during the merge window. At the end he releases the first release candidate, known as rc1.
At this point, the release cycle moves into a bug fixes-only mode, with a series of release candidate (**rc**) releases from Linus. One week after **rc1** is released, **rc2** comes out; **rc3** comes out one week after, and so on, until major bug fixes and egressions (if any) are resolved.
The new cycle begins with 3-week ***quiet period***, which starts a week before the release, and continues through the 2-week merge window. Maintainers and key contributors are busy getting their trees ready to send pul requests to Linus.

## Active Kernel Releases
- Release Candidate (RC): Release candidate or RC releases are mailine kernel pre-releases that are used for testing new features in the mainline. These releases must be compiled from source. Kernel developers test these releases for bugs and regressions.
- Stable: Stable releases are bug fix-only releases. After Linus releases a mainline kernel, it moves into stable mode. Any bug fixes for a stable kernel are backportes from the mainline kernel and applied to stable git by a designated stable kernel release maintainer. Stable kernel updates are released on avergae, once a week, or on an as needed basis.
- Long\-term: Long\-term releases are stable releases selected for long term maintenance to provide critical bug fixes for older kernel trees.


## Kernel Trees
- The Mainline kernel tree: This tree is maintained by Linus Torvalds. This is where Linus releases mainline kernels and RC releases.
- The Stable tree: This tree is maintaned by Greg Kroah-Hartman. This tree consists of stable release branches. Stable releases are based on this tree.
- The linux-next tree: This is the integration tree maintained by stephen Rothwell. Code from a large number of subsystem trees gets pulled into this tree periodically and then released for intehration testing.
