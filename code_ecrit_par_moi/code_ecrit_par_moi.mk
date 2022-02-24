##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=code_ecrit_par_moi
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi"
ProjectPath            :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/code_ecrit_par_moi"
IntermediateDirectory  :=../build-$(ConfigurationName)/code_ecrit_par_moi
OutDir                 :=../build-$(ConfigurationName)/code_ecrit_par_moi
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aliou
Date                   :=17/02/2022
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
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=D:\Cours bloc MA1\Algorithmique  structure\cours\CodeLite
Objects0=../build-$(ConfigurationName)/code_ecrit_par_moi/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/code_ecrit_par_moi/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\code_ecrit_par_moi" mkdir "..\build-$(ConfigurationName)\code_ecrit_par_moi"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\code_ecrit_par_moi" mkdir "..\build-$(ConfigurationName)\code_ecrit_par_moi"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/code_ecrit_par_moi/.d:
	@if not exist "..\build-$(ConfigurationName)\code_ecrit_par_moi" mkdir "..\build-$(ConfigurationName)\code_ecrit_par_moi"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/code_ecrit_par_moi/main.c$(ObjectSuffix): main.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/code_ecrit_par_moi/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/code_ecrit_par_moi/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/code_ecrit_par_moi/main.c$(PreprocessSuffix) main.c

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


