# Kafka as network layer in 4diac FORTE
This repository is for [ECSA 2022](https://conf.researchr.org/track/ecsa-2022/ecsa-2022-tools---demos) demonstration paper. Here we are implementing Apache Kafka as network layer at [4diac FORTE](https://www.eclipse.org/4diac/en_rte.php). Here we are using [lbrdkafka](https://github.com/edenhill/librdkafka) as Apache Kafka C++ client library. 

Demo Video [Link](https://www.youtube.com/watch?v=j3Gbk1BhMzE)

## In order to run this code
1. Install of 4diac IDE as per [documention](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#4DIAC-IDE)
1. Build Apache Kafka client C++ library [librdkafka](https://github.com/edenhill/librdkafka)
1. Install of 4diac FORTE as per [documention](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#4DIAC-FORTE) 
1. [build 4diac forte](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#ownFORTE) with Apache Kafka network layer as [external module](https://www.eclipse.org/4diac/en_help.php?helppage=html/installation/install.html#externalModules)
2. Create 4diac application based on the PLC-Service bus architecture.
3. Start executable forte and deploy 4diac application.
