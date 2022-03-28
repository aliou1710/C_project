##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=List
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi"
ProjectPath            :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/List"
IntermediateDirectory  :=../build-$(ConfigurationName)/List
OutDir                 :=../build-$(ConfigurationName)/List
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aliou
Date                   :=28/03/2022
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
Objects0=../build-$(ConfigurationName)/List/src_list.c$(ObjectSuffix) ../build-$(ConfigurationName)/List/src_ListDemo.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/List/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\List" mkdir "..\build-$(ConfigurationName)\List"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\List" mkdir "..\build-$(ConfigurationName)\List"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/List/.d:
	@if not exist "..\build-$(ConfigurationName)\List" mkdir "..\build-$(ConfigurationName)\List"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/List/src_list.c$(ObjectSuffix): src/list.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/List/src/list.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_list.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/List/src_list.c$(PreprocessSuffix): src/list.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/List/src_list.c$(PreprocessSuffix) src/list.c

../build-$(ConfigurationName)/List/src_ListDemo.c$(ObjectSuffix): src/ListDemo.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/List/src/ListDemo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ListDemo.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/List/src_ListDemo.c$(PreprocessSuffix): src/ListDemo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/List/src_ListDemo.c$(PreprocessSuffix) src/ListDemo.c

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


