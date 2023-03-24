#include "NPC_SplineNavLink.h"
#include "SplineNavLinkComponent.h"

ANPC_SplineNavLink::ANPC_SplineNavLink(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NavLinkComponent = CreateDefaultSubobject<USplineNavLinkComponent>(TEXT("NavLink"));
}

