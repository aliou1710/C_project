##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ErasthostheneDiallo
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi"
ProjectPath            :="D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/ErasthostheneDiallo"
IntermediateDirectory  :=../build-$(ConfigurationName)/ErasthostheneDiallo
OutDir                 :=../build-$(ConfigurationName)/ErasthostheneDiallo
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aliou
Date                   :=24/02/2022
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
Libs                   := $(LibrarySwitch)InOut 
ArLibs                 :=  "InOut" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../InOut/Debug 

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
Objects0=../build-$(ConfigurationName)/ErasthostheneDiallo/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/ErasthostheneDiallo/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\ErasthostheneDiallo" mkdir "..\build-$(ConfigurationName)\ErasthostheneDiallo"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\ErasthostheneDiallo" mkdir "..\build-$(ConfigurationName)\ErasthostheneDiallo"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/ErasthostheneDiallo/.d:
	@if not exist "..\build-$(ConfigurationName)\ErasthostheneDiallo" mkdir "..\build-$(ConfigurationName)\ErasthostheneDiallo"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/ErasthostheneDiallo/main.c$(ObjectSuffix): main.c 
	$(CC) $(SourceSwitch) "D:/Cours bloc MA1/Algorithmique structure/codes_ecrits/code_ecrit_par_moi/code_ecrit_par_moi/ErasthostheneDiallo/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ErasthostheneDiallo/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ErasthostheneDiallo/main.c$(PreprocessSuffix) main.c

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


