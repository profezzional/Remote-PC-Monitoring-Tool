import os
import shutil
from sys import platform

def GetMsBuildLocation():
	paths = [
		"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe", 
		"C:/Program Files (x86)/Microsoft Visual Studio/2019/Preview/MSBuild/Current/Bin/MSBuild.exe"
	]
	for path in paths:
		if (os.path.isfile(path)):
			return path
	return ""


def GetRootDir():
	path = os.path.dirname(os.path.realpath(__file__))
	path = os.path.normpath(path + "/../")
	return path

def GetSlnDir():
	return GetRootDir() + "/server/"

def GetSlnPath():
	return GetSlnDir() + "/server.sln"

def BuildWindows():
	msBuildLocation = GetMsBuildLocation()
	if os.path.isfile(msBuildLocation) != True:
		print("MSBuild Not Found!")
		quit()
	print("MSBuild Found at: " + msBuildLocation)
	command = "\"" + msBuildLocation + "\" " + GetSlnPath() + " /t:Build /p:Configuration=Release"
	os.system(command)


def BuildDarwin():
	print("Not supported yet")


def BuildLinux():
	command = "rm " + GetRootDir() + "/CMakeCache.txt"
	os.system(command)
	command = "cmake " + GetSlnDir() + " && make"
	os.system(command)
	currentPath = GetRootDir() + "/server_linux"
	if os.path.isfile(currentPath):
		print("Moving file")
		shutil.move(currentPath, GetRootDir() + "/bin/server_linux")

if platform == "linux" or platform == "linux2":
    BuildLinux()
elif platform == "darwin":
    BuildDarwin()
elif platform == "win32":
	BuildWindows()