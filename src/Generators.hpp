//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Generators.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

#include "Thing.hpp"
#include "SecurityDefinitions.hpp"
#include "Oauth2Sc.hpp"
#include "Properties.hpp"
#include "On.hpp"
#include "Color.hpp"
#include "ColorLink.hpp"
#include "ThingLink.hpp"
#include "Actions.hpp"

namespace nlohmann {
    void from_json(const json & j, webthings::Actions & x);
    void to_json(json & j, const webthings::Actions & x);

    void from_json(const json & j, webthings::ThingLink & x);
    void to_json(json & j, const webthings::ThingLink & x);

    void from_json(const json & j, webthings::ColorLink & x);
    void to_json(json & j, const webthings::ColorLink & x);

    void from_json(const json & j, webthings::Color & x);
    void to_json(json & j, const webthings::Color & x);

    void from_json(const json & j, webthings::On & x);
    void to_json(json & j, const webthings::On & x);

    void from_json(const json & j, webthings::Properties & x);
    void to_json(json & j, const webthings::Properties & x);

    void from_json(const json & j, webthings::Oauth2Sc & x);
    void to_json(json & j, const webthings::Oauth2Sc & x);

    void from_json(const json & j, webthings::SecurityDefinitions & x);
    void to_json(json & j, const webthings::SecurityDefinitions & x);

    void from_json(const json & j, webthings::Thing & x);
    void to_json(json & j, const webthings::Thing & x);

    inline void from_json(const json & j, webthings::Actions& x) {
    }

    inline void to_json(json & j, const webthings::Actions & x) {
        j = json::object();
    }

    inline void from_json(const json & j, webthings::ThingLink& x) {
        x.set_rel(j.at("rel").get<std::string>());
        x.set_href(j.at("href").get<std::string>());
        x.set_media_type(webthings::get_optional<std::string>(j, "mediaType"));
    }

    inline void to_json(json & j, const webthings::ThingLink & x) {
        j = json::object();
        j["rel"] = x.get_rel();
        j["href"] = x.get_href();
        j["mediaType"] = x.get_media_type();
    }

    inline void from_json(const json & j, webthings::ColorLink& x) {
        x.set_rel(j.at("rel").get<std::string>());
        x.set_href(j.at("href").get<std::string>());
    }

    inline void to_json(json & j, const webthings::ColorLink & x) {
        j = json::object();
        j["rel"] = x.get_rel();
        j["href"] = x.get_href();
    }

    inline void from_json(const json & j, webthings::Color& x) {
        x.set_name(j.at("name").get<std::string>());
        x.set_value(j.at("value").get<std::string>());
        x.set_visible(j.at("visible").get<bool>());
        x.set_title(j.at("title").get<std::string>());
        x.set_color_type(j.at("type").get<std::string>());
        x.set_type(j.at("@type").get<std::string>());
        x.set_links(j.at("links").get<std::vector<webthings::ColorLink>>());
        x.set_profile_id(j.at("profileId").get<int64_t>());
        x.set_endpoint(j.at("endpoint").get<int64_t>());
        x.set_cluster_id(j.at("clusterId").get<int64_t>());
        x.set_attr(j.at("attr").get<std::vector<std::string>>());
        x.set_attr_id(j.at("attrId").get<std::vector<int64_t>>());
        x.set_fire_and_forget(j.at("fireAndForget").get<bool>());
        x.set_bind_needed(j.at("bindNeeded").get<bool>());
        x.set_config_report_needed(j.at("configReportNeeded").get<bool>());
        x.set_initial_read_needed(j.at("initialReadNeeded").get<bool>());
    }

    inline void to_json(json & j, const webthings::Color & x) {
        j = json::object();
        j["name"] = x.get_name();
        j["value"] = x.get_value();
        j["visible"] = x.get_visible();
        j["title"] = x.get_title();
        j["type"] = x.get_color_type();
        j["@type"] = x.get_type();
        j["links"] = x.get_links();
        j["profileId"] = x.get_profile_id();
        j["endpoint"] = x.get_endpoint();
        j["clusterId"] = x.get_cluster_id();
        j["attr"] = x.get_attr();
        j["attrId"] = x.get_attr_id();
        j["fireAndForget"] = x.get_fire_and_forget();
        j["bindNeeded"] = x.get_bind_needed();
        j["configReportNeeded"] = x.get_config_report_needed();
        j["initialReadNeeded"] = x.get_initial_read_needed();
    }

