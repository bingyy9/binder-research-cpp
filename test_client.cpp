//refer frameworks/av/media/mediaserver/main_mediaserver.cpp

#define LOG_TAG "HelloService"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include "IHelloService.h"

using namespace android;

int main(int argc, char** argv)
{
	//open binder, mmap
    sp<ProcessState> proc(ProcessState::self());
    //获得BpServiceManager
    sp<IServiceManager> sm(defaultServiceManager());
    ALOGI("ServiceManager: %p", sm.get());

    //get service
    sp<IBinder> binder = sm->getService(String16("hello"));
    if(binder == 0){
        return -1;
    }
    
    sp<IHelloService> service = interface_case<IHelloService>(binder);
    service->sayHello();
    service->sayHelloTo("xxx");
}