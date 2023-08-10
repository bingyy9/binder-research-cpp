/* Refer frameworks/av/media/libmedia/IMediaPlayerService.cpp */

#include "IHelloService.h"

#define LOG_TAG "HelloService"

namespace android {

IMPLEMENT_META_INTERFACE(HelloService, "android.media.IHelloService");	

class BpHelloService: public BpInterface<IHelloService>
{
public:
    explicit BpHelloService(const sp<IBinder>& impl)
        : BpInterface<IHelloService>(impl)
    {
    	
    }
}

}