    inline void from_json(const json & j, webthings::On& x) {
        x.set_name(j.at("name").get<std::string>());
        x.set_value(j.at("value").get<bool>());
        x.set_visible(j.at("visible").get<bool>());
        x.set_title(j.at("title").get<std::string>());
        x.set_on_type(j.at("type").get<std::string>());
        x.set_type(j.at("@type").get<std::string>());
        x.set_links(j.at("links").get<std::vector<webthings::ColorLink>>());
        x.set_profile_id(j.at("profileId").get<int64_t>());
        x.set_endpoint(j.at("endpoint").get<int64_t>());
        x.set_cluster_id(j.at("clusterId").get<int64_t>());
        x.set_attr(j.at("attr").get<std::string>());
        x.set_attr_id(j.at("attrId").get<int64_t>());
        x.set_fire_and_forget(j.at("fireAndForget").get<bool>());
        x.set_bind_needed(j.at("bindNeeded").get<bool>());
        x.set_config_report_needed(j.at("configReportNeeded").get<bool>());
        x.set_initial_read_needed(j.at("initialReadNeeded").get<bool>());
    }

    inline void to_json(json & j, const webthings::On & x) {
        j = json::object();
        j["name"] = x.get_name();
        j["value"] = x.get_value();
        j["visible"] = x.get_visible();
        j["title"] = x.get_title();
        j["type"] = x.get_on_type();
        j["@type"] = x.get_type();
        j["links"] = x.get_links();
        j["profileId"] = x.get_profile_id();
        j["endpoint"] = x.get_endpoint();
        j["clusterId"] = x.get_cluster_id();
        j["attr"] = x.get_attr();
        j["attrId"] = x.get_attr_id();
        j["fireAndForget"] = x.get_fire_and_forget();
        j["bindNeeded"] = x.get_bind_needed();
        j["configReportNeeded"] = x.get_config_report_needed();
        j["initialReadNeeded"] = x.get_initial_read_needed();
    }

    inline void from_json(const json & j, webthings::Properties& x) {
        x.set_color(j.at("color").get<webthings::Color>());
        x.set_on(j.at("on").get<webthings::On>());
    }

    inline void to_json(json & j, const webthings::Properties & x) {
        j = json::object();
        j["color"] = x.get_color();
        j["on"] = x.get_on();
    }

    inline void from_json(const json & j, webthings::Oauth2Sc& x) {
        x.set_scheme(j.at("scheme").get<std::string>());
        x.set_flow(j.at("flow").get<std::string>());
        x.set_authorization(j.at("authorization").get<std::string>());
        x.set_token(j.at("token").get<std::string>());
        x.set_scopes(j.at("scopes").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const webthings::Oauth2Sc & x) {
        j = json::object();
        j["scheme"] = x.get_scheme();
        j["flow"] = x.get_flow();
        j["authorization"] = x.get_authorization();
        j["token"] = x.get_token();
        j["scopes"] = x.get_scopes();
    }

    inline void from_json(const json & j, webthings::SecurityDefinitions& x) {
        x.set_oauth2_sc(j.at("oauth2_sc").get<webthings::Oauth2Sc>());
    }

    inline void to_json(json & j, const webthings::SecurityDefinitions & x) {
        j = json::object();
        j["oauth2_sc"] = x.get_oauth2_sc();
    }

    inline void from_json(const json & j, webthings::Thing& x) {
        x.set_title(j.at("title").get<std::string>());
        x.set_context(j.at("@context").get<std::string>());
        x.set_type(j.at("@type").get<std::vector<std::string>>());
        x.set_description(j.at("description").get<std::string>());
        x.set_href(j.at("href").get<std::string>());
        x.set_properties(j.at("properties").get<webthings::Properties>());
        x.set_actions(j.at("actions").get<webthings::Actions>());
        x.set_events(j.at("events").get<webthings::Actions>());
        x.set_links(j.at("links").get<std::vector<webthings::ThingLink>>());
        x.set_layout_index(j.at("layoutIndex").get<int64_t>());
        x.set_selected_capability(j.at("selectedCapability").get<std::string>());
        x.set_icon_href(webthings::get_untyped(j, "iconHref"));
        x.set_id(j.at("id").get<std::string>());
        x.set_base(j.at("base").get<std::string>());
        x.set_security_definitions(j.at("securityDefinitions").get<webthings::SecurityDefinitions>());
        x.set_security(j.at("security").get<std::string>());
    }

    inline void to_json(json & j, const webthings::Thing & x) {
        j = json::object();
        j["title"] = x.get_title();
        j["@context"] = x.get_context();
        j["@type"] = x.get_type();
        j["description"] = x.get_description();
        j["href"] = x.get_href();
        j["properties"] = x.get_properties();
        j["actions"] = x.get_actions();
        j["events"] = x.get_events();
        j["links"] = x.get_links();
        j["layoutIndex"] = x.get_layout_index();
        j["selectedCapability"] = x.get_selected_capability();
        j["iconHref"] = x.get_icon_href();
        j["id"] = x.get_id();
        j["base"] = x.get_base();
        j["securityDefinitions"] = x.get_security_definitions();
        j["security"] = x.get_security();
    }
}
