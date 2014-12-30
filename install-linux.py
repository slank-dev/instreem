
import os
import shutil
import sys



print("linux installer")
username = input("input username: ")
DEF_PROOT = "/home/" + username + "/Public/project/"
DEF_DROOT = "/home/" + username + "/.instreem/documents/"
DEF_MROOT = "/home/" + username + "/.instreem/modules/"
USER_ROOT = "/home/" + username + "/"

os.system("chmod 777 FILE/rmtree.pl");
os.system("chmod 777 FILE/help.txt");


mode = input("chose config mode(auto:1/yourself:2)? ")

if(mode == 2):
	print("this module dont make already")
	print("config path. chose exist directory")
	#project_root = input("project_root: ")
	#document_root = input("document_root: ")
	#module_root = input("module_root: ")
elif(mode == 1):
	project_root = DEF_PROOT
	document_root = DEF_DROOT
	module_root = DEF_MROOT
	
	if not os.path.exists(project_root):
		os.mkdir(project_root)
	if not os.path.exists(document_root):
		os.makedirs(document_root)
	if not os.path.exists(module_root):
		os.mkdir(module_root)
else:
	print("mode not found")
	sys.exit()


print("-------------------------------------------------------")
print("PROJECT_ROOT : %s" %  project_root)
print("DOCUMENT_ROOT: %s" %  document_root)
print("MODULE_ROOT  : %s" %  module_root)
print("-------------------------------------------------------")



f = open('.instreemrc', 'w')
w1 = "PROJECT_ROOT=" + project_root + "\n"
w2 = "DOCUMENT_ROOT=" + document_root + "\n"
w3 = "MODULE_ROOT=" + module_root + "\n"
f.write(w1)
f.write(w2)
f.write(w3)

if os.path.isfile(USER_ROOT + ".instreemrc"):
	os.remove(USER_ROOT + ".instreemrc")	
shutil.move(".instreemrc", USER_ROOT)
shutil.copy("FILE/rmtree.pl", module_root)
shutil.copy("FILE/help.txt", document_root)

os.chdir("SRC/")
os.system("g++ *.cc -o instreem")
shutil.copy("instreem", USER_ROOT)

print("out files is in home directory")

	

	
