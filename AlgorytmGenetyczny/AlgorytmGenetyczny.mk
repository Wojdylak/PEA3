##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=AlgorytmGenetyczny
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekt3
ProjectPath            :=C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekt3/AlgorytmGenetyczny
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Admin
Date                   :=08/01/2019
CodeLitePath           :=D:/Programy/CodeLite
LinkerName             :=D:/Programy/TDM-GCC/bin/g++.exe
SharedObjectLinkerName :=D:/Programy/TDM-GCC/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="AlgorytmGenetyczny.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/Programy/TDM-GCC/bin/windres.exe
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
AR       := D:/Programy/TDM-GCC/bin/ar.exe rcu
CXX      := D:/Programy/TDM-GCC/bin/g++.exe
CC       := D:/Programy/TDM-GCC/bin/gcc.exe
CXXFLAGS :=  -O2 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -std=c++14 -std=c++11 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/Programy/TDM-GCC/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Programy\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MatrixCost.cpp$(ObjectSuffix) $(IntermediateDirectory)/AlgorithmGenetic.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekt3/AlgorytmGenetyczny/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/MatrixCost.cpp$(ObjectSuffix): MatrixCost.cpp $(IntermediateDirectory)/MatrixCost.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekt3/AlgorytmGenetyczny/MatrixCost.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MatrixCost.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MatrixCost.cpp$(DependSuffix): MatrixCost.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MatrixCost.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MatrixCost.cpp$(DependSuffix) -MM MatrixCost.cpp

$(IntermediateDirectory)/MatrixCost.cpp$(PreprocessSuffix): MatrixCost.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MatrixCost.cpp$(PreprocessSuffix) MatrixCost.cpp

$(IntermediateDirectory)/AlgorithmGenetic.cpp$(ObjectSuffix): AlgorithmGenetic.cpp $(IntermediateDirectory)/AlgorithmGenetic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekt3/AlgorytmGenetyczny/AlgorithmGenetic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AlgorithmGenetic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AlgorithmGenetic.cpp$(DependSuffix): AlgorithmGenetic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AlgorithmGenetic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AlgorithmGenetic.cpp$(DependSuffix) -MM AlgorithmGenetic.cpp

$(IntermediateDirectory)/AlgorithmGenetic.cpp$(PreprocessSuffix): AlgorithmGenetic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AlgorithmGenetic.cpp$(PreprocessSuffix) AlgorithmGenetic.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


