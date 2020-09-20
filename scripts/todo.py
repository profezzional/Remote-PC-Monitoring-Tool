import os
import glob

print(os.getcwd())

global output
output = "| File | To-Do |\n|---|---|\n"

todoVariants = ["//todo: ", "//TODO: ", "// todo: ", "// TODO: "]


def logTodo(line, variant, filename):
	global output
	index = line.index(variant)
	todoText = line[index + len(variant):-1]
	output += "| [" + os.path.basename(filename) + "](" + filename.replace("\\","/")  + ") | " + todoText + " |\n"


def findTodos(filename):
	with open(filename) as f:
		for line in f:
			for variant in todoVariants:
				if variant in line:
					logTodo(line, variant, filename)



dirs = ['../Remote-PC-Monitoring-Tool/server/', "../Remote-PC-Monitoring-Tool/NvidiaGpu/"]
extensions = [".cpp", ".hpp", ".h"]


for folder in dirs:
	for ext in extensions:
		for filename in glob.glob(folder + "*" + ext):
			findTodos(filename)

print(output)
outputFile = open("../docs/todo.md", "w")
outputFile.write(output)
outputFile.close()