//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Oauth2Sc.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"
#include "helper.hpp"

namespace webthings {
    using nlohmann::json;

    class Oauth2Sc {
        public:
        Oauth2Sc() = default;
        virtual ~Oauth2Sc() = default;

        private:
        std::string scheme;
        std::string flow;
        std::string authorization;
        std::string token;
        std::vector<std::string> scopes;

        public:
        const std::string & get_scheme() const { return scheme; }
        std::string & get_mutable_scheme() { return scheme; }
        void set_scheme(const std::string & value) { this->scheme = value; }

        const std::string & get_flow() const { return flow; }
        std::string & get_mutable_flow() { return flow; }
        void set_flow(const std::string & value) { this->flow = value; }

        const std::string & get_authorization() const { return authorization; }
        std::string & get_mutable_authorization() { return authorization; }
        void set_authorization(const std::string & value) { this->authorization = value; }

        const std::string & get_token() const { return token; }
        std::string & get_mutable_token() { return token; }
        void set_token(const std::string & value) { this->token = value; }

        const std::vector<std::string> & get_scopes() const { return scopes; }
        std::vector<std::string> & get_mutable_scopes() { return scopes; }
        void set_scopes(const std::vector<std::string> & value) { this->scopes = value; }
    };
}
