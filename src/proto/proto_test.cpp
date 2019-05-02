/**
 * @file proto_test.cpp
 * @author tonghaoy
 * @brief test for libprpto
 * @version 0.1
 * @date 2019-05-02
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <google/protobuf/util/json_util.h>  // for json process
#include "3rdparty/gtest/gtest.h"
#include "build/proto/cargo.pb.h"
#include "proto/cargo.pb.h"

/**
 * @brief test for protobuf converto json
 */
TEST(json, to_json)
{
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
        GTEST_FAIL();
    } else {
        GTEST_ASSERT_GT(out.length(), 0);
    }
}

/**
 * @brief test for protobuf parse from json
 */
TEST(json, from_json)
{
    PortoCargo proto_test;

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
    } else {
        GTEST_ASSERT_EQ(proto_test.id(), 1);
        GTEST_ASSERT_EQ(proto_test.name(), std::string("michael"));
        GTEST_ASSERT_EQ(proto_test.price(), 0.1);
    }
}
