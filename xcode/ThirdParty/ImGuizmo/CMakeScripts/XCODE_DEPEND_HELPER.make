# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ImGuizmo.Debug:
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/Debug/libImGuizmo.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/Debug/libImGuizmo.a


PostBuild.ImGuizmo.Release:
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/Release/libImGuizmo.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/Release/libImGuizmo.a


PostBuild.ImGuizmo.MinSizeRel:
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/MinSizeRel/libImGuizmo.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/MinSizeRel/libImGuizmo.a


PostBuild.ImGuizmo.RelWithDebInfo:
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/RelWithDebInfo/libImGuizmo.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/ImGuizmo/RelWithDebInfo/libImGuizmo.a




# For each target create a dummy ruleso the target does not have to exist
