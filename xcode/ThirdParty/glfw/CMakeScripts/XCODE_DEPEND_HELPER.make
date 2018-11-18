# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glfw.Debug:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a


PostBuild.boing.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/boing.app/Contents/MacOS/boing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/boing.app/Contents/MacOS/boing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/boing.app/Contents/MacOS/boing


PostBuild.gears.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/gears.app/Contents/MacOS/gears
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/gears.app/Contents/MacOS/gears:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/gears.app/Contents/MacOS/gears


PostBuild.heightmap.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/heightmap.app/Contents/MacOS/heightmap
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/heightmap.app/Contents/MacOS/heightmap:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/heightmap.app/Contents/MacOS/heightmap


PostBuild.offscreen.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/offscreen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/offscreen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/offscreen


PostBuild.particles.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/particles.app/Contents/MacOS/particles
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/particles.app/Contents/MacOS/particles:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/particles.app/Contents/MacOS/particles


PostBuild.sharing.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/sharing.app/Contents/MacOS/sharing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/sharing.app/Contents/MacOS/sharing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/sharing.app/Contents/MacOS/sharing


PostBuild.simple.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/simple.app/Contents/MacOS/simple
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/simple.app/Contents/MacOS/simple:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/simple.app/Contents/MacOS/simple


PostBuild.splitview.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/splitview.app/Contents/MacOS/splitview
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/splitview.app/Contents/MacOS/splitview:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/splitview.app/Contents/MacOS/splitview


PostBuild.wave.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/wave.app/Contents/MacOS/wave
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/wave.app/Contents/MacOS/wave:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Debug/wave.app/Contents/MacOS/wave


PostBuild.clipboard.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/clipboard
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/clipboard:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/clipboard


PostBuild.cursor.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/cursor
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/cursor:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/cursor


PostBuild.empty.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/empty.app/Contents/MacOS/empty
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/empty.app/Contents/MacOS/empty:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/empty.app/Contents/MacOS/empty


PostBuild.events.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/events
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/events:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/events


PostBuild.gamma.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/gamma.app/Contents/MacOS/gamma
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/gamma.app/Contents/MacOS/gamma:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/gamma.app/Contents/MacOS/gamma


PostBuild.glfwinfo.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/glfwinfo
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/glfwinfo:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/glfwinfo


PostBuild.icon.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/icon.app/Contents/MacOS/icon
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/icon.app/Contents/MacOS/icon:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/icon.app/Contents/MacOS/icon


PostBuild.iconify.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/iconify
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/iconify:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/iconify


PostBuild.inputlag.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/inputlag.app/Contents/MacOS/inputlag
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/inputlag.app/Contents/MacOS/inputlag:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/inputlag.app/Contents/MacOS/inputlag


PostBuild.joysticks.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/joysticks.app/Contents/MacOS/joysticks
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/joysticks.app/Contents/MacOS/joysticks:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/joysticks.app/Contents/MacOS/joysticks


PostBuild.monitors.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/monitors
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/monitors:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/monitors


PostBuild.msaa.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/msaa
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/msaa:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/msaa


PostBuild.opacity.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/opacity.app/Contents/MacOS/opacity
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/opacity.app/Contents/MacOS/opacity:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/opacity.app/Contents/MacOS/opacity


PostBuild.reopen.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/reopen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/reopen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/reopen


PostBuild.tearing.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/tearing.app/Contents/MacOS/tearing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/tearing.app/Contents/MacOS/tearing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/tearing.app/Contents/MacOS/tearing


PostBuild.threads.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/threads.app/Contents/MacOS/threads
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/threads.app/Contents/MacOS/threads:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/threads.app/Contents/MacOS/threads


PostBuild.timeout.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/timeout.app/Contents/MacOS/timeout
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/timeout.app/Contents/MacOS/timeout:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/timeout.app/Contents/MacOS/timeout


PostBuild.title.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/title.app/Contents/MacOS/title
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/title.app/Contents/MacOS/title:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/title.app/Contents/MacOS/title


PostBuild.windows.Debug:
PostBuild.glfw.Debug: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/windows.app/Contents/MacOS/windows
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/windows.app/Contents/MacOS/windows:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Debug/windows.app/Contents/MacOS/windows


