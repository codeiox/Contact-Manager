#include <drogon/drogon.h>

#include <iostream>

int main(int argc, const char *argv[]) {
    drogon::app()
        .registerHandler("/hello",
                         [](const drogon::HttpRequestPtr &req,
                            std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
                             auto resp = drogon::HttpResponse::newHttpResponse();
                             resp->setBody("Hello, Drogon is running!");
                             callback(resp);
                             std::cout << "Server started at http://localhost:18080/hello"
                                       << std::endl;
                         },
                         {drogon::Get})
        .addListener("0.0.0.0", 18080)
        .run();
}