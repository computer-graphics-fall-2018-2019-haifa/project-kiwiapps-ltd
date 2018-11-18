# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.imgui.Debug:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libimgui.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libimgui.a


PostBuild.imgui.Release:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libimgui.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libimgui.a


PostBuild.imgui.MinSizeRel:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libimgui.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libimgui.a


PostBuild.imgui.RelWithDebInfo:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libimgui.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libimgui.a




# For each target create a dummy ruleso the target does not have to exist
