//refer frameworks/av/media/mediaserver/main_mediaserver.cpp

#define LOG_TAG "HelloService"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include "IHelloService.h"

using namespace android;

int main()
{
	//open binder, mmap
    sp<ProcessState> proc(ProcessState::self());
    //获得BpServiceManager
    sp<IServiceManager> sm(defaultServiceManager());
    ALOGI("ServiceManager: %p", sm.get());

	//add service
    sm->addService(String16("hello"), new BnHelloService);

    //循环体 loop { read data, parse data, invoke function }
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}