PostBuild.glfw.Release:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a


PostBuild.boing.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/boing.app/Contents/MacOS/boing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/boing.app/Contents/MacOS/boing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/boing.app/Contents/MacOS/boing


PostBuild.gears.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/gears.app/Contents/MacOS/gears
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/gears.app/Contents/MacOS/gears:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/gears.app/Contents/MacOS/gears


PostBuild.heightmap.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/heightmap.app/Contents/MacOS/heightmap
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/heightmap.app/Contents/MacOS/heightmap:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/heightmap.app/Contents/MacOS/heightmap


PostBuild.offscreen.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/offscreen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/offscreen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/offscreen


PostBuild.particles.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/particles.app/Contents/MacOS/particles
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/particles.app/Contents/MacOS/particles:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/particles.app/Contents/MacOS/particles


PostBuild.sharing.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/sharing.app/Contents/MacOS/sharing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/sharing.app/Contents/MacOS/sharing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/sharing.app/Contents/MacOS/sharing


PostBuild.simple.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/simple.app/Contents/MacOS/simple
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/simple.app/Contents/MacOS/simple:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/simple.app/Contents/MacOS/simple


PostBuild.splitview.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/splitview.app/Contents/MacOS/splitview
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/splitview.app/Contents/MacOS/splitview:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/splitview.app/Contents/MacOS/splitview


PostBuild.wave.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/wave.app/Contents/MacOS/wave
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/wave.app/Contents/MacOS/wave:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/Release/wave.app/Contents/MacOS/wave


PostBuild.clipboard.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/clipboard
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/clipboard:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/clipboard


PostBuild.cursor.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/cursor
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/cursor:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/cursor


PostBuild.empty.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/empty.app/Contents/MacOS/empty
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/empty.app/Contents/MacOS/empty:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/empty.app/Contents/MacOS/empty


PostBuild.events.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/events
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/events:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/events


PostBuild.gamma.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/gamma.app/Contents/MacOS/gamma
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/gamma.app/Contents/MacOS/gamma:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/gamma.app/Contents/MacOS/gamma


PostBuild.glfwinfo.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/glfwinfo
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/glfwinfo:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/glfwinfo


PostBuild.icon.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/icon.app/Contents/MacOS/icon
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/icon.app/Contents/MacOS/icon:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/icon.app/Contents/MacOS/icon


PostBuild.iconify.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/iconify
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/iconify:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/iconify


PostBuild.inputlag.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/inputlag.app/Contents/MacOS/inputlag
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/inputlag.app/Contents/MacOS/inputlag:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/inputlag.app/Contents/MacOS/inputlag


PostBuild.joysticks.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/joysticks.app/Contents/MacOS/joysticks
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/joysticks.app/Contents/MacOS/joysticks:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/joysticks.app/Contents/MacOS/joysticks


PostBuild.monitors.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/monitors
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/monitors:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/monitors


PostBuild.msaa.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/msaa
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/msaa:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/msaa


PostBuild.opacity.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/opacity.app/Contents/MacOS/opacity
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/opacity.app/Contents/MacOS/opacity:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/opacity.app/Contents/MacOS/opacity


PostBuild.reopen.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/reopen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/reopen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/reopen


PostBuild.tearing.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/tearing.app/Contents/MacOS/tearing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/tearing.app/Contents/MacOS/tearing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/tearing.app/Contents/MacOS/tearing


PostBuild.threads.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/threads.app/Contents/MacOS/threads
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/threads.app/Contents/MacOS/threads:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/threads.app/Contents/MacOS/threads


PostBuild.timeout.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/timeout.app/Contents/MacOS/timeout
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/timeout.app/Contents/MacOS/timeout:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/timeout.app/Contents/MacOS/timeout


PostBuild.title.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/title.app/Contents/MacOS/title
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/title.app/Contents/MacOS/title:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/title.app/Contents/MacOS/title


PostBuild.windows.Release:
PostBuild.glfw.Release: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/windows.app/Contents/MacOS/windows
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/windows.app/Contents/MacOS/windows:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/Release/windows.app/Contents/MacOS/windows


PostBuild.glfw.MinSizeRel:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a


PostBuild.boing.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/boing.app/Contents/MacOS/boing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/boing.app/Contents/MacOS/boing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/boing.app/Contents/MacOS/boing


