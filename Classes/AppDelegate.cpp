#include "AppDelegate.h"
#include "network/HttpClient.h"



USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // Example Code
    network::HttpRequest *request = new network::HttpRequest();
    request->setUrl("http://www.cocos2d-x.org/");
    request->setRequestType(network::HttpRequest::Type::GET);
    request->setResponseCallback([this](network::HttpClient *sender, network::HttpResponse *response) {
        CCLOG("ResponseCallback called.");
    });
    network::HttpClient::getInstance()->send(request);
    request->release();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
