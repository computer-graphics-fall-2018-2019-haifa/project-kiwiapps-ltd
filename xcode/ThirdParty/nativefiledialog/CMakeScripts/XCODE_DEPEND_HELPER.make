# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.nativefiledialog.Debug:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libnativefiledialog.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libnativefiledialog.a


PostBuild.nativefiledialog.Release:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libnativefiledialog.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libnativefiledialog.a


PostBuild.nativefiledialog.MinSizeRel:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libnativefiledialog.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libnativefiledialog.a


PostBuild.nativefiledialog.RelWithDebInfo:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libnativefiledialog.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libnativefiledialog.a




# For each target create a dummy ruleso the target does not have to exist