PostBuild.gears.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/gears.app/Contents/MacOS/gears
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/gears.app/Contents/MacOS/gears:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/gears.app/Contents/MacOS/gears


PostBuild.heightmap.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/heightmap.app/Contents/MacOS/heightmap
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/heightmap.app/Contents/MacOS/heightmap:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/heightmap.app/Contents/MacOS/heightmap


PostBuild.offscreen.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/offscreen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/offscreen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/offscreen


PostBuild.particles.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/particles.app/Contents/MacOS/particles
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/particles.app/Contents/MacOS/particles:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/particles.app/Contents/MacOS/particles


PostBuild.sharing.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/sharing.app/Contents/MacOS/sharing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/sharing.app/Contents/MacOS/sharing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/sharing.app/Contents/MacOS/sharing


PostBuild.simple.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/simple.app/Contents/MacOS/simple
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/simple.app/Contents/MacOS/simple:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/simple.app/Contents/MacOS/simple


PostBuild.splitview.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/splitview.app/Contents/MacOS/splitview
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/splitview.app/Contents/MacOS/splitview:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/splitview.app/Contents/MacOS/splitview


PostBuild.wave.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/wave.app/Contents/MacOS/wave
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/wave.app/Contents/MacOS/wave:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/MinSizeRel/wave.app/Contents/MacOS/wave


PostBuild.clipboard.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/clipboard
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/clipboard:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/clipboard


PostBuild.cursor.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/cursor
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/cursor:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/cursor


PostBuild.empty.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/empty.app/Contents/MacOS/empty
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/empty.app/Contents/MacOS/empty:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/empty.app/Contents/MacOS/empty


PostBuild.events.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/events
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/events:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/events


PostBuild.gamma.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/gamma.app/Contents/MacOS/gamma
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/gamma.app/Contents/MacOS/gamma:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/gamma.app/Contents/MacOS/gamma


PostBuild.glfwinfo.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/glfwinfo
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/glfwinfo:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/glfwinfo


PostBuild.icon.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/icon.app/Contents/MacOS/icon
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/icon.app/Contents/MacOS/icon:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/icon.app/Contents/MacOS/icon


PostBuild.iconify.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/iconify
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/iconify:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/iconify


PostBuild.inputlag.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/inputlag.app/Contents/MacOS/inputlag
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/inputlag.app/Contents/MacOS/inputlag:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/inputlag.app/Contents/MacOS/inputlag


PostBuild.joysticks.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/joysticks.app/Contents/MacOS/joysticks
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/joysticks.app/Contents/MacOS/joysticks:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/joysticks.app/Contents/MacOS/joysticks


PostBuild.monitors.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/monitors
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/monitors:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/monitors


PostBuild.msaa.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/msaa
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/msaa:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/msaa


PostBuild.opacity.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/opacity.app/Contents/MacOS/opacity
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/opacity.app/Contents/MacOS/opacity:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/opacity.app/Contents/MacOS/opacity


PostBuild.reopen.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/reopen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/reopen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/reopen


PostBuild.tearing.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/tearing.app/Contents/MacOS/tearing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/tearing.app/Contents/MacOS/tearing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/tearing.app/Contents/MacOS/tearing


PostBuild.threads.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/threads.app/Contents/MacOS/threads
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/threads.app/Contents/MacOS/threads:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/threads.app/Contents/MacOS/threads


PostBuild.timeout.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/timeout.app/Contents/MacOS/timeout
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/timeout.app/Contents/MacOS/timeout:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/timeout.app/Contents/MacOS/timeout


PostBuild.title.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/title.app/Contents/MacOS/title
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/title.app/Contents/MacOS/title:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/title.app/Contents/MacOS/title


PostBuild.windows.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/windows.app/Contents/MacOS/windows
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/windows.app/Contents/MacOS/windows:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/MinSizeRel/windows.app/Contents/MacOS/windows


PostBuild.glfw.RelWithDebInfo:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a


PostBuild.boing.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/boing.app/Contents/MacOS/boing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/boing.app/Contents/MacOS/boing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/boing.app/Contents/MacOS/boing


