import os


with open("libft copy.h", "r") as f:
	lines = f.readlines()
	lines.remove("\n")
	clean = []
	for line in lines:
		if line != "\n" and line[0] != "#" and line[0] != '/':
			clean.append(line)
			#print(line)
	for line in clean:
		if line[:7:] != "typedef":
			filename = line[line.find("ft_"):line.find("(")] + ".c"
			#print(filename)
			with open(filename, "r") as f2:
				code = f2.readlines()
				startindex = 0
				endindex = 0
				instructions = 0
				for line2 in code:
					if not startindex and line2[0] != "/" and line2.find(filename[:-2]) > 0:
						startindex = code.index(line2)
					elif startindex and line2[0] != "/" and line2[0] != '\t' and line2.find("}\n") >= 0:
						endindex = code.index(line2)
				if startindex and endindex:
					instructions = "".join(code[startindex:endindex+1])
					print(instructions)
					input()
				


	#print(clean)