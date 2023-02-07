#include "AkAcousticPortal.h"
#include "AkPortalComponent.h"

void AAkAcousticPortal::OpenPortal() {
}

AkAcousticPortalState AAkAcousticPortal::GetCurrentState() const {
    return AkAcousticPortalState::Closed;
}

void AAkAcousticPortal::ClosePortal() {
}

AAkAcousticPortal::AAkAcousticPortal() {
    this->Portal = CreateDefaultSubobject<UAkPortalComponent>(TEXT("PortalComponent"));
    this->InitialState = AkAcousticPortalState::Open;
    this->bRequiresStateMigration = false;
}

