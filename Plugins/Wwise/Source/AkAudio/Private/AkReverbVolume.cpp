#include "AkReverbVolume.h"
#include "AkLateReverbComponent.h"

AAkReverbVolume::AAkReverbVolume() {
    this->bEnabled = true;
    this->AuxBus = NULL;
    this->SendLevel = 1.00f;
    this->FadeRate = 0.50f;
    this->Priority = 1.00f;
    this->LateReverbComponent = CreateDefaultSubobject<UAkLateReverbComponent>(TEXT("LateReverb"));
}

