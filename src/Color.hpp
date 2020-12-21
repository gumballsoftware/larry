//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Color.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

namespace webthings {
    class ColorLink;
}

namespace webthings {
    using nlohmann::json;

    class Color {
        public:
        Color() = default;
        virtual ~Color() = default;

        private:
        std::string name;
        std::string value;
        bool visible;
        std::string title;
        std::string color_type;
        std::string type;
        std::vector<ColorLink> links;
        int64_t profile_id;
        int64_t endpoint;
        int64_t cluster_id;
        std::vector<std::string> attr;
        std::vector<int64_t> attr_id;
        bool fire_and_forget;
        bool bind_needed;
        bool config_report_needed;
        bool initial_read_needed;

        public:
        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }

        const std::string & get_value() const { return value; }
        std::string & get_mutable_value() { return value; }
        void set_value(const std::string & value) { this->value = value; }

        const bool & get_visible() const { return visible; }
        bool & get_mutable_visible() { return visible; }
        void set_visible(const bool & value) { this->visible = value; }

        const std::string & get_title() const { return title; }
        std::string & get_mutable_title() { return title; }
        void set_title(const std::string & value) { this->title = value; }

        const std::string & get_color_type() const { return color_type; }
        std::string & get_mutable_color_type() { return color_type; }
        void set_color_type(const std::string & value) { this->color_type = value; }

        const std::string & get_type() const { return type; }
        std::string & get_mutable_type() { return type; }
        void set_type(const std::string & value) { this->type = value; }

        const std::vector<ColorLink> & get_links() const { return links; }
        std::vector<ColorLink> & get_mutable_links() { return links; }
        void set_links(const std::vector<ColorLink> & value) { this->links = value; }

        const int64_t & get_profile_id() const { return profile_id; }
        int64_t & get_mutable_profile_id() { return profile_id; }
        void set_profile_id(const int64_t & value) { this->profile_id = value; }

        const int64_t & get_endpoint() const { return endpoint; }
        int64_t & get_mutable_endpoint() { return endpoint; }
        void set_endpoint(const int64_t & value) { this->endpoint = value; }

        const int64_t & get_cluster_id() const { return cluster_id; }
        int64_t & get_mutable_cluster_id() { return cluster_id; }
        void set_cluster_id(const int64_t & value) { this->cluster_id = value; }

        const std::vector<std::string> & get_attr() const { return attr; }
        std::vector<std::string> & get_mutable_attr() { return attr; }
        void set_attr(const std::vector<std::string> & value) { this->attr = value; }

        const std::vector<int64_t> & get_attr_id() const { return attr_id; }
        std::vector<int64_t> & get_mutable_attr_id() { return attr_id; }
        void set_attr_id(const std::vector<int64_t> & value) { this->attr_id = value; }

        const bool & get_fire_and_forget() const { return fire_and_forget; }
        bool & get_mutable_fire_and_forget() { return fire_and_forget; }
        void set_fire_and_forget(const bool & value) { this->fire_and_forget = value; }

        const bool & get_bind_needed() const { return bind_needed; }
        bool & get_mutable_bind_needed() { return bind_needed; }
        void set_bind_needed(const bool & value) { this->bind_needed = value; }

        const bool & get_config_report_needed() const { return config_report_needed; }
        bool & get_mutable_config_report_needed() { return config_report_needed; }
        void set_config_report_needed(const bool & value) { this->config_report_needed = value; }

        const bool & get_initial_read_needed() const { return initial_read_needed; }
        bool & get_mutable_initial_read_needed() { return initial_read_needed; }
        void set_initial_read_needed(const bool & value) { this->initial_read_needed = value; }
    };
}
