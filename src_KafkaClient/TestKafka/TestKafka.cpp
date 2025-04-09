// TestKafka.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>

#include <cppkafka/producer.h>
#include <cppkafka/consumer.h>
#include <cppkafka/configuration.h>

using namespace cppkafka;
using namespace std;

// 配置参数
const string BROKER_LIST = "192.168.131.128:9092";  // Kafka broker 地址
const string TOPIC_NAME = "test1"; // 测试主题

int main() {
	// 消费者配置示例
    //cppkafka::Configuration config = {
    //    {"metadata.broker.list", BROKER_LIST},
    //    {"group.id", "my_consumer_group"},
    //    {"auto.offset.reset", "latest"}  // 设置为"latest"来接收实时消息
    //};

    //cppkafka::Consumer consumer(config);
    //consumer.subscribe({ TOPIC_NAME });

    //while (true) {
    //    cppkafka::Message msg = consumer.poll();
    //    if (msg) {
    //        // 处理消息
    //        std::cout << "Received message: " << msg.get_payload() << std::endl;
    //    }
    //}

	// 生产者配置示例
        // Construct the configuration
    Configuration config = {
        { "metadata.broker.list", BROKER_LIST }
    };

    // Create the producer
    MessageBuilder builder(TOPIC_NAME);
    Producer producer(config);
    builder.partition(-1);
    // Now read lines and write them into kafka
    string line;
    while (getline(cin, line)) {
        if (cin.fail()) {
            cerr << "从输入流读取时出错" << endl;
            break;
        }
        // Set the payload on this builder
        builder.payload(line);

        // Actually produce the message we've built
        producer.produce(builder);
    }
    producer.flush();

    // Flush all produced messages
  

    return 0;
}

