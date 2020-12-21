//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     SecurityDefinitions.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

#include "Oauth2Sc.hpp"

namespace webthings {
    using nlohmann::json;

    class SecurityDefinitions {
        public:
        SecurityDefinitions() = default;
        virtual ~SecurityDefinitions() = default;

        private:
        Oauth2Sc oauth2_sc;

        public:
        const Oauth2Sc & get_oauth2_sc() const { return oauth2_sc; }
        Oauth2Sc & get_mutable_oauth2_sc() { return oauth2_sc; }
        void set_oauth2_sc(const Oauth2Sc & value) { this->oauth2_sc = value; }
    };
}
