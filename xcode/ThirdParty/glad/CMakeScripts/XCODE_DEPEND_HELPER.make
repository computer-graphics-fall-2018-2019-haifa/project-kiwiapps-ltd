# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glad.Debug:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglad.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglad.a


PostBuild.glad.Release:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglad.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglad.a


PostBuild.glad.MinSizeRel:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglad.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglad.a


PostBuild.glad.RelWithDebInfo:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglad.a




# For each target create a dummy ruleso the target does not have to exist
