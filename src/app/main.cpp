/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2019-05-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <google/protobuf/util/json_util.h>  // for json
#include <iostream>
#include <string>
#include "../build/proto/cargo.pb.h"  // for test

int main(int argc, char** argv)
{
    std::cout << "hello vincent!" << std::endl;

    // set proto data
    PortoCargo proto_test;
    proto_test.set_id(1);
    proto_test.set_name("michael");
    proto_test.set_description("test");

    // convert to json
    google::protobuf::util::JsonPrintOptions op;
    op.add_whitespace = true;
    op.always_print_primitive_fields = true;
    std::string out;

    if (google::protobuf::util::MessageToJsonString(proto_test, &out, op) !=
        google::protobuf::util::Status::OK) {
        std::cout << "protobuf message convert to json failed!\n";
    } else {
        std::cout << "json from protouf message:\n";
        std::cout << out << "\n";
    }

    // parse from json
    std::string json{
        "{\n"
        "    \"id\":\"1\",\n"
        "    \"name\":\"michael\",\n"
        "    \"description\":\"test\",\n"
        "    \"prodeceArea\":\"30\",\n"
        "    \"price\":0.1,\n"
        "    \"unit\":\"90\",\n"
        "    \"relativePerson\":\"person\",\n"
        "    \"relativeGeoPosition\":\"positon\"\n"
        "}"};
    if (google::protobuf::util::JsonStringToMessage(json, &proto_test) !=
        google::protobuf::util::Status::OK) {
        std::cout << "protobuf parse from json failed\n";
    } else {
        std::cout << "protobuf from json:\n";
        proto_test.PrintDebugString();
    }
}