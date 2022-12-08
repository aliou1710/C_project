##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Tree
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi"
ProjectPath            :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/Tree"
IntermediateDirectory  :=../build-$(ConfigurationName)/Tree
OutDir                 :=../build-$(ConfigurationName)/Tree
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aliou
Date                   :=12/05/2022
CodeLitePath           :="D:/Cours bloc MA1/Algorithmique structure/cours/CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   := -std=c90  -pedantic-errors -Wall -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=D:\Cours bloc MA1\Algorithmique  structure\cours\CodeLite
Objects0=../build-$(ConfigurationName)/Tree/src_allocator.c$(ObjectSuffix) ../build-$(ConfigurationName)/Tree/src_tree.c$(ObjectSuffix) ../build-$(ConfigurationName)/Tree/src_TreeDemo.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Tree/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Tree" mkdir "..\build-$(ConfigurationName)\Tree"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Tree" mkdir "..\build-$(ConfigurationName)\Tree"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Tree/.d:
	@if not exist "..\build-$(ConfigurationName)\Tree" mkdir "..\build-$(ConfigurationName)\Tree"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Tree/src_allocator.c$(ObjectSuffix): src/allocator.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/Tree/src/allocator.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_allocator.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Tree/src_allocator.c$(PreprocessSuffix): src/allocator.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Tree/src_allocator.c$(PreprocessSuffix) src/allocator.c

../build-$(ConfigurationName)/Tree/src_tree.c$(ObjectSuffix): src/tree.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/Tree/src/tree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tree.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Tree/src_tree.c$(PreprocessSuffix): src/tree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Tree/src_tree.c$(PreprocessSuffix) src/tree.c

../build-$(ConfigurationName)/Tree/src_TreeDemo.c$(ObjectSuffix): src/TreeDemo.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/Tree/src/TreeDemo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TreeDemo.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Tree/src_TreeDemo.c$(PreprocessSuffix): src/TreeDemo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Tree/src_TreeDemo.c$(PreprocessSuffix) src/TreeDemo.c

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


