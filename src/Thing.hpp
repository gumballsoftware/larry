//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Thing.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

#include "Properties.hpp"
#include "Actions.hpp"
#include "SecurityDefinitions.hpp"

namespace webthings {
    class ThingLink;
}

namespace webthings {
    using nlohmann::json;

    class Thing {
        public:
        Thing() = default;
        virtual ~Thing() = default;

        private:
        std::string title;
        std::string context;
        std::vector<std::string> type;
        std::string description;
        std::string href;
        Properties properties;
        Actions actions;
        Actions events;
        std::vector<ThingLink> links;
        int64_t layout_index;
        std::string selected_capability;
        nlohmann::json icon_href;
        std::string id;
        std::string base;
        SecurityDefinitions security_definitions;
        std::string security;

        public:
        const std::string & get_title() const { return title; }
        std::string & get_mutable_title() { return title; }
        void set_title(const std::string & value) { this->title = value; }

        const std::string & get_context() const { return context; }
        std::string & get_mutable_context() { return context; }
        void set_context(const std::string & value) { this->context = value; }

        const std::vector<std::string> & get_type() const { return type; }
        std::vector<std::string> & get_mutable_type() { return type; }
        void set_type(const std::vector<std::string> & value) { this->type = value; }

        const std::string & get_description() const { return description; }
        std::string & get_mutable_description() { return description; }
        void set_description(const std::string & value) { this->description = value; }

        const std::string & get_href() const { return href; }
        std::string & get_mutable_href() { return href; }
        void set_href(const std::string & value) { this->href = value; }

        const Properties & get_properties() const { return properties; }
        Properties & get_mutable_properties() { return properties; }
        void set_properties(const Properties & value) { this->properties = value; }

        const Actions & get_actions() const { return actions; }
        Actions & get_mutable_actions() { return actions; }
        void set_actions(const Actions & value) { this->actions = value; }

        const Actions & get_events() const { return events; }
        Actions & get_mutable_events() { return events; }
        void set_events(const Actions & value) { this->events = value; }

        const std::vector<ThingLink> & get_links() const { return links; }
        std::vector<ThingLink> & get_mutable_links() { return links; }
        void set_links(const std::vector<ThingLink> & value) { this->links = value; }

        const int64_t & get_layout_index() const { return layout_index; }
        int64_t & get_mutable_layout_index() { return layout_index; }
        void set_layout_index(const int64_t & value) { this->layout_index = value; }

        const std::string & get_selected_capability() const { return selected_capability; }
        std::string & get_mutable_selected_capability() { return selected_capability; }
        void set_selected_capability(const std::string & value) { this->selected_capability = value; }

        const nlohmann::json & get_icon_href() const { return icon_href; }
        nlohmann::json & get_mutable_icon_href() { return icon_href; }
        void set_icon_href(const nlohmann::json & value) { this->icon_href = value; }

        const std::string & get_id() const { return id; }
        std::string & get_mutable_id() { return id; }
        void set_id(const std::string & value) { this->id = value; }

        const std::string & get_base() const { return base; }
        std::string & get_mutable_base() { return base; }
        void set_base(const std::string & value) { this->base = value; }

        const SecurityDefinitions & get_security_definitions() const { return security_definitions; }
        SecurityDefinitions & get_mutable_security_definitions() { return security_definitions; }
        void set_security_definitions(const SecurityDefinitions & value) { this->security_definitions = value; }

        const std::string & get_security() const { return security; }
        std::string & get_mutable_security() { return security; }
        void set_security(const std::string & value) { this->security = value; }
    };
}
