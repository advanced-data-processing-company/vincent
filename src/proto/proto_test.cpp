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
#include "src/proto/cargo.pb.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

/**
 * @brief test for protobuf converto json
 */
TEST_CASE("json") {
    SUBCASE("to_json") {
        // set proto data
        PortoCargo proto_test;
        proto_test.set_id(1u);
        proto_test.set_name("michael");
        proto_test.set_description("test");

        // convert to json
        google::protobuf::util::JsonPrintOptions op;
        op.add_whitespace                = true;
        op.always_print_primitive_fields = true;
        std::string out;

        if (google::protobuf::util::MessageToJsonString(proto_test, &out, op) !=
            google::protobuf::util::Status::OK) {
            CHECK(false);
        } else {
            CHECK(out.length() > 0u);
        }
    }

    SUBCASE("from_json") {
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
            CHECK_EQ(proto_test.id(), 1u);
            CHECK_EQ(proto_test.name(), std::string("michael"));
            CHECK_EQ(proto_test.price(), 0.1);
        }
    }
}
