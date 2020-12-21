//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Actions.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

namespace webthings {
    using nlohmann::json;

    class Actions {
        public:
        Actions() = default;
        virtual ~Actions() = default;

        private:

        public:
    };
}
