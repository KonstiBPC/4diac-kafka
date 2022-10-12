# Kafka as network layer in 4diac FORTE
This repository is for [ECSA 2022](https://conf.researchr.org/track/ecsa-2022/ecsa-2022-tools---demos) demonstration paper. Here we are implementing Apache Kafka as network layer at [4diac FORTE](https://www.eclipse.org/4diac/en_rte.php). Here we are using [lbrdkafka](https://github.com/edenhill/librdkafka) as Apache Kafka C++ client library. 

Demo Video [Link](https://www.youtube.com/watch?v=j3Gbk1BhMzE)

<!-- 
## In order to run this code
1. Install of 4diac IDE as per [documention](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#4DIAC-IDE)
1. Build Apache Kafka client C++ library [librdkafka](https://github.com/edenhill/librdkafka)
1. Install of 4diac FORTE as per [documention](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#4DIAC-FORTE) 
1. [build 4diac forte](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#ownFORTE) with Apache Kafka network layer as [external module](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#externalModules)
2. Create 4diac application based on the PLC-Service bus architecture.
3. Start executable forte and deploy 4diac application.
-->

Prerequisites:
- CMake
- Visual Studio Build Tools (Tested with 2022)
- git (for convinience)

### A) Configuring librdKafka with CMake
1. Download librdkafka from github https://github.com/edenhill/librdkafka.git
2. Create a directory you want to build in
3. start CMake and select the downloaded source for "where is the source code"
4. Select your build target folder for "where to build the bineries
5. Click configure
6. select your version of Visual Studio for the generator, leave everything else as is and click finish
If a error occures that hints that you don't have a compiler or windows sdk you should check your installation of the visual studio build tools
7. After configuring is done options should be displayed. Leve them as they are and hit Generate
	
### B) Build librdkafka
1. open the visual studio installer and start the visual studio build tools
2. In the now open command line navigate to the folder the you specified in A.2
3. type msbuild RdKafka.sln and hit enter
4. after the building finished you should find two dll files rdkafka.dll and rdkafka++.dll in the src/debug and src-cpp/debug folder of your build directory.
	
### C) Configuring Forte wih CMake
1. Download the 4diac-Forte sourcecode from https://git.eclipse.org/r/4diac/org.eclipse.4diac.forte.git
2. Download the kafkacomlayer source from https://sourcery.im.jku.at/cps-labs/cps4ep/student/4diac-kafka.git
3. choose one of the options
	3a. place it INSIDE a folder and create a CMake file that has this command inside forte_add_subdirectory(4diac-kafka)
	3b. place it inside your external modules folder that has a cmake file to include all subfolders
4. In CMake select the forte source as in A.3 and specify a different build folder as in A.4
Repeat A.5 and A.6
5. Change the following setting
	i) 	Select FORTE_ARCHITECTURE
	ii) 	CHECK FORTE_MODULE_IEC61131
	iii) 	Specify the Directory you chose at step 3 for FORTE_EXTERNAL_MODULES_DIRECTORY
6. Click configure. Now three new kafka related options should appear in red. Configure them as follows
-	FORTE_COM_KAFKA -> Check the box
- FORTE_COM_KAFKA_BUILD_DIR -> specify the path to the folder you selected in A.4
- FORTE_COM_KAFKA_INC_DIR -> specify the path to the folder from A.1
7. Click configure again. Now no option should be red
8. Click generate

### D) Build your FORTE
1. Reopen the visual studio build tools or reuse the one you left open after B)
2. Navigate to the folder specified in C.4 (Build folder of forte (+kafka))
3. type msbuild FORTE.sln and hit enter
4. After the build finished you should have a exe file in (your build folder)\src\Debug
5. Copy the dll files of B.4 next to the exe in order to run it
	
### Differences for Posix buils:
- Instead of msbuild use make and the gcc compiler -> navigate to you build folder and execute the make command
- When configuring cmake use "unix makefiles" instead of Visual Studio
- You might specify the build type
- Instead of the dll files you will get .so from building the kafka library
- Copying them may not be necessesary, because linux searches for .so
- The forte executeable will just be in the src folder instead of src/Debug
	
### Usage:
- follow the guide here https://kafka.apache.org/quickstart to set up your broker and create a topic
- In 4diac-ide create publisher and subscriber blocks and specify the id
- ID: "kafka[brokerip:port,topic, config file]"
- The config file is optional. You can change all parameters provided by librdkafka as listed here https://github.com/edenhill/librdkafka/blob/master/CONFIGURATION.md
- If you don't specify a configfile omit the last comma
