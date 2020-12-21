//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ThingLink.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

namespace webthings {
    using nlohmann::json;

    class ThingLink {
        public:
        ThingLink() = default;
        virtual ~ThingLink() = default;

        private:
        std::string rel;
        std::string href;
        std::shared_ptr<std::string> media_type;

        public:
        const std::string & get_rel() const { return rel; }
        std::string & get_mutable_rel() { return rel; }
        void set_rel(const std::string & value) { this->rel = value; }

        const std::string & get_href() const { return href; }
        std::string & get_mutable_href() { return href; }
        void set_href(const std::string & value) { this->href = value; }

        std::shared_ptr<std::string> get_media_type() const { return media_type; }
        void set_media_type(std::shared_ptr<std::string> value) { this->media_type = value; }
    };
}
