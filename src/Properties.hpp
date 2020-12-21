//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Properties.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

#include "Color.hpp"
#include "On.hpp"

namespace webthings {
    using nlohmann::json;

    class Properties {
        public:
        Properties() = default;
        virtual ~Properties() = default;

        private:
        Color color;
        On on;

        public:
        const Color & get_color() const { return color; }
        Color & get_mutable_color() { return color; }
        void set_color(const Color & value) { this->color = value; }

        const On & get_on() const { return on; }
        On & get_mutable_on() { return on; }
        void set_on(const On & value) { this->on = value; }
    };
}
