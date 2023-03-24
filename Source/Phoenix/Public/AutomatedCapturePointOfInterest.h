#pragma once
#include "CoreMinimal.h"
#include "Engine/NavigationObjectBase.h"
#include "AutomatedCapturePointOfInterest.generated.h"

UCLASS(Blueprintable)
class AAutomatedCapturePointOfInterest : public ANavigationObjectBase {
    GENERATED_BODY()
public:
    AAutomatedCapturePointOfInterest(const FObjectInitializer& ObjectInitializer);
};

