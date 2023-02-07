#include "NPC_SplineNavLink.h"
#include "SplineNavLinkComponent.h"

ANPC_SplineNavLink::ANPC_SplineNavLink() {
    this->NavLinkComponent = CreateDefaultSubobject<USplineNavLinkComponent>(TEXT("NavLink"));
}

