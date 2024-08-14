# Patches
Linux kernel development is done using git, started by Linus Torvalds and currently maintained by Junio C. Hamano.
Developers send changes to the kernel mailing list called *patches*.
**Maintainers have their personal preferences on how granular the patch splitting should be for their systems.**

## Tags
- Acked-by: This tag is often used by the maintainer of the affected code when that maintainer neither contributed to, nor **forwarded** the patch.
- Reviewed-by: This tag indicates that the patch has been reviewed by the person named in the tag.
- Reported-by: This tag gives credit ti people who find bugs and report them.
- Tested-by: This tag indicates that the átch has been tested by the érson named in the tag.
- Suggested-by: This tag is used to give credit for the patch idea to the person named in the tag.
- Fixes: This tag indicates that the patch fixes an issue in a previous commit referenced by its Commit ID. This tag allows us to track where the bug originated.

## Patch Email Subject Line Conventions
- [PATCH] prefix is used to indicate that the email consists of a patch.
- [PATCH RFC] or [RFC PATCH] indicates the author is requesting comments on the patch (RFC - Request For Comments).
- [PATCH v4] is used to indicatethat the patch is the 4th version of this specfic change that is being submitted. It is a requirement to include the patch version history when sending a re-worked patch. The patch revision history on what changed between the current version and the previous version is added between the "---" abd the "start of the diff" in the patch file.

**Start a new thread for each version of the patch**
