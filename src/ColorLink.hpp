//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ColorLink.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

namespace webthings {
    using nlohmann::json;

    class ColorLink {
        public:
        ColorLink() = default;
        virtual ~ColorLink() = default;

        private:
        std::string rel;
        std::string href;

        public:
        const std::string & get_rel() const { return rel; }
        std::string & get_mutable_rel() { return rel; }
        void set_rel(const std::string & value) { this->rel = value; }

        const std::string & get_href() const { return href; }
        std::string & get_mutable_href() { return href; }
        void set_href(const std::string & value) { this->href = value; }
    };
}