PostBuild.gears.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/gears.app/Contents/MacOS/gears
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/gears.app/Contents/MacOS/gears:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/gears.app/Contents/MacOS/gears


PostBuild.heightmap.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/heightmap.app/Contents/MacOS/heightmap
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/heightmap.app/Contents/MacOS/heightmap:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/heightmap.app/Contents/MacOS/heightmap


PostBuild.offscreen.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/offscreen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/offscreen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/offscreen


PostBuild.particles.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/particles.app/Contents/MacOS/particles
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/particles.app/Contents/MacOS/particles:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/particles.app/Contents/MacOS/particles


PostBuild.sharing.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/sharing.app/Contents/MacOS/sharing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/sharing.app/Contents/MacOS/sharing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/sharing.app/Contents/MacOS/sharing


PostBuild.simple.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/simple.app/Contents/MacOS/simple
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/simple.app/Contents/MacOS/simple:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/simple.app/Contents/MacOS/simple


PostBuild.splitview.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/splitview.app/Contents/MacOS/splitview
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/splitview.app/Contents/MacOS/splitview:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/splitview.app/Contents/MacOS/splitview


PostBuild.wave.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/wave.app/Contents/MacOS/wave
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/wave.app/Contents/MacOS/wave:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/examples/RelWithDebInfo/wave.app/Contents/MacOS/wave


PostBuild.clipboard.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/clipboard
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/clipboard:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/clipboard


PostBuild.cursor.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/cursor
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/cursor:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/cursor


PostBuild.empty.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/empty.app/Contents/MacOS/empty
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/empty.app/Contents/MacOS/empty:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/empty.app/Contents/MacOS/empty


PostBuild.events.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/events
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/events:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/events


PostBuild.gamma.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/gamma.app/Contents/MacOS/gamma
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/gamma.app/Contents/MacOS/gamma:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/gamma.app/Contents/MacOS/gamma


PostBuild.glfwinfo.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/glfwinfo
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/glfwinfo:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/glfwinfo


PostBuild.icon.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/icon.app/Contents/MacOS/icon
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/icon.app/Contents/MacOS/icon:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/icon.app/Contents/MacOS/icon


PostBuild.iconify.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/iconify
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/iconify:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/iconify


PostBuild.inputlag.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/inputlag.app/Contents/MacOS/inputlag
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/inputlag.app/Contents/MacOS/inputlag:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/inputlag.app/Contents/MacOS/inputlag


PostBuild.joysticks.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/joysticks.app/Contents/MacOS/joysticks
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/joysticks.app/Contents/MacOS/joysticks:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/joysticks.app/Contents/MacOS/joysticks


PostBuild.monitors.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/monitors
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/monitors:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/monitors


PostBuild.msaa.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/msaa
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/msaa:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/msaa


PostBuild.opacity.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/opacity.app/Contents/MacOS/opacity
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/opacity.app/Contents/MacOS/opacity:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/opacity.app/Contents/MacOS/opacity


PostBuild.reopen.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/reopen
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/reopen:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/reopen


PostBuild.tearing.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/tearing.app/Contents/MacOS/tearing
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/tearing.app/Contents/MacOS/tearing:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/tearing.app/Contents/MacOS/tearing


PostBuild.threads.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/threads.app/Contents/MacOS/threads
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/threads.app/Contents/MacOS/threads:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/threads.app/Contents/MacOS/threads


PostBuild.timeout.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/timeout.app/Contents/MacOS/timeout
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/timeout.app/Contents/MacOS/timeout:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/timeout.app/Contents/MacOS/timeout


PostBuild.title.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/title.app/Contents/MacOS/title
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/title.app/Contents/MacOS/title:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/title.app/Contents/MacOS/title


PostBuild.windows.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/windows.app/Contents/MacOS/windows
/Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/windows.app/Contents/MacOS/windows:\
	/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidantoon/git/project-kiwiapps-ltd/build/ThirdParty/glfw/tests/RelWithDebInfo/windows.app/Contents/MacOS/windows




# For each target create a dummy ruleso the target does not have to exist
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Debug/libglfw3.a:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/MinSizeRel/libglfw3.a:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/RelWithDebInfo/libglfw3.a:
/Users/davidantoon/git/project-kiwiapps-ltd/build/lib/Release/libglfw3.a:
