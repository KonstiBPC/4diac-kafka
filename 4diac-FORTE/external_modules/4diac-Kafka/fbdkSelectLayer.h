#include <fbdkasn1layer.h>
#include "comlayer.h"
#include "basecommfb.h"
#include <vector>

#ifndef FBDKSELECTLAYER_H_
#define FBDKSELECTLAYER_H_

using namespace forte::com_infra;

class fbdkSelectLayer : public CFBDKASN1ComLayer {
    public:
        fbdkSelectLayer(CComLayer* pa_poUpperLayer, CBaseCommFB * pa_poFB);
        virtual ~fbdkSelectLayer();
    private:
        std::vector<int> selected;
        EComResponse openConnection(char* paLayerParameter);
        EComResponse recvData(const void *paData, unsigned int paSize);
};

#endif