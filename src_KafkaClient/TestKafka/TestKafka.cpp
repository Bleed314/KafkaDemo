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
    cppkafka::Configuration config = {
        {"metadata.broker.list", BROKER_LIST},
        {"group.id", "my_consumer_group"},
        {"auto.offset.reset", "latest"}  // 设置为"latest"来接收实时消息
    };

    cppkafka::Consumer consumer(config);
    consumer.subscribe({ TOPIC_NAME });

    while (true) {
        cppkafka::Message msg = consumer.poll();
        if (msg) {
            // 处理消息
            std::cout << "Received message: " << msg.get_payload() << std::endl;
        }
    }

    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
