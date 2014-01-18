#ifndef FILESERVER_FILESERVER_H_INCLUDED
#define FILESERVER_FILESERVER_H_INCLUDED

#include <zeppelin/plugins/http-server/httpserver.h>

#include <zeppelin/plugin/plugin.h>

class FileServer : public zeppelin::plugin::Plugin
{
    public:
	std::string getName() const override
	{ return "file-server"; }

	void start(const Json::Value& config, zeppelin::plugin::PluginManager& pm) override;
	void stop() override;

    private:
	std::unique_ptr<httpserver::HttpResponse> processRequest(const httpserver::HttpRequest& request);

	void setContentType(httpserver::HttpResponse& response, const std::string& url);

    private:
	std::string m_documentRoot;

	static const std::string s_contentType;
	static std::map<std::string, std::string> s_contentTypeMap;
};

#endif
