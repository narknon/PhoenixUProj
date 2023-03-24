#include "ControlTest.h"

class UUserWidget;

void AControlTest::SetLogWidget(UUserWidget* i_logWidget) {
}

void AControlTest::SetCommandVelocity(const FVector& i_velocity) {
}

AControlTest::AControlTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_maxDisplacement = 5000.00f;
}

